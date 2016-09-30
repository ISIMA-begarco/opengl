/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: mouse.hpp                                                          * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

/** @brief Modèle pour la souris (interaction utilisateur)
 * Paramètres concernant la souris (état, vitesse, etc)
 */
struct MouseData{
  // Variables globales pour gestion de la souris
  static Sint32 mousex; // mémorise la dernière position de la souris 
  static Sint32 mousey; // mémorise la dernière position de la souris 
  static bool leftButtonPressed; // État des boutons de la souris
  static bool middleButtonPressed; // État des boutons de la souris
  static float vitesse; // facteur vitesse de la souris
};
// Initialisation des données de classe
Sint32 MouseData::mousex = 0;
Sint32 MouseData::mousey = 0;
bool MouseData::leftButtonPressed = false;
bool MouseData::middleButtonPressed = false;
float MouseData::vitesse = 0.2f;
