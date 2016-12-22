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
    protected:
        double mAzimuth;
        double mElevation;

    public:
        /** 'Default' constructor */
        TransfoCamera(	double px, double py, double pz,
				double vx, double vy, double vz,
				double vertx, double verty, double vertz,
				double zproche = 1, double zeloigne = 500,
				double angleOuverture = 50, double azimuth = 0.0, double elevation = 0.0);
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

        /** @brief Setter de l'angle azimuth
        * @param double : nouvel angle
        * @return void
        */
        void SetAzimuth(double a);
        /** @brief Setter de l'angle d'élévation
        * @param double : nouvel angle
        * @return void
        */
        void SetElevation(double e);
        /** @brief Getter de l'angle azimuth
        * @param void
        * @return double
        */
        double GetAzimuth(void) const;
        /** @brief Getter de l'angle d'élévation
        * @param void
        * @return double
        */
        double GetElevation(void) const;
};

#endif // HEADER_TRANSFOCAMERA_HPP
