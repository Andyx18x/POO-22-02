#include "Object.h"

Object::Object() {
	
	
}

void Object::Draw(RenderWindow &window){
	window.draw(m_player);
	window.draw(m_ball);
	window.draw(b_shape);
}

bool Object::Colisiona(const Object &o) const{
	auto r1 = this->m_ball.getGlobalBounds();
	auto r2 = o.m_player.getGlobalBounds();
	return r1.intersects(r2) or r1.intersects(o.b_shape.getGlobalBounds());
}
