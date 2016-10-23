#ifndef HEADER_ABSTRACT_CAMERA_HPP
#define HEADER_ABSTRACT_CAMERA_HPP

class AbstractCamera {

	protected:

		double mPosition[3];
		double mVisee[3];
		double mVertical[3];
		double mZ_proche;
		double mZ_eloigne;
		double mAngleOuverture;
		double mAspect;

	public:
		/** Types de repères support é s ( repères du monde et de l a camé ra ) */
		enum TypeRepere{
			MONDE = 0 , CAMERA = 1
		};

		AbstractCamera(	double px, double py, double pz,
					double vx, double vy, double vz,
					double vertx, double verty, double vertz,
					double zproche = 1, double zeloigne = 500,
					double angleOuverture = 50);
		virtual ~AbstractCamera();

		void Redimensionnement(int w, int h);
		void ChangementAngle(double angleOuvertureY);
		void ApplyPerspectiveProjection(double angleOuvertureY, double aspect, double zProche, double zEloigne);
		virtual void ChangerRepereCamera(double position[3], double pointDeVisee[3], double vecteurVertical[3]) = 0;
		virtual void ChangerRepereCamera() = 0;
		void Zoumage(bool forward);
		void setPostion(double px,  double py, double pz);
		void setVisee(double vx, double vy, double vz);
		void setVertical(double vertx, double verty, double vertz);
		void setAngleOuverture(double a);
		double* getPosition();
		double* getVisee();
		double* getVertical();
		double getAngleOuverture() const;
};


#endif
