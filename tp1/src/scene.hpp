/**
 * @file scene.hpp
 * @brief Scene chargee par fichier
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */


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
#include "maillage.hpp"

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)

/**
 * Scene chargee par fichier
 */
class Scene : public AbstractScene {

	private:
		const bool mReshape;
		const aiScene* mScene;	/// Pointeur vers la scene opengl
		aiVector3D* mSceneMin;	/// Pointeur vers la position (opengl) min de la scene
		aiVector3D* mSceneMax; 	/// Pointeur vers la position (opengl) max de la scene
		aiVector3D* mCenter;		/// Pointeur vers la position (opengl) centre de la scene
		
		const std::string mPathTexture;


		/**
		 * @brief recupere les enfants d'un noeud precis (fonction recursive)
		 * @param nd Noeud ou chercher les enfants
		 * @param matrice 4x4 pour transformation
		 */
		void getBoundindBoxForNode (const aiNode* nd, aiMatrix4x4* trafo);

		/**
		 * @brief Recupere les noeuds charges
		 */
		void getBoundindBox ();

		/**
		 * @brief Affiche les points du noeud de maniere recursive
		 * @param nd Noeud ou commencer l'affichage
		 */
		void recursiveRender (const aiNode* nd);


		void color4_to_float4(const aiColor4D *c, float f[4]);
		void set_float4(float f[4], float a, float b, float c, float d);

		void apply_material(const aiMaterial *mtl);

	public:

		Scene(const std::string path, const std::string texture, bool reshape = false);
		virtual ~Scene();

		void render ();
		void render (Noeud noeud);
		
		void center();

		/**
		 * @brief Recupere le noeud mere de la scene
		 * @return le Noeud mere
		 */
		Noeud getRacine();

		/**
		 * @brief Renvoie le center de la scene
		 */
		Vecteur3D getCenter(){
			return Vecteur3D(mCenter);
		}

		/**
		 * @brief Renvoie la liste des vertices de la scene
		 */
		std::vector<Vecteur3D> getVertices();

		/**
		 * @brief Revoie la liste des normales de la scene
		 */
		std::vector<Vecteur3D> getNormals();
};

#endif
