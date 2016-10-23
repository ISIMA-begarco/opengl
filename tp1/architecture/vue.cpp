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
    mCamera(3, 20, -50,
    			0,0,0,
    			0,1,0,
    			1,1000, 50),
    mLight()
  {
    FramesData::Init();
    mCamera.Redimensionnement(largeurFenetre, hauteurFenetre);
    mLight.AddSource(AbstractCamera::TypeRepere::CAMERA,1,
          40, 20, -40,
          50,50,50,
          50,50,50);

   this->mModele.addScene("../testAssimp/dwarf.x");
   //this->mModele.addTeapot(5);
   //this->mModele.addSystemeSolaire(10);
   //this->mModele.addVoiture(1.0);
  }

void DisplayManager::Affichage(){

    // Affichage des Frames par seconde (FPS)
    if (FramesData::Update()){
      fprintf(stderr, "%s\n", FramesData::getDescriptionFPS());
    }

	// On efface le buffer vidéo (fenêtre graphique)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    mCamera.ChangerRepereCamera();
    mModele.renderAll();

    mLight.ApplyLightPositions(AbstractCamera::TypeRepere::CAMERA);
    mLight.ApplyLightIntensities();

}

void DisplayManager::Redimensionnement(GLint l,GLint h){
    mLargeurFenetre = l;
    mHauteurFenetre = h;
    // Surface de rendu (voir chapitres suivants)
    glViewport((GLint)mCamera.getPosition()[0],(GLint)mCamera.getPosition()[1],(GLsizei)l,(GLsizei)h);
    mCamera.Redimensionnement(l, h);

}
