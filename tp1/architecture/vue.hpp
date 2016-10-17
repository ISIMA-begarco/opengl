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
  DisplayManager(GLint largeurFenetre,GLint hauteurFenetre);
  
  /** Méthode d'affichage */
  void Affichage();

  /** Réglage du cadrage pour la vue
   * Doit être rappelée si la taille de la vue change (SDL_WINDOWEVENT)
   * @param l largeur de la (nouvelle) vue
   * @param h hauteur de la (nouvelle) vue
   */
  void Redimensionnement(GLint l,GLint h);
};
#endif
