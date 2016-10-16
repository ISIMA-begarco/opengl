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

class Voiture : public AbstractScene {
	private:
		double mVitesseRoue;
		int mStep;
		const int maxStep;

	public:
		Voiture(double vitesseRoue = 0.1): mVitesseRoue(vitesseRoue), mStep(0), maxStep((int)(360.0/vitesseRoue)) {}
		~Voiture() {}
			
		void drawRoue(){
			glPushMatrix();
				GeometricTransform::Rotate(0, 1, 0, 90);
				GeometricTransform::Rotate(0, 0, 1, mStep * mVitesseRoue);
				gluCylinder(gluNewQuadric(),
				 	5,	//base,
				 	5,  	//top,
				 	0.5, 	//height,
				 	12, 	//slices,
				 	12  	//stacks
				 );
			glPopMatrix();
		}		
		
		void drawEssieu(double longueur){
			glPushMatrix();
				GeometricTransform::Translate(-longueur/2, 0, 0);
				GeometricTransform::Rotate(0, 1, 0, 90);
				gluCylinder(gluNewQuadric(),
				 	0.5,		//base,
				 	0.5,  	//top,
				 	longueur, 	//height,
				 	8, 	//slices,
				 	8  	//stacks
				 );
			glPopMatrix();
			
			// Roue gauche
			glPushMatrix();
				GeometricTransform::Translate(longueur/2, 0, 0);
				drawRoue();
			glPopMatrix();
			
			// Roue droite
			glPushMatrix();
				GeometricTransform::Translate(-longueur/2, 0, 0);
				drawRoue();
			glPopMatrix();
		}		
		
		void drawCorps(){
			// Gros bloc
			glPushMatrix();
				GeometricTransform::Scale(1,1,3);
				glutWireCube(10);
			glPopMatrix();
			
			// Petit bloc
			glPushMatrix();
				GeometricTransform::Translate(0, 8, -3);
				GeometricTransform::Scale(1,1,2);
				glutWireCube(8);
			glPopMatrix();
			
			// Essieu arriere
			glPushMatrix();
				GeometricTransform::Translate(0, -5, -12);
				drawEssieu(12);
			glPopMatrix();
			
			// Essieu avant
			glPushMatrix();
				GeometricTransform::Translate(0, -5, 12);
				drawEssieu(12);
			glPopMatrix();
			
		}

		void render(){	
			drawCorps();

			mStep = (mStep+1) % maxStep;
		}
};

#endif
