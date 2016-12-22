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
		double mRevolutionLight;
		double mMovingLightX;
		double mMovingLightY;
		double mMovingLightZ;
		double mMovingLightIntensity;

		GLint mLargeurFenetre; // Largeur de la vue
		GLint mHauteurFenetre; // Hauteur de la vue

		// Modèle de données à afficher
		Modele mModele;
		TransfoCamera mCamera;
		LightSourceData mLight;

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
