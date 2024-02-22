#include "Ball.h"
#include <iostream>
#include <cstdlib>
#include <SFML/Window/Keyboard.hpp>
using namespace std;

Ball::Ball(){
	m_ball.setRadius(8.0f);
	m_ball.setFillColor({255,255,255});
	m_ball.setOutlineThickness(1.0f);
	m_ball.setOutlineColor(Color::White);
	m_ball.setPosition(400,300);
	
	velocity = 4.5f;
	m_speed.y = velocity; is_falling = 0;
	m_speed.x = 0;
	
	
}

void Ball::Update(){
	Play();
	auto p = m_ball.getPosition();
	is_falling = false;
	
	if(p.x<0 or p.x + 16> 800){
		m_speed.x = -m_speed.x;
		
	}
	if(p.y < 0){
		m_speed.y = -m_speed.y;
	}
	if(p.y> 600){
		m_ball.setPosition(800 / 2.f,600 / 2.f);
		ball_moving = false; is_falling = true;
		m_speed.x = 0;
	}
	
}

void Ball::Rebotar(const FloatRect& playerBounds){ /// Este rebotar se utiliza para paleta-pelota
	/// Invierte la dirección vertical de la pelota
	m_speed.y = -m_speed.y;
	
	/// Calcula la posición relativa de la pelota en relación con la paleta
	float relativeIntersect = (m_ball.getPosition().x + m_ball.getRadius()) - (playerBounds.left + playerBounds.width / 2);
	
	/// Ajusta el cambio en la dirección horizontal en función de la posición relativa
	m_speed.x = relativeIntersect / (playerBounds.width / 2) * MAX_SPEED_X;
}
void Ball::Rebotar(){ /// Este rebotar se utiliza para pelota - ladrillo 
	m_speed.y = -m_speed.y;
	m_speed.x -= std::rand()%100 / 50.f;
}

void Ball::IncrementarVelocidad(int speed){
	velocity+=speed;
	m_speed.y = velocity;
	
}

void Ball::Play(){

	if(ball_moving){
		m_ball.move(m_speed);
	}
}

void Ball::setBallMoving(bool moving){
	ball_moving = moving;
}

int Ball::ball_speed(){
	return velocity;
}

bool Ball::falling(){
	return is_falling;
}
