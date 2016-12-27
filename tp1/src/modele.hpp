/**
 * @file modele.hpp
 * @brief Classe du modèle de MVC
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_MODELE_HPP
#define HEADER_MODELE_HPP

#include <string>
#include <vector>

#include "scene.hpp"
#include "abstractScene.hpp"
#include "computedScene.hpp"
#include "./sourceShading/renderingModel.hpp"

/**
 * Modèle de données
 */
class Modele{
	public:
		/// Niveau de gris du fond
		float mNiveauGris;
		/// Liste des scènes du modèle
		std::vector<AbstractScene *> mSceneList;

		/// Taux de brillance des scènes
		float mBrillance;
		/// Taux de réflexion ambiante
		float mReflexionAmbiante;
		/// Matériel commun à toute la scène
		Material mMaterialAllScenes;


		/** @brief constructeur par défaut
		* Initialise les données nécessaires à l'affichage. */
		Modele();

		/** Mise à jour du modèle appelée à chaque événement timer */
		void Update();

		/** @brief Ajout d'une théière au modèle
		  * @param Taille de la théière
		  * @return void
		  */
		void addTeapot(int size);
		/** @brief Ajout d'un Système solaire au modèle
		  * @param Taille du Soleil
		  * @return void
		  */
		void addSystemeSolaire(int sizeSun);
		/** @brief Ajout d'une voiture
		  * @param Vitesse des roues
		  * @return void
		  */
		void addVoiture(double vitesse);
		/** @brief Ajout d'un cylindre
		  * @param rayon du cylindre
			* @param hauteur du cylindre
			* @param nombre de meridiens
			*/
		void addCylindre(double pRayon, double pHauteur, int pNbMeridien);
		/** @brief Ajout d'une scène chargée
		  * @param Chemin vers le fichier
		  * @return void
		  */
		void addScene(std::string path);

		/** @brief Effectue le rendu d'une scène
		  * @param Numéro de la scène à rendre
		  * @return void
		  */
		void render(int i);
		/** @brief Effectue le rendu de toutes les scènes
		  * @param void
		  * @return void
		  */
		void renderAll();

		/** @brief Change la brillance d'une scène
		  * @param Nouvelle brillance
		  * @return void
		  */
		void changeBrillance(float brillance);

		/** @brief Change la reflexion ambiante d'une scène
		  * @param Nouvelle reflexion ambiante
		  * @return void
		  */
		void changeRefAmbiante(float refAmbiante);

		/** @brief Nettoie les scènes
		  * @param void
		  * @return void
		  */
		void clear();
};
#endif
