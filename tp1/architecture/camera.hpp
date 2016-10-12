#ifndef HEADER_CAMERA_HPP
#define HEADER_CAMERA_HPP

#include <iostream>

#include "../cameraParams/transform.hpp"

class Camera {
public:
	double mPosition[3];
	double mVisee[3];
	double mVertical[3];
    double mZ_proche;
    double mZ_eloigne;
    double mAngleOuverture;
    double mAspect;

    Camera(	double px, double py, double pz,
                double vx, double vy, double vz,
                double vertx, double verty, double vertz,
                double zproche = 1, double zeloigne = 500,
                double angleOuverture = 50);
    void Redimensionnement(int w, int h);
    void ChangementAngle(double angleOuvertureY);
    void ApplyPerspectiveProjection(double angleOuvertureY, double aspect, double zProche, double zEloigne);
    void LookAt(double position[3], double pointDeVisee[3], double vecteurVertical[3]);
    void LookAt();
    void Zoumage(bool forward);
    
	void setPostion(double px,  double py, double pz){
		this->mPosition[0] = px;
		this->mPosition[1] = py;
		this->mPosition[2] = pz;
	}
    
	void setVisee(double vx, double vy, double vz){
		this->mVisee[0] = vx;
		this->mVisee[1] = vy;
		this->mVisee[2] = vz;
	}
    
	void setVertical(double vertx, double verty, double vertz){
		this->mVertical[0] = vertx;
		this->mVertical[1] = verty;
		this->mVertical[2] = vertz; 
	}
	
	double* getPositon(){
		return this->mPosition;
	}
	
	double* getVisee(){
		return this->mPosition;
	}
	
	double* getVertical(){
		return this->mPosition;
	}
    
};



#endif
