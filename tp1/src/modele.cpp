/**
 * @file modele.cpp
 * @brief Classe du modèle de MVC
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#include "modele.hpp"

Modele::Modele() : mNiveauGris(0.0f), mSceneList(), mBrillance(120.0f), mReflexionAmbiante(0.2f),
	mMaterialAllScenes(mReflexionAmbiante,mReflexionAmbiante,mReflexionAmbiante,
										1.0f,1.0f,1.0f,
										1.0f,1.0f,1.0f,
										mBrillance) {
}

void Modele::Update(){
	mNiveauGris += 0.01f;
	if (mNiveauGris > 1.0f){
	mNiveauGris = 0.0f;
	}
}

void Modele::addTeapot(int size){
	this->mSceneList.push_back(new Teapot(size));
}

void Modele::addSystemeSolaire(int sizeSun){
	this->mSceneList.push_back(new SystemeSolaire(sizeSun));
}

void Modele::addVoiture(double vitesse){
	this->mSceneList.push_back(new Voiture(vitesse));
}

void Modele::addCylindre(double pRayon, double pHauteur, int pNbMeridien){
	this->mSceneList.push_back(new Cylindre(pRayon, pHauteur, pNbMeridien));
}

void Modele::addScene(std::string path, bool reshape){
	this->mSceneList.push_back(new Scene(path,"",reshape) );
}

void Modele::addSceneWithTexture(std::string path, std::string texture, bool reshape){
	this->mSceneList.push_back(new Scene(path,texture,reshape) );
}

void Modele::render(int i){
	if(i<(int)this->mSceneList.size()){
		this->mSceneList[i]->render();
	}
}

void Modele::renderAll(){
	for (unsigned i = 0; i < this->mSceneList.size(); i++){
		this->render(i);
	}
}

void Modele::changeBrillance(float brillance){
	if(brillance>=0.0f && brillance<128.0f){
		mBrillance=brillance;
		mMaterialAllScenes.mShininess[0] = mBrillance;
		RenderingModel::ApplyMaterial(mMaterialAllScenes);
	}
}

void Modele::changeRefAmbiante(float refAmbiante){
	if(refAmbiante>=0.0f && refAmbiante<1.0f){
		mReflexionAmbiante=refAmbiante;
		mMaterialAllScenes.mAmbient[0] = mReflexionAmbiante;
		mMaterialAllScenes.mAmbient[1] = mReflexionAmbiante;
		mMaterialAllScenes.mAmbient[2] = mReflexionAmbiante;
		RenderingModel::ApplyMaterial(mMaterialAllScenes);
	}
}

void Modele::clear(){
	for (auto it = mSceneList.begin() ; it != mSceneList.end(); ++it) {
		delete (*it);
	}
	mSceneList.clear();
}
