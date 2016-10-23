/**
 * @file eventHandling.cpp
 * @brief Classe de gestion des évènements
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#include "gui.hpp"
#include <list>
#include <algorithm>
#include <iostream>

#define VITESSEKEY 10
#define VITESSEMOU 100
#define VITESSEROT 5

/**
 * @brief Gestion d'un événement SDL extrait de la file
 * @param p_evenement données de l'événement
 * @param window  Fenêtre SDL (pour gérer les SDL_WINDOWEVENT)
 * @param p_ParamsAffichage instance de la classe Vue
 * @return true si l'événement est SDL_QUIT (fermeture de la fenêtre)
 */

bool managePressedKeys(std::list<int> keys, DisplayManager *p_ParamsAffichage){
	bool res = std::find(keys.begin(), keys.end(), SDLK_q) != keys.end();
	if (res){
		exit(0);
	}

	if(std::find(keys.begin(), keys.end(), SDLK_LSHIFT) != keys.end() ||
		std::find(keys.begin(), keys.end(), SDLK_RSHIFT) != keys.end()){
			// MAJ PRESSED
		if(std::find(keys.begin(), keys.end(), SDLK_x) != keys.end()){
			p_ParamsAffichage->mCamera.GetPosition()[0] += VITESSEKEY;
		}

		if(std::find(keys.begin(), keys.end(), SDLK_a) != keys.end()){
			p_ParamsAffichage->mCamera.SetAzimuth(p_ParamsAffichage->mCamera.GetAzimuth() + VITESSEROT);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_e) != keys.end()){
			p_ParamsAffichage->mCamera.SetElevation(p_ParamsAffichage->mCamera.GetElevation() + VITESSEROT);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_y) != keys.end()){
			p_ParamsAffichage->mCamera.GetPosition()[1] += VITESSEKEY;
		}

		if(std::find(keys.begin(), keys.end(), SDLK_z) != keys.end()){
			p_ParamsAffichage->mCamera.GetPosition()[2] += VITESSEKEY;
		}

		if(std::find(keys.begin(), keys.end(), SDLK_d) != keys.end()){
			p_ParamsAffichage->mCamera.ChangementAngle(p_ParamsAffichage->mCamera.GetAngleOuverture() + VITESSEKEY);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_i) != keys.end()){
			p_ParamsAffichage->mLight.SetIntensities(p_ParamsAffichage->mLight.mIntensity+0.1f);
			p_ParamsAffichage->mLight.ApplyLightIntensities();
		}

		if(std::find(keys.begin(), keys.end(), SDLK_b) != keys.end()){
			p_ParamsAffichage->mModele.changeBrillance(p_ParamsAffichage->mModele.mBrillance + 8.0f);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_o) != keys.end()){
			p_ParamsAffichage->mModele.changeRefAmbiante(p_ParamsAffichage->mModele.mReflexionAmbiante + 0.1f);
		}

	}else{

		if(std::find(keys.begin(), keys.end(), SDLK_a) != keys.end()){
			p_ParamsAffichage->mCamera.SetAzimuth(p_ParamsAffichage->mCamera.GetAzimuth() - VITESSEROT);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_e) != keys.end()){
			p_ParamsAffichage->mCamera.SetElevation(p_ParamsAffichage->mCamera.GetElevation() - VITESSEROT);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_x) != keys.end()){
			p_ParamsAffichage->mCamera.GetPosition()[0] -= VITESSEKEY;
		}

		if(std::find(keys.begin(), keys.end(), SDLK_y) != keys.end() ||
			std::find(keys.begin(), keys.end(), SDLK_DOWN) != keys.end() ){
			p_ParamsAffichage->mCamera.GetPosition()[1] += VITESSEKEY;
		}

		if(std::find(keys.begin(), keys.end(), SDLK_z) != keys.end()){
			p_ParamsAffichage->mCamera.GetPosition()[2] -= VITESSEKEY;
		}

		if(std::find(keys.begin(), keys.end(), SDLK_d) != keys.end()){
			p_ParamsAffichage->mCamera.ChangementAngle(p_ParamsAffichage->mCamera.GetAngleOuverture() - VITESSEKEY);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_i) != keys.end()){
			p_ParamsAffichage->mLight.SetIntensities(p_ParamsAffichage->mLight.mIntensity-0.1f);
			p_ParamsAffichage->mLight.ApplyLightIntensities();
		}

		if(std::find(keys.begin(), keys.end(), SDLK_b) != keys.end()){
			p_ParamsAffichage->mModele.changeBrillance(p_ParamsAffichage->mModele.mBrillance - 8.0f);
		}

		if(std::find(keys.begin(), keys.end(), SDLK_o) != keys.end()){
			p_ParamsAffichage->mModele.changeRefAmbiante(p_ParamsAffichage->mModele.mReflexionAmbiante - 0.1f);
		}
	}

	if(std::find(keys.begin(), keys.end(), SDLK_UP) != keys.end()){
		p_ParamsAffichage->mCamera.GetPosition()[1] -= VITESSEKEY;
	}

	if(std::find(keys.begin(), keys.end(), SDLK_RIGHT) != keys.end()){
		p_ParamsAffichage->mCamera.GetPosition()[0] -= VITESSEKEY;
	}

	if(std::find(keys.begin(), keys.end(), SDLK_LEFT) != keys.end()){
		p_ParamsAffichage->mCamera.GetPosition()[0] += VITESSEKEY;
		//std::cout << p_ParamsAffichage->mCamera.GetPosition()[0] << " " << p_ParamsAffichage->mCamera.GetPosition()[1] << " " << p_ParamsAffichage->mCamera.GetPosition()[2] << std::endl;
	}

	if(std::find(keys.begin(), keys.end(), SDLK_t) != keys.end()){
		p_ParamsAffichage->mCamera.Zoumage(true);
	}

	if(std::find(keys.begin(), keys.end(), SDLK_r) != keys.end()){
		p_ParamsAffichage->mCamera.Zoumage(false);
	}

	return res;
}

