/**
 * @file main.cpp
 * @brief Programme principal
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#include <cstdlib>
#include <cstdio>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
//#include <GLES3/gl3.h>
#include <GL/glut.h>

#include "frames.hpp"
#include "modele.hpp"
#include "./cameraParams/transform.hpp"
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
  glutInit(&argc, argv);
  MainApplication myApp(1080, 1080, "OpenGL à Pierre et Benoît");
  myApp.DoEventsLoop();

  return 0;
}
