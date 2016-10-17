#include "gui.hpp"

static void WrapperSDL::EventController::Init(DisplayManager* p_ParamsAffichage){
	// Enregistrement d'un timer de raffraichissement de la vue 
	mTimerId = SDL_AddTimer(20, CreateTimerRefreshFrame,
		           (void*)p_ParamsAffichage);
}

static void WrapperSDL::EventController::DoEventsLoop(SDL_Window *window, 
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

static Uint32 WrapperSDL::EventController::CreateTimerRefreshFrame(Uint32 interval, void* p_DisplayManager){

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

WrapperSDL::WindowManager::WindowManager(int largeurFenetreInit, int hauteurFenetreInit,
	  const char* windowTitle)
	// Initialisation d'une fenêtre SDL
	:mWindow(init_SDL_Window(largeurFenetreInit, hauteurFenetreInit, 
		                        windowTitle)),
	// Création du contexte OpenGL associé à cette fenêtre 		
	mGlContext(new SDL_GLContext(SDL_GL_CreateContext(mWindow)))
{}

static SDL_Window * WrapperSDL::WindowManager::init_SDL_Window(int windowWidth, int windowHeight, const char* windowTitle){
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);
	SDL_Init(SDL_INIT_VIDEO);  

	// Le double buffering permet les animations temps réel 
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_Window *window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	return window;
}

WrapperSDL::WindowManager::~WindowManager(){
	SDL_GL_DeleteContext(*mGlContext);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
	delete mGlContext;
}

void WrapperSDL::DoEventsLoop(DisplayManager* p_ParamsAffichage){
	EventController::DoEventsLoop(mWindowManager.mWindow, p_ParamsAffichage);
}

WrapperSDL::WrapperSDL(int largeurFenetreInit, int hauteurFenetreInit,
     const char* windowTitle)
:mWindowManager(largeurFenetreInit, hauteurFenetreInit, windowTitle)
{}

void WrapperSDL::Init(DisplayManager* p_ParamsAffichage){
	EventController::Init(p_ParamsAffichage);
}
