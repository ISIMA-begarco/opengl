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
	double* getPositon();
	double* getVisee();	
	double* getVertical();
};


#endif
