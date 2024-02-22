#include "Game.h"
#include <SFML/Window/Event.hpp>
#include "Menu.h"
#include "Scene.h"
#include <SFML/Audio/Listener.hpp>
#include "Nivel.h"
Game::Game(): m_window(VideoMode(800,600), "Akari Breackout"){
	m_window.setFramerateLimit(60);
	m_scene = new Menu();
}

void Game::Run (){
	while(m_window.isOpen()) {
		Event e;
		while(m_window.pollEvent(e)) {
			if(e.type == Event::Closed)
				m_window.close();
			
			if(e.type == sf::Event::KeyPressed){
				if(e.key.code == Keyboard::Up){
					m_scene ->MoveUp();
				}
			}
			if(e.type == sf::Event::KeyPressed){
				if(e.key.code == Keyboard::Down){
					m_scene ->MoveDown();
				}
			}
		}
		m_scene ->Update(*this);
		m_scene ->Draw(m_window);
		m_window.display();
		
		if(m_next_scene){
			delete m_scene;
			m_scene = m_next_scene;
			m_next_scene = nullptr;
		}
	}
}

void Game::CloseGame(){
	m_window.close();
}

void Game::SetScene (Scene *new_scene){
	m_next_scene = new_scene;
}


Game::~Game(){
	delete m_scene;
}
	
	
	
