#ifndef NIVEL5_H
#define NIVEL5_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Nivel.h"
#include "Game.h"

class Nivel5 : public Nivel {
public:
	Nivel5();
	void Update(Game &g) override;
	void Draw(RenderWindow &w) override;
private:
};

#endif

