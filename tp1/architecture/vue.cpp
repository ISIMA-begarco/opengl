#include "vue.hpp"
#include <cstdio>

DisplayManager::DisplayManager(GLint largeurFenetre,GLint hauteurFenetre)
    :mLargeurFenetre(largeurFenetre),
    mHauteurFenetre(hauteurFenetre),
    mModele(), // Construction du modèle
    mCamera(3, 20, -50,
    			0,0,0,
    			0,1,0,
    			1,1000, 50),
    mLight()
  {
    FramesData::Init();
    RenderingModel::Init();

    mCamera.Redimensionnement(largeurFenetre, hauteurFenetre);
    mLight.AddSource(AbstractCamera::TypeRepere::CAMERA,GL_LIGHT0,
          40, 20, -40,
          mLight.mIntensity, mLight.mIntensity, mLight.mIntensity,
          mLight.mIntensity, mLight.mIntensity, mLight.mIntensity);
    mLight.ApplyLightPositions(AbstractCamera::TypeRepere::CAMERA);
    mLight.ApplyLightIntensities();

    glDisable(GL_COLOR_MATERIAL);

    RenderingModel::ApplyMaterial (mModele.mMaterialAllScenes);

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
    RenderingModel::InitView();

    mLight.ApplyLightPositions(AbstractCamera::TypeRepere::MONDE);




    mCamera.ChangerRepereCamera();
    mModele.renderAll();


}

void DisplayManager::Redimensionnement(GLint l,GLint h){
    mLargeurFenetre = l;
    mHauteurFenetre = h;
    // Surface de rendu (voir chapitres suivants)
    glViewport((GLint)mCamera.getPosition()[0],(GLint)mCamera.getPosition()[1],(GLsizei)l,(GLsizei)h);
    mCamera.Redimensionnement(l, h);

}
