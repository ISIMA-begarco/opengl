#ifndef COMPUTED_SCENE_HPP
#define COMPUTED_SCENE_HPP

#include "abstractScene.hpp"
#include "../cameraParams/transform.hpp"

#include <iostream>
#include <cmath>

class Teapot : public AbstractScene {
	private:
		int mSize;
		
	public:
		Teapot(int size): mSize(size){}
		~Teapot() {}
	
		void render(){
		 	glutSolidTeapot(this->mSize);
		}
};

class SystemeSolaire : public AbstractScene {
	private:
		const int mRayonSoleil;
		const double inc;
		double mRevolutionSelf;
		double mRevolutionSun;
		
	public:
		SystemeSolaire(int rayonSoleil): mRayonSoleil(rayonSoleil), inc(0.2), mRevolutionSelf(0.0), mRevolutionSun(0.0) {}
		~SystemeSolaire() {}
	
		void render(){	
			// Soleil
		 	glutSolidSphere(mRayonSoleil, 15, 15);
		 	
			// Planete
			// Rotation superieur
			GeometricTransform::Rotate(0, 1, 0, mRevolutionSun);
			
			// Translation de la petite planete
			GeometricTransform::Translate(-mRayonSoleil*3, 0, 0);
			
			// Rotation de la planete meme
			GeometricTransform::Rotate(0, 1, 0, mRevolutionSelf);
			
			// Affichafe de la planete
			glutSolidSphere(mRayonSoleil/2, 10, 10);

        	// Update
        	mRevolutionSelf=fmod((mRevolutionSelf+inc*4),360.0);
        	mRevolutionSun=fmod((mRevolutionSun+inc),360.0);
		}
};

#endif
