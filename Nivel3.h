#ifndef NIVEL3_H
#define NIVEL3_H
#include "Player.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include "Nivel.h"


class Nivel3 : public Nivel{
public:
	Nivel3();
	void Draw(RenderWindow &w) override;
	void Update(Game &g) override;
	
private:
};

#endif

