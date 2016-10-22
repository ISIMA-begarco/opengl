#include "maillage.hpp"

Maillage::Maillage():
mMaillage(new aiMesh())
{}


Maillage::Maillage(aiMesh* noeud):
mMaillage(noeud)
{}

Maillage::~Maillage(){
	//delete mNoeud;
}

std::vector<Vecteur3D> Maillage::getVertices(){
  std::vector<Vecteur3D> vertices;
  for(unsigned i=0; i<mMaillage->mNumVertices ;i++){
    vertices.push_back(Vecteur3D(mMaillage->mVertices+i));
  }
  return vertices;
}

std::vector<Vecteur3D>  Maillage::getNormals(){
  std::vector<Vecteur3D> normals;
  for(unsigned i=0; i<mMaillage->mNumVertices ;i++){
    normals.push_back(Vecteur3D(mMaillage->mNormals+i));
  }
  return normals;
}
