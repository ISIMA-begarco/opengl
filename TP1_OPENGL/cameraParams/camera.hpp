#ifndef HEADER_CAMERA_HPP
#define HEADER_CAMERA_HPP

class Camera{

    double mAngleOuvertureY;
    double mAspect;
    double mZ_proche;
    double mZ_eloigne;

	double mPosition[3];
	double mVisee[3];
	double mVertical[3];
	
	public:
        Camera(double angleOuvertureY, double aspect, double z_proche, double z_eloigne,
                double px, double py, double pz,
					double vx, double vy, double vz,
                    double vertx, double verty, double vertz);
/*

        static void Viewport(int32_t viewCenterX,  int32_t viewCenterY,
                 uint32_t viewWidth, uint32_t viewHeight){
          glViewport(viewCenterX, viewCenterY, viewWidth, viewHeight);
        }*/

        /** Applique la nouvelle projection en perspectives sur les primitives graphiques
          * Seuls les objets affichés ultérieurement sont affectés */
        void ApplyPerspectiveProjection(double angleOuvertureY, double aspect,
                                        double zProche, double zEloigne);

        void SetProjection(double angleOuvertureY, double aspect, double z_proche, double z_eloigne);

        void LookAt(double position[3], double pointDeVisee[3], double vecteurVertical[3]);

        /** Réinitialise la transformation Projection à l'identité */
        static void ClearProjection();



};



#endif
