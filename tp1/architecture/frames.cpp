#include "frames.hpp"  

  static void FramesData::Init(){
    strcpy(mDescriptionFPS, "00 Frames en 00s, FPS: --");
  }

  static bool FramesData::Update(){
    mNbFrames++;

    // gestion des frames par secondes (ici 50 fps) 
    GLint currentTime = SDL_GetTicks(); // date courante en milliseconde 
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

  static const char* FramesData::getDescriptionFPS(){
    return mDescriptionFPS;
  }
