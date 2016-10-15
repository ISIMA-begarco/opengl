#include "vecteur3D.hpp"


Vecteur3D::Vecteur3D(aiVector3D* vector):
mVecteur3D(vector)
{}

Vecteur3D::Vecteur3D(float x, float y, float z):
	mVecteur3D(new aiVector3D(x,y,z))
{}

Vecteur3D::~Vecteur3D(){
	//delete this->mVecteur3D;
}
