#ifndef ABSTRACT_SCENE_HPP
#define ABSTRACT_SCENE_HPP

class AbstractScene {
	public:
		virtual ~AbstractScene() {}
		virtual void render() = 0;
};

#endif
