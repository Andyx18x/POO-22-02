#include "Blocks.h"
#include <SFML/Graphics/RectangleShape.hpp>

Blocks::Blocks(float x, float y, float width, float height, Color color, bool is_especial, bool is_especial_n, bool is_especial_nd, bool is_special_pts){
	
	
	b_shape.setSize(Vector2f(width,height));
	b_shape.setPosition(x,y);
	b_shape.setFillColor(color);		/// FORMATO DE LOS BLOQUES default
	b_shape.setOutlineThickness(2.f);
	b_shape.setOutlineColor(sf::Color::White);
	
	
	
	es_especial = is_especial;
	es_especial_nivel = is_especial_n;  /// Bloques ESPECIALES
	es_especial_nivel_d = is_especial_nd;
	es_especial_pts = is_special_pts;
}


