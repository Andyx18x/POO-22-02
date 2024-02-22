#ifndef NIVEL2_H
#define NIVEL2_H
#include "Nivel1.h"
#include "Nivel.h"

class Nivel2: public Nivel {
public:
	Nivel2();
	void Draw(RenderWindow &w) override;
	void Update(Game &g) override;
	int VerPuntaje();
	int speed_ball();
	int VerNivel();
	int VerVidas();
private:
};

#endif

