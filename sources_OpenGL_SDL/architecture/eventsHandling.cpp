/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: eventsHandling.cpp                                                 * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "gui.hpp"

/**
 * @brief Gestion d'un événement SDL extrait de la file
 * @param p_evenement données de l'événement
 * @param window  Fenêtre SDL (pour gérer les SDL_WINDOWEVENT)
 * @param p_ParamsAffichage instance de la classe Vue
 * @return true si l'événement est SDL_QUIT (fermeture de la fenêtre)
 */
bool WrapperSDL::EventController::Handle_SDL_Event(SDL_Event *p_evenement, SDL_Window *window,
		      DisplayManager *p_ParamsAffichage){
  switch (p_evenement->type){ // suivant le type d'événement 
    //////////////////////////////////////////////////////
    // Événements utilisateur via la souris
    case SDL_MOUSEBUTTONDOWN: // Enfoncement d'un bouton souris 
      switch (p_evenement->button.button){
	case SDL_BUTTON_LEFT :  // Bouton gauche 
	  MouseData::leftButtonPressed=true;
	  MouseData::mousex = p_evenement->button.x; // mémorisation coordonnées souris 
	  MouseData::mousey = p_evenement->button.y; // mémorisation coordonnées souris 
	  break;
	case SDL_BUTTON_MIDDLE :  // Bouton gauche 
	  MouseData::middleButtonPressed=true;
	  MouseData::mousex = p_evenement->button.x; // mémorisation coordonnées souris 
	  MouseData::mousey = p_evenement->button.y; // mémorisation coordonnées souris 
	  break;
	default: ;
      }
      break;     
    case SDL_MOUSEBUTTONUP: // Relachement d'un bouton souris 
      switch (p_evenement->button.button){
	case SDL_BUTTON_LEFT :  // Bouton gauche 
	  MouseData::leftButtonPressed=false;
	  break;
	case SDL_BUTTON_MIDDLE :  // Bouton gauche 
	  MouseData::middleButtonPressed=false;
	  break;
	default: ;
      }
      break;  
    case SDL_MOUSEMOTION: // Mouvement de la souris 
      if (MouseData::leftButtonPressed){
	// Mise à jour du modèle
	// Non implémenté
	MouseData::mousex = p_evenement->motion.x; // enregistrement des nouvelles 
	MouseData::mousey = p_evenement->motion.y; // coordonnées de la souris 
      }
      if (MouseData::middleButtonPressed){
	// Mise à jour du modèle
	// Non implémenté
	MouseData::mousex = p_evenement->motion.x; // enregistrement des nouvelles 
	MouseData::mousey = p_evenement->motion.y; // coordonnées de la souris 
      }
      break;       
    //////////////////////////////////////////////////////
    // Événements perso : raffraîchissement de la vue
    case SDL_USEREVENT: // Événement timer
    {	  
      // Récupération des données de l'événement nécessaire à l'affichage
      DisplayManager* paramsAff = static_cast<DisplayManager*>(p_evenement->user.data1);
      
      // Mise à jour du modèle :
      paramsAff->mModele.Update();

      // on raffraichit la vue
      paramsAff->Affichage();
 
      SDL_GL_SwapWindow(window); // On envoie le buffer à l'écran 
    }
    break;
    //////////////////////////////////////////////////////
    // Événements utilisateur sur la fenêtre graphique
    case SDL_WINDOWEVENT: // La fenêtre graphique a changé
      int w,h;
      SDL_GetWindowSize(window,&w,&h); // récupération taille fenêtre 
      p_ParamsAffichage->Redimensionnement(w, h);
      break;
    //////////////////////////////////////////////////////
    // Fermeture de l'application
    case SDL_QUIT: // fermeture de la fenêtre 
      return true;
      break;
    default:
      fprintf(stderr, "Événement non géré\n");
  }     
  return false;
}
