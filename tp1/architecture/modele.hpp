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
  Modele();
  
  /** Mise à jour du modèle appelée à chaque événement timer */
  void Update();
  
  void addTeapot(int size);
  void addSystemeSolaire(int sizeSun);
  void addVoiture(double vitesse);
  void addScene(std::string path);
  
  void render(int i);
  void renderAll();
  
  void clear();
};
#endif
