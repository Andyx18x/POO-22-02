#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

using namespace std;
using namespace sf;

class Object {
public:
	Object();
	void Draw(RenderWindow &window);
	bool Colisiona(const Object &o) const;
	
	
	
protected:
	CircleShape m_ball;
	RectangleShape m_player;
	RectangleShape b_shape;
};

#endif

