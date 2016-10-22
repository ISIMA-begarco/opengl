#ifndef HEADER_SCENE_HPP
#define HEADER_SCENE_HPP

#include <string>
#include <iostream>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <GL/glut.h>

#include "abstractScene.hpp"
#include "vecteur3D.hpp"
#include "noeud.hpp"

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)

class Scene : public AbstractScene {

	private :

		const aiScene* mScene;
		aiVector3D* mSceneMin;
		aiVector3D* mSceneMax; 
		aiVector3D* mCenter;
		
		void getBoundindBoxForNode (const aiNode* nd, aiMatrix4x4* trafo);
		void getBoundindBox ();
		
		void recursiveRender (const aiNode* nd);
		
	public:

		Scene(const std::string path);
		virtual ~Scene();
		
		void render ();
		void render (Noeud noeud);
		Noeud getRacine();
		
		Vecteur3D getCenter(){
			return Vecteur3D(mCenter);
		}
};

#endif
