#ifndef HEADER_LOOKATCAMERA_HPP
#define HEADER_LOOKATCAMERA_HPP

#include "abstractCamera.hpp"

class LookAtCamera : public AbstractCamera {
	public:
		LookAtCamera(	double px, double py, double pz,
				double vx, double vy, double vz,
				double vertx, double verty, double vertz,
				double zproche = 1, double zeloigne = 500,
				double angleOuverture = 50);
		virtual ~LookAtCamera();

		virtual void ChangerRepereCamera(	double position[3],
									double pointDeVisee[3],
									double vecteurVertical[3]);
		virtual void ChangerRepereCamera();
};



#endif
