#include "vue.hpp"

DisplayManager::DisplayManager(GLint largeurFenetre,GLint hauteurFenetre)
    :mLargeurFenetre(largeurFenetre),
    mHauteurFenetre(hauteurFenetre),
    mModele(), // Construction du modèle
    mCamera(3, 20, -50,
    			0,0,0,
    			0,1,0,
    			1,1000, 50)
  {
    FramesData::Init();
    mCamera.Redimensionnement(largeurFenetre, hauteurFenetre);
   this->mModele.addScene("../testAssimp/dwarf.x");
   //this->mModele.addTeapot(5);
   //this->mModele.addSystemeSolaire(10);
   //this->mModele.addVoiture(1.0);
  }

void DisplayManager::Affichage(){
	
    // Affichage des Frames par seconde (FPS)
    if (FramesData::Update()){
      fprintf(stderr, "%s\n", FramesData::getDescriptionFPS());
    }
    
	// On efface le buffer vidéo (fenêtre graphique)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    mCamera.LookAt();
    mModele.renderAll();

}

void DisplayManager::Redimensionnement(GLint l,GLint h){
    mLargeurFenetre = l;
    mHauteurFenetre = h;
    // Surface de rendu (voir chapitres suivants)
    glViewport((GLint)mCamera.mPosition[0],(GLint)mCamera.mPosition[1],(GLsizei)l,(GLsizei)h);
    mCamera.Redimensionnement(l, h);
    
}

