
#include "Game.h"
#include "Menu.h"
#include <iostream>
#include "Nivel2.h"
#include "GameOver.h"
#include <cmath>
#include "Nivel3.h"
using namespace std;

Nivel1::Nivel1() {
	m_ball.setBallMoving(false);
	m_stats.ResetStats();
	
	
	
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < columnCount - i; ++j) { /// Ajuste en el límite de columnas
			float x = (j + 0.5f * i) * (blockWidth + 6.f) + 5.f;
			float y = i * (blockHeight + 6.f) + 5.f;
			
			bool isSpecial = (rand () % 40 == 0); /// Probabilidad de 1 / 30 de ser especial el bloque nivel (Saltea 1)
			bool isSpecial_puntos = (rand()% 50 == 0); /// Probabilidad de 1 / 50 de ser especial  el bloque puntos
			bool isSpecial_nivel_d = (rand () % 110 == 0); /// Probabilidad 1 / 110 de ser especial el bloque Nivel (saltea 2)
			bool isSpecial_menospts = (rand () % 20 == 0); /// Probabilidad 1 / 30 de ser especial el bloque puntos (resta 100)
			
			if(isSpecial){
				m_blocks.emplace_back(x,y,blockWidth,blockHeight,Color(255,0,128),false,true);
			}else{
				if(isSpecial_puntos){
					m_blocks.emplace_back(x,y,blockWidth,blockHeight,Color::Yellow,true,false);
				}else{
					if(isSpecial_nivel_d){
						m_blocks.emplace_back(x,y,blockWidth,blockHeight,Color(255,165,0),false,false,true);
					}else{
						if(isSpecial_menospts){
							m_blocks.emplace_back(x,y,blockWidth,blockHeight,Color::Blue,false,false,false,true);
						}else{
							m_blocks.emplace_back(x, y, blockWidth, blockHeight, Color::Black);
						}
					}
				}
			}
		}
	}
}
	

void Nivel1::Update(Game &g){
	
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		g.SetScene(new Menu());
		m_stats.ResetStats();
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		m_ball.setBallMoving(true);
		m_stats.CambiarColores();
		m_stats.draw_text(false);
	}
	
	if(m_ball.Colisiona(m_player)){
		m_ball.Rebotar(m_player.DimensionesPlayer());
	}
	
	
	
	for (auto it = m_blocks.begin(); it != m_blocks.end(); ){
		if (m_ball.Colisiona(*it)) {
			if (it->isSpecialNivel()) {         /// Bloque especial de Nivel
				g.SetScene(new Nivel2());
				m_stats.aumentarpuntaje(100);
				m_ball.Rebotar();
				it = m_blocks.erase(it); /// Eliminar bloque especial
				continue; /// Continuar con el siguiente bloque
			}
			
			/// Bloque especial de puntos
			if(it->isSpecialBlock()){
				m_stats.aumentarpuntaje(75);
				m_stats.IncrementarVidas();
				m_ball.Rebotar();
				it = m_blocks.erase(it); /// Eliminar bloque especial
				continue; /// Continuar con el siguiente bloque
			} 
			
			/// Bloque especial Nivel (Saltea 2)
			if(it->isSpecialNivel_dos()){
				m_stats.aumentarpuntaje(200);
				g.SetScene(new Nivel3());
				m_ball.Rebotar();
				it = m_blocks.erase(it); /// Eliminar bloque especial
				continue; /// Continuar con el siguiente bloque
			}   
			
			/// Bloque especial de puntos (resta 100)
			if(it->isSpecialPts()){
				m_stats.restarpuntaje(100);
				m_ball.Rebotar();
				it = m_blocks.erase(it); /// Eliminar bloque especial
				continue; /// Continuar con el siguiente bloque
			} 
			
			/// Si no es especial el bloque pasa esto..
			m_stats.aumentarpuntaje(25);
			m_ball.Rebotar();
			it = m_blocks.erase(it); /// Avanza el iterador después de eliminar el bloque no especial
		} else {
			++it; /// Avanza al siguiente bloque si no hay colisión
		}
	}
	
	
	
	if(m_blocks.empty()){
		g.SetScene(new Nivel2());
	}
	
	if(m_ball.falling()){
		m_stats.decrementar_vidas(1);
	}
	
	if(m_stats.VerVidas() == 0){
		m_stats.GuardarScore(m_stats.obtenerpuntaje());
		g.SetScene(new GameOver());
	}
	
	m_stats.actualizarStats();
	m_ball.Update();
	m_player.Update();
	
}

void Nivel1::Draw(RenderWindow &w){
	w.clear({20,20,20});
	m_ball.Draw(w);
	m_player.Draw(w);
	m_stats.DrawStats(w);
	
	for(auto &bloque : m_blocks){
		bloque.Draw(w);
	}
}


