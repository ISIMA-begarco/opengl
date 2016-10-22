#ifndef NOEUD_HPP
#define NOEUD_HPP

#include <assimp/scene.h>
#include <string>

class Scene;

class Noeud{
	friend Scene;

	private:
		aiNode* mNoeud;

	public:
		Noeud();
		Noeud(std::string name);
		Noeud(aiNode* noeud);
		virtual ~Noeud();

		Noeud findNode(std::string name);
};

#endif
