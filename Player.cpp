#include "Player.h"
#include <iostream>
#include <SFML/Graphics/Rect.hpp>
using namespace std;

Player::Player(){
	m_player.setSize(Vector2f(100,20));
	m_player.setFillColor({128,128,128});
	m_player.setOutlineThickness(2.0f);
	m_player.setOutlineColor({255,255,255});
	m_player.setPosition(400,570);
	
}

void Player::Update(){
	auto p = m_player.getPosition();
	
	if(Keyboard::isKeyPressed(Keyboard::A) or (Keyboard::isKeyPressed(Keyboard::Left))){
		m_player.move(-6,0);
	}
	if((Keyboard::isKeyPressed(Keyboard::D)) or (Keyboard::isKeyPressed(Keyboard::Right))){
		m_player.move(6,0);
	}
	
	LimitesPlayer();
	
	
}

void Player::LimitesPlayer(){
	if(m_player.getPosition().x < 0){
		m_player.setPosition(0, m_player.getPosition().y);
	}else{
		if(m_player.getPosition().x + m_player.getGlobalBounds().width > 800){
			m_player.setPosition(800 - m_player.getGlobalBounds().width, m_player.getPosition().y);
		}
	}
	
}

FloatRect Player::DimensionesPlayer(){
	float player_x = m_player.getPosition().x;
	float player_y = m_player.getPosition().y;	/// Esto se hace para sacar las dimensiones de la paleta
	float player_width = m_player.getSize().x;
	float player_height = m_player.getSize().y;
		
	FloatRect DimensionPlayer (player_x, player_y, player_width, player_height); /// x_paleta, y_paleta , ancho_paleta, alto_paleta
	return DimensionPlayer;
}
