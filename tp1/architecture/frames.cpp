#include "frames.hpp"
#include <cstdio>
#include <cstring>
#include <SDL2/SDL.h>

// Initialisation des données de classe
int FramesData::mNbSeconds = 0; 
int FramesData::mNbFrames=0;
int FramesData::mLastNbFrames=0; // compteur de frames 
int FramesData::mNextDueFrameDate = 0; // pour timer affichage 
int FramesData::mFps = 0; // pour timer affichage 
char FramesData::mDescriptionFPS[200];


void FramesData::Init(){
	strcpy(mDescriptionFPS, "00 Frames en 00s, FPS: --");
}

bool FramesData::Update(){
	mNbFrames++;

	// gestion des frames par secondes (ici 50 fps) 
	int currentTime = SDL_GetTicks(); // date courante en milliseconde 
	if (currentTime/1000 > mNbSeconds){
		mFps = mNbFrames-mLastNbFrames;
		mLastNbFrames = mNbFrames;
		mNbSeconds++;
		sprintf(mDescriptionFPS, "       %4d Frames, en %ds, soit %d FPS       ",
		mNbFrames , mNbSeconds, mFps);
		return true;
	}
	return false;
}

const char* FramesData::getDescriptionFPS(){
	return mDescriptionFPS;
}
