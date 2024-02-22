#include "Guia.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu.h"

using namespace sf;

Guia::Guia():m_bl_amarillo(100,100,100.f,20.f,Color::Yellow)
	,m_bl_naranja(100,200,100.f,20.f,Color(255,165,0)), 
	m_bl_rosa(100,300,100.f,20.f,Color(255,0,128)),
    m_bl_azul(100,400,100.f,20.f,Color::Blue) {
		
	
	m_font.loadFromFile("fuente_menu.ttf");
	m_text_amarillo.setFont(m_font);
	m_text_rosa.setFont(m_font); /// Cargamos la Fuente menu
	m_text_naranja.setFont(m_font);
	m_text_azul.setFont(m_font);
	m_volver_menu.setFont(m_font);
	
	
	m_text_amarillo.setFillColor(Color::White);
	m_text_rosa.setFillColor(Color::White);	/// Le Ponemos color blanco a los text
	m_text_naranja.setFillColor(Color::White);
	m_text_azul.setFillColor(Color::White);
	m_volver_menu.setFillColor(Color::Green);
	
	m_text_amarillo.setCharacterSize(16);
	m_text_rosa.setCharacterSize(16);	/// 16 pixeles de text
	m_text_naranja.setCharacterSize(16);
	m_text_azul.setCharacterSize(16);
	m_volver_menu.setCharacterSize(16);
	
	
	m_text_amarillo.setPosition(250,100); /// Establecemos la posicion de los text
	m_text_rosa.setPosition(250,300);
	m_text_naranja.setPosition(250,200);
	m_text_azul.setPosition(250,400);
	m_volver_menu.setPosition(540,570);
	
	
	
	
	m_text_amarillo.setString("Suma 70 puntos y 1 vida"); /// Establecemos un text a cada variable
	m_text_rosa.setString("Suma 100 puntos y 1 nivel");
	m_text_naranja.setString("Suma 200 puntos y 2 niveles");
	m_text_azul.setString("Resta 100 puntos");
	m_volver_menu.setString("<volver al menu>");
}

void Guia::Update (Game & g) {
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		g.SetScene(new Menu());
	}
}

void Guia::Draw (RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(m_text_amarillo); /// Dibujamos los text 
	window.draw(m_text_rosa);
	window.draw(m_text_naranja);
	window.draw(m_text_azul);
	window.draw(m_volver_menu);
	
	
	m_bl_amarillo.Draw(window); /// Dibujamos los bloques
	m_bl_rosa.Draw(window);
	m_bl_naranja.Draw(window);
	m_bl_azul.Draw(window);
}

