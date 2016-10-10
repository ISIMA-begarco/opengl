#include "camera.hpp"

Camera::Camera(double px, double py, double pz,
					double vx, double vy, double vz,
                    double vertx, double verty, double vertz,
                    double zproche, double zeloigne,
                    double angleOuverture):
    mZ_proche(zproche), mZ_eloigne(zeloigne), mAngleOuverture(angleOuverture) {
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
    GeometricTransform::ApplyPerspectiveProjection(this->mAngleOuverture, /*aspect*/ (double)l/(double)h,
                                                  this->mZ_proche, this->mZ_eloigne);
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
