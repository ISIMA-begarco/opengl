/**
 * @file abstractCamera.hpp
 * @brief Classe abstraite de caméra
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_ABSTRACT_CAMERA_HPP
#define HEADER_ABSTRACT_CAMERA_HPP

/**
  *	@brief Classe de caméra abstraite
  * Classe de caméra abstraite
  */
class AbstractCamera {

	protected:
		/// Position de la caméra
		double mPosition[3];
		/// Point de visée de la caméra
		double mVisee[3];
		/// Vecteur vertical de la caméra
		double mVertical[3];
		/// Distance du plan proche
		double mZ_proche;
		/// Distance du plan éloigné
		double mZ_eloigne;
		/// Angle d'ouverture de la caméra
		double mAngleOuverture;
		/// Aspect de la caméra
		double mAspect;

	public:
		/** Types de repères supportés ( repères du monde et de l a camé ra ) */
		enum TypeRepere{
			MONDE = 0 , CAMERA = 1
		};

		/** Constructeur */
		AbstractCamera(	double px, double py, double pz,
					double vx, double vy, double vz,
					double vertx, double verty, double vertz,
					double zproche = 1, double zeloigne = 500,
					double angleOuverture = 50);
		/** Destructeur */
		virtual ~AbstractCamera();

		/** @brief Redimensionnement de la fenêtre
		  * @param Largeur de la fenêtre
		  * @param Hauteur de la fenêtre
		  */
		void Redimensionnement(int w, int h);
		/** @brief Changement de l'angle d'ouverture
		  * @param float : angle
		  */
		void ChangementAngle(double angleOuvertureY);
		/** @brief Application de la projection
		  * @param double
  		  * @param double
  		  * @param double
  		  * @param double
		  * @return void
		  */
		void ApplyPerspectiveProjection(double angleOuvertureY, double aspect, double zProche, double zEloigne);
		/** @brief Changement du repère de la caméra
		  * @param double[] position de la caméra
  		  * @param double[] point de visée de la caméra
  		  * @param double[] vertical de la caméra
		  * @return void
		  */
		virtual void ChangerRepereCamera(double position[3], double pointDeVisee[3], double vecteurVertical[3]) = 0;
		/** @brief Changement du repère de la caméra
		  * @return void
		  */
		virtual void ChangerRepereCamera() = 0;
		/** @brief Zoom de la caméra
		  * @param true : avancer
		  * @return void
		  */
		void Zoumage(bool forward);
		/** @brief Setter de la position
		  * @param Nouvelle position
		  * @return void
		  */
		void setPostion(double px,  double py, double pz);
		/** @brief Setter de la visée
		  * @param Nouvelle position
		  * @return void
		  */
		void setVisee(double vx, double vy, double vz);
		/** @brief Setter de la verticale
		  * @param Nouvelle position
		  * @return void
		  */
		void setVertical(double vertx, double verty, double vertz);
		/** @brief Setter de l'angle d'ouverture
		  * @param Nouvel angle
		  * @return void
		  */
		void setAngleOuverture(double a);
		/** @brief Getter de la position
		  * @param void
		  * @return position
		  */
		double* getPosition();
		/** @brief Getter de la visée
		  * @param void
		  * @return visée
		  */
		double* getVisee();
		/** @brief Getter de la verticale
		  * @param void
		  * @return verticale
		  */
		double* getVertical();
		/** @brief Getter de l'angle d'ouverture
		  * @param void
		  * @return angle d'ouverture
		  */
		double getAngleOuverture() const;
};


#endif
