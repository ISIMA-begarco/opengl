#include "transfoCamera.hpp"
#include "../cameraParams/transform.hpp"
#include "vecteur3D.hpp"
#include <iostream>
#include <cstring>
#include <cmath>

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

void TransfoCamera::ChangerRepereCamera(	double pposition[3],
                            double ppointDeVisee[3],
                            double pvecteurVertical[3]) {
	memcpy( mPosition ,  pposition ,  3*sizeof( double ) ) ;
	memcpy( mVisee ,  ppointDeVisee ,  3*sizeof ( double ) ) ;
	memcpy( mVertical ,  pvecteurVertical ,  3*sizeof ( double ) ) ;

	Vecteur3D position(pposition[0],pposition[1],pposition[2]);
	Vecteur3D pointDeVisee(ppointDeVisee[0],ppointDeVisee[1],ppointDeVisee[2]);
	Vecteur3D direction(ppointDeVisee[0]-pposition[0],ppointDeVisee[1]-pposition[1],ppointDeVisee[2]-pposition[2]);
	Vecteur3D vecteurVertical(pvecteurVertical[0],pvecteurVertical[1],pvecteurVertical[2]);

	Vecteur3D dirNorm;
	Vecteur3D vertiNorm;
	Vecteur3D vecNorm;

	dirNorm = direction;
	dirNorm.Normalize();

	vertiNorm = vecteurVertical;
	vertiNorm.Normalize();

	vecNorm = dirNorm.Cross(vertiNorm);
	vecNorm.Normalize();

	vertiNorm = vecNorm.Cross(dirNorm);
	vertiNorm.Normalize();

    float mat[16];
	mat[ 0] = vecNorm.GetX();
	mat[ 1] = vertiNorm.GetX();
	mat[ 2] = -dirNorm.GetX();
	mat[ 3] = 0.0;

	mat[ 4] = vecNorm.GetY();
	mat[ 5] = vertiNorm.GetY();
	mat[ 6] = -dirNorm.GetY();
	mat[ 7] = 0.0;

	mat[ 8] = vecNorm.GetZ();
	mat[ 9] = vertiNorm.GetZ();
	mat[10] = -dirNorm.GetZ();
	mat[11] = 0.0;

	mat[12] = -(vecNorm.Dot(position));
	mat[13] = -(vertiNorm.Dot(position));
	mat[14] = (dirNorm.Dot(position));
	mat[15] = 1.0;

    glMultMatrixf(&mat[0]);

/*
	double 	dirX = mVisee[0]-mPosition[0],
			dirY = mVisee[1]-mPosition[1],
			dirZ = mVisee[2]-mPosition[2];

	double elevation = acos(sqrt(dirX*dirX+dirZ*dirZ)/sqrt(dirX*dirX+dirY*dirY+dirZ*dirZ)) * 360 / 6.28;
	//double roll = 0.0;
	double azimuth = atan2(dirZ, dirX) * 360 / 6.28;

	//    glMatrixMode(GL_MODELVIEW);
	GeometricTransform::Rotate(0,1,0, -azimuth);
	GeometricTransform::Rotate(1,0,0, -elevation);
	GeometricTransform::Rotate(0,0,1, -azimuth);
	GeometricTransform::Translate(-mPosition[0], -mPosition[1], -mPosition[2]);*/
}

void TransfoCamera::ChangerRepereCamera() {
    ChangerRepereCamera(this->mPosition, this->mVisee, this->mVertical);
}
