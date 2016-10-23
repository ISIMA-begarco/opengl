/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    *
*     http://malgouyres.org                                                    *
*     File: main.cpp                                                           *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
//#include <GLES3/gl3.h>
#include <GL/glut.h>

#include "frames.hpp"
#include "modele.hpp"
#include "../cameraParams/transform.hpp"
#include "vue.hpp"
#include "mouse.hpp"
#include "gui.hpp"
#include "eventsHandling.cpp"

/**
 * CLASSE TOUTES LES DONNÉES DE L'APPLICATION
 * RÉALISE LES INITIALISATIONS
 * @warning Le gestionnaire de GUI initialise le contexte OpenGL
 * qui peut être utilisé par les contructeurs les paramètres de la vue
 * (choix du mode graphique, etc.)
 * Le gestionnaire de GUI initialise doit donc être initialisé avant
 * les paramètres de l'affichage.
 **/
struct MainApplication{
  // Gestionnaire de GUI et Contexte OpenGL
  WrapperSDL mGuiManager;

  // Variable globale initialisées par le constructeur par défaut
  DisplayManager mParamsAffichage;

  /**
   * @param largeurFenetreInit largeur initiale de la fenêtre graphique
   * @param hauteurFenetreInit hauteur initiale de la fenêtre graphique
   **/
  MainApplication(int largeurFenetreInit, int hauteurFenetreInit,
		  const char* windowTitle)
    : mGuiManager(largeurFenetreInit, hauteurFenetreInit, windowTitle),
      mParamsAffichage(largeurFenetreInit, hauteurFenetreInit)
    {
      mGuiManager.Init(&mParamsAffichage);
    }

  /** Boucle d'attente des événements */
  void DoEventsLoop(){
    mGuiManager.DoEventsLoop(&mParamsAffichage);
  }
};

/////////////////////////////////////////////////////////////////
// PROGRAMME PRINCIPAL
/////////////////////////////////////////////////////////////////

int main(int argc, char**argv)
{
  MainApplication myApp(900, 900, "OpenGL de Pierre et Benoît");
  glutInit(&argc, argv);
  myApp.DoEventsLoop();

  return 0;
}
