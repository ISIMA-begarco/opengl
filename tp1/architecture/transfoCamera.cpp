#include "transfoCamera.hpp"

TransfoCamera::TransfoCamera(double px, double py, double pz,
					double vx, double vy, double vz,
					double vertx, double verty, double vertz,
					double zproche, double zeloigne,
					double angleOuverture): AbstractCamera(	px,py,pz,vx,vy,vz,vertx,verty,vertz,
															zproche,zeloigne,angleOuverture) {
}

TransfoCamera::~TransfoCamera()
{
    //dtor
}

void TransfoCamera::ChangerRepereCamera(	double position[3],
                            double pointDeVisee[3],
                            double vecteurVertical[3]) {
    double what = position[0] + pointDeVisee[0] + vecteurVertical[0];
    if(what >= 0.0)
    what++;
    else
    what--;
}

void TransfoCamera::ChangerRepereCamera() {
    ChangerRepereCamera(this->mPosition, this->mVisee, this->mVertical);
}
