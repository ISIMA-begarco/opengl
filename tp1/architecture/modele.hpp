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
/**
 * Modèle de données
 */
struct Modele{
  // Niveau de gris du fond
  float mNiveauGris;
  
  /** @brief constructeur par défaut
   * Initialise les données nécessaires à l'affichage. */
  Modele()
    :mNiveauGris(0.0f)
  {}
  
  /** Mise à jour du modèle appelée à chaque événement timer */
  void Update(){
    mNiveauGris += 0.01f;
    if (mNiveauGris > 1.0f){
      mNiveauGris = 0.0f;
    }
  }
};
#endif
