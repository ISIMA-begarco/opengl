/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: frames.hpp                                                         * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

/**
 * DONNÉES POUR LE TIMER ET LE CALCUL DES FRAMES PER SECONDS
*/
struct FramesData{
  static GLint mNbSeconds; // compteur de secondes
  static GLint mNbFrames;
  static GLint mLastNbFrames; // compteur de frames 
  static GLint mNextDueFrameDate; // pour timer affichage 
  static GLint mFps; // frames par secondes
  
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
// Initialisation des données de classe
GLint FramesData::mNbSeconds = 0; 
GLint FramesData::mNbFrames=0;
GLint FramesData::mLastNbFrames=0; // compteur de frames 
GLint FramesData::mNextDueFrameDate = 0; // pour timer affichage 
GLint FramesData::mFps = 0; // pour timer affichage 
char FramesData::mDescriptionFPS[200];


