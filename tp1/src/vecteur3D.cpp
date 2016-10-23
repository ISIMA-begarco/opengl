/**
 * @file vecteur3D.cpp
 * @brief Classe de vecteur en trois dimensions
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#include "vecteur3D.hpp"


Vecteur3D::Vecteur3D(aiVector3D* vector):
mVecteur3D(vector)
{}

Vecteur3D::Vecteur3D(float x, float y, float z):
	mVecteur3D(new aiVector3D(x,y,z))
{}

Vecteur3D::Vecteur3D(const Vecteur3D &vec)
{
	this->mVecteur3D = new aiVector3D(vec.GetX(),vec.GetY(),vec.GetZ());
}

Vecteur3D::~Vecteur3D(){
	//delete this->mVecteur3D;
}

Vecteur3D Vecteur3D::Normalize() const {
	aiVector3D n = mVecteur3D->Normalize();
    return Vecteur3D(n.x, n.y, n.z);
}

Vecteur3D Vecteur3D::Cross(Vecteur3D v) const {
    return Vecteur3D(	this->GetY()*v.GetZ() - this->GetZ()*v.GetY(),
						this->GetZ()*v.GetX() - this->GetX()*v.GetZ(),
						this->GetX()*v.GetY() - this->GetY()*v.GetX());
}

float Vecteur3D::Dot(Vecteur3D & vec) const {
    return this->GetX()*vec.GetX() + this->GetY()*vec.GetY() + this->GetZ()*vec.GetZ();
}

float Vecteur3D::GetX() const {
	return mVecteur3D->x;
}

float Vecteur3D::GetY() const {
	return mVecteur3D->y;
}

float Vecteur3D::GetZ() const {
	return mVecteur3D->z;
}

void Vecteur3D::SetX(float newX) {
	mVecteur3D->x = newX;
}

void Vecteur3D::SetY(float newY) {
	mVecteur3D->y = newY;
}

void Vecteur3D::SetZ(float newZ) {
	mVecteur3D->z = newZ;
}
