#include "camera.hpp"
#include "transform.hpp"


Camera::Camera(double px, double py, double pz,
					double vx, double vy, double vz,
                    double vertx, double verty, double vertz)
    :mAngleOuvertureY(angleOuvertureY),
    mAspect(aspect),
    mZ_eloigne(z_eloigne),
    mZ_proche(z_proche) {

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

void Camera::SetProjection(double angleOuvertureY, double aspect, double z_proche, double z_eloigne){
    mAngleOuvertureY = angleOuvertureY;
    mAspect = aspect;
    mZ_proche = zProche;
    mZ_eloigne = zEloigne;
}

void Camera::ApplyPerspectiveProjection(){

    GeometricTransform.ApplyPerspectiveProjection(mAngleOuvertureY,mAspect,mZ_proche,mZ_eloigne);
}

void Camera::LookAt(double position[3], double pointDeVisee[3], double vecteurVertical[3]){
    mPosition = position;
    mVisee = pointDeVisee;
    mVertical = vecteurVertical;
    GeometricTransform.LookAt(position,pointDeVisee,vecteurVertical);
}

static void Camera::ClearProjection(){
    GeometricTransform.ClearProjection();
}


