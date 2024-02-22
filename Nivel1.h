#ifndef MATCH_H
#define MATCH_H
#include "Ball.h"
#include "Player.h"
#include "Blocks.h"
#include <SFML/Graphics/Text.hpp>
#include "Stats.h"
#include "Nivel.h"



class Nivel1 : public Nivel{
public:
	Nivel1();
	void Draw(RenderWindow &w) override;
	void Update(Game &g) override;
private:
	
};

#endif

