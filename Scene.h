#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics/RenderWindow.hpp>


using namespace sf;
class Game;

class Scene {
public:
	virtual void Update(Game &g) = 0;
	virtual void Draw(RenderWindow &window) = 0;
	virtual void MoveUp(){};
	virtual void MoveDown(){};
	virtual ~Scene(){};
private:
};

#endif

