/**
 * @file frames.hpp
 * @brief Classe de gestion des frames
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_FRAMES_HPP
#define HEADER_FRAMES_HPP

/**
 * DONNÉES POUR LE TIMER ET LE CALCUL DES FRAMES PER SECONDS
*/
class FramesData {

	public:

		static int mNbSeconds; // compteur de secondes
		static int mNbFrames;
		static int mLastNbFrames; // compteur de frames
		static int mNextDueFrameDate; // pour timer affichage
		static int mFps; // frames par secondes

		private: static char mDescriptionFPS[200];

		public:

		// Initialisation de la description des FPS
		static void Init();

		/**
		* Met à jour l'information du Frame Rate
		* @return true si une mise à jour a eu lieu (chaque seconde)
		*/
		static bool Update();

		/**
		* @return description des numéro de frame, durée, et FPS
		*/
		static const char* getDescriptionFPS();
};

#endif
