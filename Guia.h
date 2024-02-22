#ifndef GUIA_H
#define GUIA_H
#include "Scene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include "Blocks.h"

class Guia : public Scene {
public:
	Guia();
	void Update (Game & g);
	void Draw (RenderWindow & window);
private:
	Font m_font;
	Text m_text_amarillo, m_text_rosa, m_text_naranja, m_text_azul, m_volver_menu;
	Blocks m_bl_amarillo, m_bl_rosa, m_bl_naranja, m_bl_azul;
	
};

#endif

