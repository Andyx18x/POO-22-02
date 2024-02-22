#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window/Keyboard.hpp>
#include "Object.h"
#include <SFML/Graphics/Rect.hpp>
using namespace sf;

class Player : public Object{
public:
	Player();
	void Update();
	void LimitesPlayer();
	FloatRect DimensionesPlayer();
private:
};

#endif

