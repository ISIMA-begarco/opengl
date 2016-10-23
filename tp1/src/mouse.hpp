/**
 * @file mouse.hpp
 * @brief Classe de gestion de la souris
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_MOUSE_HPP
#define HEADER_MOUSE_HPP

/** @brief Modèle pour la souris (interaction utilisateur)
 * Paramètres concernant la souris (état, vitesse, etc)
 */
class MouseData{
	public:
		/// mémorise la dernière position de la souris
		static int mousex;
		/// mémorise la dernière position de la souris
		static int mousey;
		/// mémorise la precedente position de la souris
		static int pmousex;
		/// mémorise la precedente position de la souris
		static int pmousey;
		/// État des boutons de la souris
		static bool leftButtonPressed;
		/// État des boutons de la souris
		static bool middleButtonPressed;
		/// État des boutons de la souris
		static bool rightButtonPressed;
		/// facteur vitesse de la souris
		static float vitesse;

		/** @brief Mise à jour des coordonnées de la souris
		  * @param Coordonnée x
		  * @param Coordonnée y
		  */
		static void updatePosition(int x, int y);
};

#endif
