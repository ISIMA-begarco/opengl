/**
 * @file vecteur3D.hpp
 * @brief Classe de vecteur en trois dimensions
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef VECTEUR3D_HPP
#define VECTEUR3D_HPP

#include <assimp/scene.h>

class Scene;
class Maillage;

/**
  *	@brief Classe pour un vecteur 3D
  * Cette classe encapsule les aiVector3D.
  */
class Vecteur3D {
	friend Scene;
	friend Maillage;

	private :
		aiVector3D* mVecteur3D;
		Vecteur3D(aiVector3D*);

	public:
		/**
		  *	@brief Constructeur
		  * @param Cooronnée x (0 par défaut)
		  * @param Cooronnée y (0 par défaut)
		  * @param Cooronnée z (0 par défaut)
		  */
		Vecteur3D(float x=0.0, float y=0.0, float z=0.0);
		/**
		  *	@brief Constructeur par copie
		  */
		Vecteur3D(const Vecteur3D &vec);
		/**
		  *	@brief Destructeur
		  */
		virtual ~Vecteur3D();

		/**
		  *	@brief Getter pour la coordonnée X
		  * @return Un float.
		  */
		float GetX() const;
		/**
		  *	@brief Getter pour la coordonnée Y
		  * @return Un float.
		  */
		float GetY() const;
		/**
		  *	@brief Getter pour la coordonnée Z
		  * @return Un float.
		  */
		float GetZ() const;
		/**
		  *	@brief Setter pour la coordonnée X
		  * @param Un float.
		  */
		void SetX(float);
		/**
		  *	@brief Setter pour la coordonnée Y
		  * @param Un float.
		  */
		void SetY(float);
		/**
		  *	@brief Setter pour la coordonnée Z
		  * @param Un float.
		  */
		void SetZ(float);


		/**
		  *	@brief Calcul le vecteur normalisé
		  * @return Un Vecteur3D contenant le vecteur normalisé.
		  */
		Vecteur3D Normalize() const;
		/**
		  *	@brief Calcul le produit vectoriel
		  * @param Un Vecteur3D pour le produit.
		  * @return Un Vecteur3D contenant le vecteur produit.
		  */
		Vecteur3D Cross(Vecteur3D v) const;
		/**
		  *	@brief Calcul le produit scalaire
		  * @param Un Vecteur3D pour le produit.
		  * @return Un float contenant le résultat.
		  */
		float Dot(Vecteur3D & v) const;
};

#endif
