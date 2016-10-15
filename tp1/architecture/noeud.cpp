#include "noeud.hpp"

Noeud::Noeud():
mNoeud(new aiNode())
{}

Noeud::Noeud(std::string name):
mNoeud(new aiNode(name))
{}

Noeud::Noeud(aiNode* noeud):
mNoeud(noeud)
{}

Noeud::~Noeud(){
	//delete mNoeud;
}

Noeud Noeud::findNode(std::string name){
	return Noeud(this->mNoeud->FindNode(name.c_str()));
}
