/**
 * @file vue.cpp
 * @brief Classe de gestion de l'affichage
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#include "vue.hpp"
#include <cstdio>

DisplayManager::DisplayManager(GLint largeurFenetre,GLint hauteurFenetre)
    :mLargeurFenetre(largeurFenetre),
    mHauteurFenetre(hauteurFenetre),
    mModele(), // Construction du modèle
    mCamera(-7, -30, -110,
    			0,0,0,
    			0,1,0,
    			1,5000, 50,
                0.0, 0.0),
    mLight()
{
    FramesData::Init();
    RenderingModel::Init();

    mCamera.Redimensionnement(largeurFenetre, hauteurFenetre);
    mLight.AddSource(AbstractCamera::TypeRepere::CAMERA,GL_LIGHT0,
          40, 20, -40,
          mLight.mIntensity, mLight.mIntensity, mLight.mIntensity,
          mLight.mIntensity, mLight.mIntensity, mLight.mIntensity);
    mLight.ApplyLightPositions(AbstractCamera::TypeRepere::CAMERA);
    mLight.ApplyLightIntensities();

    glDisable(GL_COLOR_MATERIAL);

    RenderingModel::ApplyMaterial (mModele.mMaterialAllScenes);

    this->mModele.addScene("../testAssimp/dwarf.x");
    //this->mModele.addTeapot(5);
    this->mModele.addSystemeSolaire(10);
    //this->mModele.addVoiture(1.0);
}

void DisplayManager::Affichage(){

    // Affichage des Frames par seconde (FPS)
    if (FramesData::Update()){
      fprintf(stderr, "%s\n", FramesData::getDescriptionFPS());
    }

	// On efface le buffer vidéo (fenêtre graphique)
    glClearColor(0, 0, 0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    RenderingModel::InitView();
    GeometricTransform::ClearModelView();
    mLight.ApplyLightPositions(AbstractCamera::TypeRepere::MONDE);
    mCamera.ChangerRepereCamera();
    //GeometricTransform::ClearProjection();
    mModele.renderAll();
}

void DisplayManager::Redimensionnement(GLint l,GLint h){
    mLargeurFenetre = l;
    mHauteurFenetre = h;
    // Surface de rendu (voir chapitres suivants)
    glViewport((GLint)mCamera.GetPosition()[0],(GLint)mCamera.GetPosition()[1],(GLsizei)l,(GLsizei)h);
    mCamera.Redimensionnement(l, h);

}
