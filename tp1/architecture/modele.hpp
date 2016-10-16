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
#include "abstractScene.hpp"
#include "computedScene.hpp"

/**
 * Modèle de données
 */
struct Modele{
  // Niveau de gris du fond
  float mNiveauGris;
  std::vector<AbstractScene *> mSceneList;
  
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
  
  void addTeapot(int size){
  	this->mSceneList.push_back(new Teapot(size));
  }
    
  void addSystemeSolaire(int sizeSun){
  	this->mSceneList.push_back(new SystemeSolaire(sizeSun));
  }
  
  void addScene(std::string path){
  	this->mSceneList.push_back(new Scene(path));
  }
  
  void render(int i){
  	if(i<(int)this->mSceneList.size()){
  		this->mSceneList[i]->render();
  	}
  }
  
  void renderAll(){
  	for (unsigned i = 0; i < this->mSceneList.size(); i++){
  		this->render(i);
  	}
  }
  
  void clear(){
  	for(AbstractScene* sc : this->mSceneList){
  		delete sc;
  	}
  }
};
#endif
