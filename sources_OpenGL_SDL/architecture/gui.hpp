/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: gui.hpp                                                            * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef HEADER_GUI_HPP
#define HEADER_GUI_HPP
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
    static void Init(DisplayManager* p_ParamsAffichage){
      // Enregistrement d'un timer de raffraichissement de la vue 
      mTimerId = SDL_AddTimer(20, CreateTimerRefreshFrame,
                           (void*)p_ParamsAffichage);
    }
    
    /** Boucle d'attente des événements
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT)
     * @param p_ParamsAffichage instance de la classe Vue
     **/
    static void DoEventsLoop(SDL_Window *window, 
			     DisplayManager* p_ParamsAffichage){
      bool terminer=false;
      SDL_Event evenement; // union contenant un évennement 

      while(!terminer){
        while (SDL_PollEvent(&evenement)){  // on défile les évennements 
          // Gestion de l'événement et modification des variables
          terminer = Handle_SDL_Event(&evenement, window, p_ParamsAffichage);
        }
      }
    }

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
    static Uint32 CreateTimerRefreshFrame(Uint32 interval, void* p_DisplayManager){
      
      SDL_UserEvent userevent;

      userevent.type = SDL_USEREVENT;
      userevent.code = 0;
      // Initialisation des données de l'événement nécessaire à l'affichage
      userevent.data1 = (void*)p_DisplayManager; // fonction de raffraichissement de la vue
      userevent.data2 = NULL; // On ne l'utilise pas ici
      
      // On crée l'événement pour la fois suivante
      SDL_Event event;
      event.type = SDL_USEREVENT;
      event.user = userevent;

      SDL_PushEvent(&event);

      return interval;
    }
  };

   /**
   * @brief Classe gestionnaire de la fenêtre graphique et du contexte OpenGL
   */
  struct WindowManager{
    
    SDL_Window *mWindow;
    SDL_GLContext *mGlContext;
    WindowManager(int largeurFenetreInit, int hauteurFenetreInit,
		  const char* windowTitle)
       // Initialisation d'une fenêtre SDL
      :mWindow(init_SDL_Window(largeurFenetreInit, hauteurFenetreInit, 
                                        windowTitle)),
      // Création du contexte OpenGL associé à cette fenêtre 		
      mGlContext(new SDL_GLContext(SDL_GL_CreateContext(mWindow)))
    {}
    
    /** @brief Fonction d'initialisation de la fenêtre SDL 
      @param windowWidth largeur de la fenêtre en pixels
      @param windowWidth largeur de la fenêtre en pixels
      @param windowTitle Titre de la fenêtre dans sa barre de titre
    */
    static SDL_Window * init_SDL_Window(int windowWidth, int windowHeight, const char* windowTitle){
      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);
      SDL_Init(SDL_INIT_VIDEO);  
      
      // Le double buffering permet les animations temps réel 
      SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
      SDL_Window *window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
      return window;
    }
    
    // On interdit explicitement la recopie
    WindowManager(const WindowManager&) = delete;
    WindowManager & operator=(const WindowManager&) = delete;
    
    /** Destruction : Libération des ressources SDL */
    ~WindowManager(){
      SDL_GL_DeleteContext(*mGlContext);
      SDL_DestroyWindow(mWindow);
      SDL_Quit();
      delete mGlContext;
    }
  };
      
  /** Boucle d'attente des événements */
  void DoEventsLoop(DisplayManager* p_ParamsAffichage){
    EventController::DoEventsLoop(mWindowManager.mWindow, p_ParamsAffichage);
  }

  /** Instance de la classe gérant la fenêtre graphique */
  WindowManager mWindowManager;
  
  /** Construit la fenêtre graphique au dimensions, ainsi que le contexte OpenGL */
  WrapperSDL(int largeurFenetreInit, int hauteurFenetreInit,
	     const char* windowTitle)
    :mWindowManager(largeurFenetreInit, hauteurFenetreInit, windowTitle)
  {}
  
  /** Initialisation de l'instance contenant les données pour implémenter
   * les événements (vue, modèle...) **/
  void Init(DisplayManager* p_ParamsAffichage){
    EventController::Init(p_ParamsAffichage);
  }
};
SDL_TimerID WrapperSDL::EventController::mTimerId;
#endif
