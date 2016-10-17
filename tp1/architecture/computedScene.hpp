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
	
		void render();
};

class Voiture : public AbstractScene {
	private:
		double mVitesseRoue;
		int mStep;
		const int maxStep;

	public:
		Voiture(double vitesseRoue = 0.1): mVitesseRoue(vitesseRoue), mStep(0), maxStep((int)(360.0/vitesseRoue)) {}
		~Voiture() {}
			
		void drawRoue();
		void drawEssieu(double longueur);
		void drawCorps();

		void render();
};

#endif
