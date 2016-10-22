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
		Vecteur3D(float x, float y, float z);
		virtual ~Vecteur3D();
};

#endif
