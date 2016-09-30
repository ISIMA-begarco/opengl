#include camera.hpp

Camera::Camera(double px, double py, double pz,
					double vx, double vy, double vz,
					double vertx, double verty, double vertz) {
	this->mPosition[0] = px;
	this->mPosition[1] = py;
	this->mPosition[2] = pz;
	this->mVisee[0] = vx;
	this->mVisee[1] = vy;
	this->mVisee[2] = vz;
	this->mVertical[0] = vertx;
	this->mVertical[1] = verty;
	this->mVertical[2] = vertz;
}
