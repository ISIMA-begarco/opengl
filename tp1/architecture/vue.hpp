/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: vue.hpp                                                            * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef HEADER_VUE_HPP
#define HEADER_VUE_HPP

#include <unistd.h>

/**
 * CLASSE DE GESTION DE L'AFFICHAGE
 */
struct DisplayManager{
  
  GLint mLargeurFenetre; // Largeur de la vue
  GLint mHauteurFenetre; // Hauteur de la vue
  
  // Modèle de données à afficher
  Modele mModele;
  Camera mCamera;
  
   /** @brief  Constructeur prenant la géométrie de la fenêtre
   * Initialise les données nécessaires à l'affichage.*/
  DisplayManager(GLint largeurFenetre,GLint hauteurFenetre)
    :mLargeurFenetre(largeurFenetre),
    mHauteurFenetre(hauteurFenetre),
    mModele(), // Construction du modèle
    mCamera(3, 20, -50,
    			0,0,0,
    			0,1,0,
    			1,1000, 50)
  {
    FramesData::Init();
    mCamera.Redimensionnement(largeurFenetre, hauteurFenetre);
   //this->mModele.addScene("../testAssimp/dwarf.x");
   //this->mModele.addTeapot(5);
   //this->mModele.addSystemeSolaire(10);
   this->mModele.addVoiture(1.0);
  }
  
  /** Méthode d'affichage */
  void Affichage(){
	//static int scene_list = 0
	
    // Affichage des Frames par seconde (FPS)
    if (FramesData::Update()){
      fprintf(stderr, "%s\n", FramesData::getDescriptionFPS());
    }
    
	// On efface le buffer vidéo (fenêtre graphique)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    mCamera.LookAt();
   /* if(scene_list == 0) {
	    scene_list = glGenLists(1);
	    glNewList(scene_list, GL_COMPILE);
	    
	    
	    glEndList();
	}

	glCallList(scene_list);*/
	
	mModele.renderAll();

  }

  /** Réglage du cadrage pour la vue
   * Doit être rappelée si la taille de la vue change (SDL_WINDOWEVENT)
   * @param l largeur de la (nouvelle) vue
   * @param h hauteur de la (nouvelle) vue
   */
  void Redimensionnement(GLint l,GLint h){
    mLargeurFenetre = l;
    mHauteurFenetre = h;
    // Surface de rendu (voir chapitres suivants)
    glViewport((GLint)mCamera.mPosition[0],(GLint)mCamera.mPosition[1],(GLsizei)l,(GLsizei)h);
    mCamera.Redimensionnement(l, h);
    
  }
};
#endif
