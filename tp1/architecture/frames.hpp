/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: frames.hpp                                                         * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

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
