/*
    Secrets of Universe
    Copyright (C) 2014  BG Prod

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Contact me : bgprod@outlook.com
*/

#include "input.hpp"


Input::Input()
{
    for(int i = 0 ; i < SDLK_SIZE ; i++)
    {
        touche[i] = 0;
    }
    for(int i = 0 ; i < 8 ; i++)
    {
        souris_boutons[i] = 0;
    }
    exit = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        souris[i] = 0;
    }
    m_str = "";
    saisieActive = false;
}

Input::~Input()
{

}

void Input::update()
{
	SDL_Event event;
    souris_boutons[SDL_BUTTON_WHEELUP] = 0;
    souris_boutons[SDL_BUTTON_WHEELDOWN] = 0;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_KEYDOWN)
		{
            touche[event.key.keysym.sym] = 1;
		}
		if(event.type == SDL_KEYUP)
		{
		    touche[event.key.keysym.sym] = 0;
		}
		if(event.type == SDL_MOUSEMOTION)
		{
			souris[X] = event.motion.x;
			souris[Y] = event.motion.y;
			souris[X_REEL] = event.motion.xrel;
			souris[Y_REEL] = event.motion.yrel;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			souris_boutons[event.button.button] = 1;
		}
		if(event.type == SDL_MOUSEBUTTONUP)
		{
            if (event.button.button!=SDL_BUTTON_WHEELUP && event.button.button!=SDL_BUTTON_WHEELDOWN)
			{
                souris_boutons[event.button.button] = 0;
            }
		}
		if(event.type == SDL_QUIT)
		{
			exit = 1;
		}
	}
}

void Input::activerSaisie()
{
    m_str = "";
    saisieActive = true;
}

void Input::desactiverSaisie()
{
    saisieActive = false;
}

bool Input::modeSaisie()
{
    return saisieActive;
}

std::string Input::str()
{
    return m_str;
}
