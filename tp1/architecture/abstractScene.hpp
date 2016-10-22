#ifndef ABSTRACT_SCENE_HPP
#define ABSTRACT_SCENE_HPP

class AbstractScene {
    protected:
        double mPosition[3];
        double mVisee[3];
        double mVertical[3];
        double mZ_proche;
        double mZ_eloigne;
        double mAngleOuverture;
        double mAspect;
	public:
		virtual ~AbstractScene() {}
		virtual void render() = 0;
};

#endif
