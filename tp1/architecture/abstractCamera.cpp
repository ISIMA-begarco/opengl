#include "abstractCamera.hpp"
#include "../cameraParams/transform.hpp"


AbstractCamera::~AbstractCamera() {

}

void AbstractCamera::Redimensionnement(int l, int h) {
	this->mAspect = (double)l/(double)h; /*aspect*/
    this->ApplyPerspectiveProjection(this->mAngleOuverture, this->mAspect, this->mZ_proche, this->mZ_eloigne);
}

void AbstractCamera::ChangementAngle(double angleOuvertureY){
	this->mAngleOuverture = angleOuvertureY;
	this->ApplyPerspectiveProjection(angleOuvertureY, this->mAspect, this->mZ_proche, this->mZ_eloigne);
}

void AbstractCamera::ApplyPerspectiveProjection(double angleOuvertureY, double aspect,
					 double zProche, double zEloigne) {
 	GeometricTransform::ClearProjection();
    GeometricTransform::ApplyPerspectiveProjection(angleOuvertureY, aspect, zProche, zEloigne);
}

void AbstractCamera::Zoumage(bool forward) {
	int i;
	if(forward) {
		for(i=0;i<3;i++) {
			this->mPosition[i] = this->mVisee[i] + 1.1 * (this->mPosition[i] - this->mVisee[i]);
		}
	} else {
		for(i=0;i<3;i++) {
			this->mPosition[i] = ((this->mPosition[i] - this->mVisee[i]) / 1.1) + this->mVisee[i];
		}
	}
}

void AbstractCamera::setPostion(double px,  double py, double pz){
	this->mPosition[0] = px;
	this->mPosition[1] = py;
	this->mPosition[2] = pz;
}
 
void AbstractCamera::setVisee(double vx, double vy, double vz){
	this->mVisee[0] = vx;
	this->mVisee[1] = vy;
	this->mVisee[2] = vz;
}
 
void AbstractCamera::setVertical(double vertx, double verty, double vertz){
	this->mVertical[0] = vertx;
	this->mVertical[1] = verty;
	this->mVertical[2] = vertz; 
}

double* AbstractCamera::getPositon(){
	return this->mPosition;
}

double* AbstractCamera::getVisee(){
	return this->mPosition;
}

double* AbstractCamera::getVertical(){
	return this->mPosition;
}
