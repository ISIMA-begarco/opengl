#include "camera.hpp"
#include "../cameraParams/transform.hpp"
#include <iostream>

Camera::Camera(double px, double py, double pz,
					double vx, double vy, double vz,
					double vertx, double verty, double vertz,
					double zproche, double zeloigne,
					double angleOuverture): AbstractCamera(	px,py,pz,vx,vy,vz,vertx,verty,vertz,
															zproche,zeloigne,angleOuverture) {
}

Camera::~Camera() {

}

void Camera::ChangerRepereCamera(double position[3], double pointDeVisee[3], double vecteurVertical[3]) {
	memcpy( mPosition ,  position ,  3*sizeof( GLdouble ) ) ;
	memcpy( mVisee ,  pointDeVisee ,  3*sizeof ( GLdouble ) ) ;
	memcpy( mVertical ,  vecteurVertical ,  3*sizeof ( GLdouble ) ) ;

	GeometricTransform::ClearModelView();
	GeometricTransform::LookAt(position,pointDeVisee,vecteurVertical);
}

void Camera::ChangerRepereCamera() {
	ChangerRepereCamera(this->mPosition, this->mVisee, this->mVertical);
}
