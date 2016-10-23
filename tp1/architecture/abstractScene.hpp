#ifndef ABSTRACT_SCENE_HPP
#define ABSTRACT_SCENE_HPP

/**
* Classe mere des types de scenes disponibles
*/
class AbstractScene {
	public:
		virtual ~AbstractScene() {}

    /**
    * @brief Affiche la scene courante
    */
		virtual void render() = 0;
};

#endif
