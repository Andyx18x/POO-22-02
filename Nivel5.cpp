#include "Nivel5.h"
#include "Stats.h"
#include "Menu.h"
#include "GameOver.h"
#include "Nivel6.h"
#include <cstdlib>
#include <ctime>
Nivel5::Nivel5() {
	m_ball.IncrementarVelocidad(5.f);
	m_ball.setBallMoving(false);
	
	m_stats.IncrementarNivel();
	
	/// Bloques aleatorios
	srand(time(nullptr));   /// Establece la semilla para la generación de números aleatorios
	
	for (int i = 0; i < 70; ++i) {   /// Genera bloques en posiciones aleatorias
		float x = (rand() % columnCount) * (blockWidth + 6.f) + 5.f;
		float y = (rand() % rowCount) * (blockHeight + 6.f) + 5.f;
		
		bool isSpecial = (rand () % 15 == 0); /// Probabilidad de 1 / 15 de ser especial el bloque nivel (Saltea 1)
		bool isSpecial_puntos = (rand()% 20 == 0); /// Probabilidad de 1 / 20 de ser especial  el bloque puntos
		bool isSpecial_menospts = (rand () % 10 == 0); /// Probabilidad 1 / 10 de ser especial el bloque puntos (resta 100)
		if(isSpecial){
			m_blocks.emplace_back(x,y,blockWidth,blockHeight,Color(255,0,128),false,true);
		}else{
			if(isSpecial_puntos){
				m_blocks.emplace_back(x,y,blockWidth,blockHeight,Color::Yellow,true,false);
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

void Nivel5::Update(Game &g){
	if(Keyboard::isKeyPressed(Keyboard::Escape)){ /// Escape para volver al menu
		g.SetScene(new Menu());
		m_stats.ResetStats();
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Space)){ /// Space comenzar a jugar
		m_ball.setBallMoving(true);
		m_stats.CambiarColores();
		m_stats.draw_text(false);
	}
	
	
	if(m_ball.Colisiona(m_player)){ /// Colisiones de la pelota con la paleta
		m_ball.Rebotar(m_player.DimensionesPlayer());
	}
	
	for (auto it = m_blocks.begin(); it != m_blocks.end(); ){
		if (m_ball.Colisiona(*it)) {
			if (it->isSpecialNivel()) {         /// Bloque especial de Nivel (Saltea 1)
				g.SetScene(new Nivel6());
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
	
	if(m_blocks.empty()){	/// Si los bloques se vacian Cambia al Nivel 6
		g.SetScene(new Nivel6());
	}
	
	if(m_ball.falling()){ /// Si la pelota sobresale de la pantalla Decrementa una vida
		
		m_stats.decrementar_vidas(1);
	}
	
	if(m_stats.VerVidas() == 0){ /// Si se llega a las vidas == 0, entonces se cambia a Game Over
		m_stats.GuardarScore(m_stats.MostrarPuntajeTotal());
		g.SetScene(new GameOver());
	}
	
	m_stats.actualizarStats();
	m_ball.Update();
	m_player.Update();
}



void Nivel5::Draw(RenderWindow &w){
	w.clear({20,20,20});
	m_ball.Draw(w);
	m_player.Draw(w);
	
	m_stats.DrawStats(w);
	
	for(auto &bloque : m_blocks){
		bloque.Draw(w);
	}
}
