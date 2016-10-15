/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: modele.hpp                                                         * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef HEADER_MODELE_HPP
#define HEADER_MODELE_HPP

#include <string>
#include <vector>

#include "scene.hpp"

/**
 * Modèle de données
 */
struct Modele{
  // Niveau de gris du fond
  float mNiveauGris;
  std::vector<Scene> mSceneList;
  
  /** @brief constructeur par défaut
   * Initialise les données nécessaires à l'affichage. */
  Modele()
    :mNiveauGris(0.0f),
    mSceneList()
  {}
  
  /** Mise à jour du modèle appelée à chaque événement timer */
  void Update(){
    mNiveauGris += 0.01f;
    if (mNiveauGris > 1.0f){
      mNiveauGris = 0.0f;
    }
  }
  
  void addScene(std::string path){
  	this->mSceneList.push_back(Scene(path));
  	    std::cout << "coucou" << std::endl;
  }
  
  void render(int i){
  	if(i<(int)this->mSceneList.size()){
  		this->mSceneList[i].render(this->mSceneList[i].getRacine());
  	}
  }
  
  void renderAll(){
  	for (unsigned i = 0; i < this->mSceneList.size(); i++){
  		this->render(i);
  	}
  }
};
#endif
