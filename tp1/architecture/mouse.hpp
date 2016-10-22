/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: mouse.hpp                                                          * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef HEADER_MOUSE_HPP
#define HEADER_MOUSE_HPP

/** @brief Modèle pour la souris (interaction utilisateur)
 * Paramètres concernant la souris (état, vitesse, etc)
 */
class MouseData{
	public:
		// Variables globales pour gestion de la souris
		static int mousex; // mémorise la dernière position de la souris 
		static int mousey; // mémorise la dernière position de la souris 
		static int pmousex; // mémorise la precedente position de la souris 
		static int pmousey; // mémorise la precedente position de la souris 
		static bool leftButtonPressed; // État des boutons de la souris
		static bool middleButtonPressed; // État des boutons de la souris
		static bool rightButtonPressed; // État des boutons de la souris
		static float vitesse; // facteur vitesse de la souris

		static void updatePosition(int x, int y);
};

#endif
