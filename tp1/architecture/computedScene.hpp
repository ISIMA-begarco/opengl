#ifndef COMPUTED_SCENE_HPP
#define COMPUTED_SCENE_HPP

#include "abstractScene.hpp"

class Teapot : public AbstractScene {
	private:
		int mSize;
		
	public:
		Teapot(int size): mSize(size){}
		~Teapot() {}
	
		void render(){
		 	glutSolidTeapot(this->mSize);
		}
};

#endif