/** @brief Gère le déplacement de la caméra
  * @param Le display manager
  */
void manageCamMove(DisplayManager *p_ParamsAffichage){
	p_ParamsAffichage->mCamera.GetVisee()[0] += ((float)(MouseData::pmousex - MouseData::mousex)/(float)(p_ParamsAffichage->mLargeurFenetre))*(float)VITESSEMOU;
	p_ParamsAffichage->mCamera.GetVisee()[1] -= ((float)(MouseData::pmousey - MouseData::mousey)/(float)(p_ParamsAffichage->mHauteurFenetre))*(float)VITESSEMOU;
}

/** @brief Gère l'orientation de la caméra
  * @param Le display manager
  */
void manageCamAngle(DisplayManager *p_ParamsAffichage){
	p_ParamsAffichage->mCamera.SetAzimuth(p_ParamsAffichage->mCamera.GetAzimuth()-((float)(MouseData::pmousex - MouseData::mousex)/(float)(p_ParamsAffichage->mLargeurFenetre))*(float)VITESSEMOU);
	p_ParamsAffichage->mCamera.SetElevation(p_ParamsAffichage->mCamera.GetElevation()-((float)(MouseData::pmousey - MouseData::mousey)/(float)(p_ParamsAffichage->mHauteurFenetre))*(float)VITESSEMOU);
}

/** @brief Capture des évènements SDL
  */
bool WrapperSDL::EventController::Handle_SDL_Event(SDL_Event *p_evenement, SDL_Window *window,
		      DisplayManager *p_ParamsAffichage){
	static std::list<int> keys;
	std::list<int>::iterator toRemove;
	bool res = false;
  switch (p_evenement->type){ // suivant le type d'événement
    //////////////////////////////////////////////////////
    // Événements utilisateur via la souris
    case SDL_MOUSEBUTTONDOWN: // Enfoncement d'un bouton souris
      switch (p_evenement->button.button){
			case SDL_BUTTON_LEFT :  // Bouton gauche
			  MouseData::leftButtonPressed=true;
			 // MouseData::updatePosition(p_evenement->button.x, p_evenement->button.y);
			  break;
			case SDL_BUTTON_MIDDLE :  // Bouton milieu
			  MouseData::middleButtonPressed=true;
			 // MouseData::updatePosition(p_evenement->button.x, p_evenement->button.y);
			  break;
			case SDL_BUTTON_RIGHT :  // Bouton droit
			  MouseData::rightButtonPressed=true;
			 // MouseData::updatePosition(p_evenement->button.x, p_evenement->button.y);
			  break;
			default:
			  break;
      }
      break;
    case SDL_MOUSEBUTTONUP: // Relachement d'un bouton souris
      switch (p_evenement->button.button){
			case SDL_BUTTON_LEFT :  // Bouton gauche
			  MouseData::leftButtonPressed=false;
			  break;
			case SDL_BUTTON_MIDDLE :  // Bouton milieu
			  MouseData::middleButtonPressed=false;
			  break;
			case SDL_BUTTON_RIGHT :  // Bouton droit
			  MouseData::rightButtonPressed=false;
			  break;
			default: ;
      }
      break;
    case SDL_MOUSEMOTION: // Mouvement de la souris
      MouseData::updatePosition(p_evenement->motion.x, p_evenement->motion.y);
      if (MouseData::leftButtonPressed){
			 // MouseData::updatePosition(p_evenement->motion.x, p_evenement->motion.y);
			 manageCamAngle(p_ParamsAffichage);
      }
      if (MouseData::middleButtonPressed){
			 // MouseData::updatePosition(p_evenement->motion.x, p_evenement->motion.y);
      }
      if (MouseData::rightButtonPressed){
			 // MouseData::updatePosition(p_evenement->motion.x, p_evenement->motion.y);
			 manageCamMove(p_ParamsAffichage);
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
	 // Événements perso : appuie de touches

	 // Faire une liste des touches appuyées si on trouve pas d'autre solution

	case SDL_KEYDOWN:
		keys.push_back(p_evenement->key.keysym.sym);
		keys.unique();
		res = managePressedKeys(keys, p_ParamsAffichage);

    break;
    //////////////////////////////////////////////////////
	 // Événements perso : relachement de touches
    case SDL_KEYUP:
	   	toRemove = std::find(keys.begin(), keys.end(), p_evenement->key.keysym.sym);
    	if(toRemove != keys.end()){
    		keys.erase(toRemove);
    	}
    break;

    //////////////////////////////////////////////////////
    // Événements utilisateur sur la fenêtre graphique
    case SDL_WINDOWEVENT: // La fenêtre graphique a changé
      //int w,h;
      //SDL_GetWindowSize(window,&w,&h); // récupération taille fenêtre
      //p_ParamsAffichage->Redimensionnement(w, h);
     break;
    //////////////////////////////////////////////////////
    // Fermeture de l'application
    case SDL_QUIT: // fermeture de la fenêtre
      return true;
    break;

    default:
      //fprintf(stderr, "Événement non géré\n");
	  break;
  }
  return res;
}
