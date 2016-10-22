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
    protected:
    private:
};

#endif // HEADER_TRANSFOCAMERA_HPP
