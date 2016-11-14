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
    :
    mRevolutionLight(0.0),
    mMovingLightX(40.0),
    mMovingLightY(20.0),
    mMovingLightZ(-40.0),
    mMovingLightIntensity(0.6),
    mLargeurFenetre(largeurFenetre),
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

    // Light fixe
    mLight.AddSource(AbstractCamera::TypeRepere::CAMERA,GL_LIGHT0,
          40, 20, -40,
          mLight.mIntensity, mLight.mIntensity, mLight.mIntensity,
          mLight.mIntensity, mLight.mIntensity, mLight.mIntensity);

    mLight.ApplyLightPositions(AbstractCamera::TypeRepere::CAMERA);

    // Light qui tourne
    mLight.AddSource(AbstractCamera::TypeRepere::MONDE,GL_LIGHT1,
          mMovingLightX, mMovingLightY, mMovingLightZ,
          mMovingLightIntensity, mMovingLightIntensity, mMovingLightIntensity,
          mMovingLightIntensity, mMovingLightIntensity, mMovingLightIntensity);
    mLight.ApplyLightPositions(AbstractCamera::TypeRepere::MONDE);

    mLight.ApplyLightIntensities();

    glDisable(GL_COLOR_MATERIAL);

    RenderingModel::ApplyMaterial (mModele.mMaterialAllScenes);

 //   this->mModele.addScene("../testAssimp/dwarf.x");
//    this->mModele.addSystemeSolaire(10);
    this->mModele.addCylindre(3,10,600);
//	   this->mModele.addTeapot(7);
//    this->mModele.addVoiture(1.0);
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
    mCamera.ChangerRepereCamera();
    mLight.ApplyLightPositions(AbstractCamera::TypeRepere::MONDE);

    glPushMatrix();
      // Planete
      // Rotation superieur
      GeometricTransform::Rotate(0, 1, 0, mRevolutionLight);

      mLight.SetPosition(GL_LIGHT1, mMovingLightX, mMovingLightY, mMovingLightZ);

      // Update
      mRevolutionLight=fmod((mRevolutionLight+0.4),360.0);
    glPopMatrix();

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
