/**
 * @file lookAtCamera.hpp
 * @brief Classe de caméra utilisant gluLookAt
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_LOOKATCAMERA_HPP
#define HEADER_LOOKATCAMERA_HPP

#include "abstractCamera.hpp"

/**
  * @brief Classe de caméra utilisant gluLookAt
  * Classe de caméra utilisant gluLookAt et héritant de AbstractCamera
  */
class LookAtCamera : public AbstractCamera {
	public:
		/** Constructeur */
		LookAtCamera(	double px, double py, double pz,
				double vx, double vy, double vz,
				double vertx, double verty, double vertz,
				double zproche = 1, double zeloigne = 500,
				double angleOuverture = 50);
		/** Destructeur par défaut */
		virtual ~LookAtCamera();
		/** @brief Changement du repère de la caméra
		  * @param double[] position de la caméra
  		  * @param double[] point de visée de la caméra
  		  * @param double[] vertical de la caméra
		  * @return void
		  */
		virtual void ChangerRepereCamera(	double position[3],
									double pointDeVisee[3],
									double vecteurVertical[3]);
		/** @brief Changement du repère de la caméra
		  * @param void
		  * @return void
		  */
		virtual void ChangerRepereCamera();
};



#endif
