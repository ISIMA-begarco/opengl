#ifndef HEADER_CAMERA_HPP
#define HEADER_CAMERA_HPP

#include "../cameraParams/transform.hpp"

class Camera {
public:
	double mPosition[3];
	double mVisee[3];
	double mVertical[3];
    double mZ_proche;
    double mZ_eloigne;
    double mAngleOuverture;

    Camera(	double px, double py, double pz,
                double vx, double vy, double vz,
                double vertx, double verty, double vertz,
                double zproche = 10, double zeloigne = 100,
                double angleOuverture = 50);
    void Redimensionnement();
    void LookAt(double position[3], double pointDeVisee[3], double vecteurVertical[3]);
};



#endif
