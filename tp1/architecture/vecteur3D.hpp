#ifndef VECTEUR3D_HPP
#define VECTEUR3D_HPP

#include <assimp/scene.h>

class Scene;
class Maillage;

class Vecteur3D {
	friend Scene;
	friend Maillage;

	private :
		aiVector3D* mVecteur3D;
		Vecteur3D(aiVector3D*);

	public:
		Vecteur3D(float x=0.0, float y=0.0, float z=0.0);
		Vecteur3D(const Vecteur3D &vec);
		virtual ~Vecteur3D();

		float GetX() const;
		float GetY() const;
		float GetZ() const;
		void SetX(float);
		void SetY(float);
		void SetZ(float);

		Vecteur3D Normalize() const;
		Vecteur3D Cross(Vecteur3D v) const;
		float Dot(Vecteur3D & v) const;
};

#endif
