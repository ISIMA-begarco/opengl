/**
 * @file vue.hpp
 * @brief Classe de gestion de l'affichage
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_VUE_HPP
#define HEADER_VUE_HPP

#include <unistd.h>
#include <GL/glut.h>

#include "modele.hpp"
#include "frames.hpp"
#include "transfoCamera.hpp"
#include "lookAtCamera.hpp"
#include "./sourceShading/light.hpp"



/**
 * @brief Classe de gestion de l'affichage.
 * Classe de gestion de l'affichage.
 */
class DisplayManager{
	public:
		double mRevolutionLight;	/// Valeur de la lumiere en revolution autour du point
		double mMovingLightX;		/// coordonnee x de la lumiere en mouvement
		double mMovingLightY;		/// coordonnee y de la lumiere en mouvement
		double mMovingLightZ;		/// coordonnee z de la lumiere en mouvement
		double mMovingLightIntensity;	/// Intensite de la lumiere en mouvement

		GLint mLargeurFenetre; /// Largeur de la vue
		GLint mHauteurFenetre; /// Hauteur de la vue

		// Modèle de données à afficher
		Modele mModele;	/// Modele a afficher
		TransfoCamera mCamera;	/// Camera utilisee
		LightSourceData mLight;	/// Sources de lumiere de la scene

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
