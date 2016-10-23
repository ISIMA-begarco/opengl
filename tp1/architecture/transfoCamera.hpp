/**
 * @file transfoCamera.hpp
 * @brief Classe de caméra utilisant des transformations
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_TRANSFOCAMERA_HPP
#define HEADER_TRANSFOCAMERA_HPP

#include "abstractCamera.hpp"


class TransfoCamera : public AbstractCamera
{
    public:
        /** 'Default' constructor */
        TransfoCamera(	double px, double py, double pz,
				double vx, double vy, double vz,
				double vertx, double verty, double vertz,
				double zproche = 1, double zeloigne = 500,
				double angleOuverture = 50);
        /** Default destructor */
        virtual ~TransfoCamera();
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

#endif // HEADER_TRANSFOCAMERA_HPP
