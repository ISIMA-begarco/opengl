#ifndef NOEUD_HPP
#define NOEUD_HPP

#include <assimp/scene.h>
#include <string>

class Scene;

/**
* Classe de noeud, contenant les sous noeuds representant l'objet 3D
* Il sont lies au maillage grace a un attribut donnant un id de maillage
*/
class Noeud{
	friend Scene;

	private:
		aiNode* mNoeud;	 /// Pointeur vers le node opengl

	public:
		Noeud();
		Noeud(std::string name);
		Noeud(aiNode* noeud);
		virtual ~Noeud();

		/**
		 * @brief permet de trouver un noeud en fonction de son nom
		 */
		Noeud findNode(std::string name);
};

#endif
