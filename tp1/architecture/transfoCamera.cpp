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
