#include "modele.hpp"

Modele::Modele() : mNiveauGris(0.0f), mSceneList() {
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

void Modele::addScene(std::string path){
	this->mSceneList.push_back(new Scene(path));
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

void Modele::clear(){
	for (auto it = mSceneList.begin() ; it != mSceneList.end(); ++it) {
		delete (*it);
	} 
	mSceneList.clear();
}
