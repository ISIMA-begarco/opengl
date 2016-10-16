#include "camera.hpp"

Camera::Camera(double px, double py, double pz,
					double vx, double vy, double vz,
                    double vertx, double verty, double vertz,
                    double zproche, double zeloigne,
                    double angleOuverture):
    mZ_proche(zproche), mZ_eloigne(zeloigne), mAngleOuverture(angleOuverture), mAspect(0) {
	this->mPosition[0] = px;
	this->mPosition[1] = py;
	this->mPosition[2] = pz;
	this->mVisee[0] = vx;
	this->mVisee[1] = vy;
	this->mVisee[2] = vz;
	this->mVertical[0] = vertx;
	this->mVertical[1] = verty;
   this->mVertical[2] = vertz;
}

void Camera::Redimensionnement(int l, int h) {
	this->mAspect = (double)l/(double)h; /*aspect*/
    this->ApplyPerspectiveProjection(this->mAngleOuverture, this->mAspect, this->mZ_proche, this->mZ_eloigne);
}

void Camera::ChangementAngle(double angleOuvertureY){
	this->mAngleOuverture = angleOuvertureY;
	this->ApplyPerspectiveProjection(angleOuvertureY, this->mAspect, this->mZ_proche, this->mZ_eloigne);
}

void Camera::ApplyPerspectiveProjection(double angleOuvertureY, double aspect,
					 double zProche, double zEloigne) {
 	GeometricTransform::ClearProjection();
    GeometricTransform::ApplyPerspectiveProjection(angleOuvertureY, aspect, zProche, zEloigne);
}


void Camera::LookAt(double position[3], double pointDeVisee[3], double vecteurVertical[3]){
   memcpy( mPosition ,  position ,  3*sizeof( GLdouble ) ) ;
   memcpy( mVisee ,  pointDeVisee ,  3*sizeof ( GLdouble ) ) ;
   memcpy( mVertical ,  vecteurVertical ,  3*sizeof ( GLdouble ) ) ;
	
	GeometricTransform::ClearModelView();
	GeometricTransform::LookAt(position,pointDeVisee,vecteurVertical);
}

void Camera::LookAt(){
	LookAt(this->mPosition, this->mVisee, this->mVertical);
}

void Camera::Zoumage(bool forward){
	int i;
	if(forward){
		for(i=0;i<3;i++){
			this->mPosition[i] = this->mVisee[i] + 1.1 * (this->mPosition[i] - this->mVisee[i]);
		}
	}else{
		for(i=0;i<3;i++){
			this->mPosition[i] = ((this->mPosition[i] - this->mVisee[i]) / 1.1) + this->mVisee[i];
		}
	}
}
