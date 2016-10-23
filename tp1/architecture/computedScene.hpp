/**
 * @file computedScene.hpp
 * @brief Scene chargee calculee en temps reel par openGL
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */


#ifndef HEADER_COMPUTED_SCENE_HPP
#define HEADER_COMPUTED_SCENE_HPP

#include "abstractScene.hpp"
#include "../cameraParams/transform.hpp"

#include <iostream>
#include <cmath>

/**
*	Scene renvoyant une teiere calculee par OpenGL
*/
class Teapot : public AbstractScene {
	private:
		int mSize;

	public:
		Teapot(int size): mSize(size){}
		~Teapot() {}

		void render();
};

/**
*	Scene renvoyant un systeme solaire anime par transformation,
*  calculee par OpenGL
*/
class SystemeSolaire : public AbstractScene {
	private:
		const int mRayonSoleil;	/// Rayon de la sphere centrale
		const double inc;				/// Increment de rotation
		double mRevolutionSelf;	/// Etat de la rotation actuelle de la planete sur elle meme
		double mRevolutionSun;	/// Etat de la rotation actuelle de la planete autour du soleil

	public:
		SystemeSolaire(int rayonSoleil): mRayonSoleil(rayonSoleil), inc(0.2), mRevolutionSelf(0.0), mRevolutionSun(0.0) {}
		~SystemeSolaire() {}

		void render();
};

/**
*	Scene renvoyant une voiture animee par transformation,
*  calculee par OpenGL
*/
class Voiture : public AbstractScene {
	private:
		double mVitesseRoue;	/// increment de vitesse de rotation des roues de la voiture
		int mStep;						/// etat de la rotation des roues
		const int maxStep;		/// etat max de la rotaiton des roues

	public:
		Voiture(double vitesseRoue = 0.1): mVitesseRoue(vitesseRoue), mStep(0), maxStep((int)(360.0/vitesseRoue)) {}
		~Voiture() {}

		/**
		 * @brief Dessine une roue animee
		 */
		void drawRoue();

		/**
		 * @brief dessine un essieu avec ses deux roues animees
		 */
		void drawEssieu(double longueur);

		/**
		 * @brief dessine le corps de la voiture
		 */
		void drawCorps();

		void render();
};

#endif
