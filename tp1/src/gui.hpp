/**
 * @file gui.hpp
 * @brief Wrapper SDL
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_GUI_HPP
#define HEADER_GUI_HPP

#include <SDL2/SDL.h>

class DisplayManager;

/**
 * Classe Wrapper pour SDL et assurant les fonctionnalités de la GUI
 */
struct WrapperSDL{
	/**
	* Classe Controleur d'événements
	*/
	struct EventController{
		static SDL_TimerID mTimerId; // Au cas où on ait besoin de modifier

		/** Initialisation du timer */
		static void Init(DisplayManager* p_ParamsAffichage);

		/** Boucle d'attente des événements
		 * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT)
		 * @param p_ParamsAffichage instance de la classe Vue
		 **/
		static void DoEventsLoop(SDL_Window *window,
					 DisplayManager* p_ParamsAffichage);

		/**
		 * @brief Gestion d'un événement SDL extrait de la file
		 * @param p_evenement données de l'événement
		 * @param window  Fenêtre SDL (pour gérer les SDL_WINDOWEVENT)
		 * @param p_ParamsAffichage instance de la classe Vue
		 * @return true si l'événement est SDL_QUIT (fermeture de la fenêtre)
		 */
		static bool Handle_SDL_Event(SDL_Event *p_evenement, SDL_Window *window,
				                      DisplayManager *p_ParamsAffichage);

		/**
		 * @brief Callback du timer de raffraichissement de la vue
		 * @see http://sdl.beuc.net/sdl.wiki/SDL_AddTimer
		 */
		static Uint32 CreateTimerRefreshFrame(Uint32 interval, void* p_DisplayManager);
	};

	/**
	* @brief Classe gestionnaire de la fenêtre graphique et du contexte OpenGL
	*/
	struct WindowManager{

		SDL_Window *mWindow;
		SDL_GLContext *mGlContext;

		WindowManager(int largeurFenetreInit, int hauteurFenetreInit,
			  const char* windowTitle);

		/** @brief Fonction d'initialisation de la fenêtre SDL
		  @param windowWidth largeur de la fenêtre en pixels
		  @param windowWidth largeur de la fenêtre en pixels
		  @param windowTitle Titre de la fenêtre dans sa barre de titre
		*/
		static SDL_Window * init_SDL_Window(int windowWidth, int windowHeight, const char* windowTitle);

		// On interdit explicitement la recopie
		WindowManager(const WindowManager&) = delete;
		WindowManager & operator=(const WindowManager&) = delete;

		/** Destruction : Libération des ressources SDL */
		~WindowManager();
	};

	/** Boucle d'attente des événements */
	void DoEventsLoop(DisplayManager* p_ParamsAffichage);

	/** Instance de la classe gérant la fenêtre graphique */
	WindowManager mWindowManager;

	/** Construit la fenêtre graphique au dimensions, ainsi que le contexte OpenGL */
	WrapperSDL(int largeurFenetreInit, int hauteurFenetreInit,
		 const char* windowTitle);

	/** Initialisation de l'instance contenant les données pour implémenter
	* les événements (vue, modèle...) **/
	void Init(DisplayManager* p_ParamsAffichage);
};

#endif
