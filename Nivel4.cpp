#include "Nivel4.h"
#include "Menu.h"
#include "Ball.h"
#include "Stats.h"
#include "GameOver.h"
#include "Nivel5.h"

Nivel4::Nivel4() {
	m_ball.IncrementarVelocidad(6.f);
	m_ball.setBallMoving(false);
	
	m_stats.IncrementarNivel();
	
	
	///Tablero de ajedrez
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < columnCount; ++j) {
			if ((i + j) % 2 == 0) { // Se añaden bloques en posiciones donde la suma de índices es par
				float x = j * (blockWidth + 6.f) + 5.f;
				float y = i * (blockHeight + 6.f) + 5.f;
				m_blocks.emplace_back(x, y, blockWidth, blockHeight, Color::Black);
			}
		}
	}
}

void Nivel4::Update(Game &g){
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
	
	for(auto it = m_blocks.begin();it!=m_blocks.end();it++){
		if(m_ball.Colisiona(*it)){
			m_stats.aumentarpuntaje(25);
			m_blocks.erase(it);
			m_ball.Rebotar();
			break;
		}
	}
	
	if(m_blocks.empty()){
		g.SetScene(new Nivel5());
		
	}
	
	if(m_ball.falling()){
		m_stats.decrementar_vidas(1);
	}
	
	if(m_stats.VerVidas() == 0){
		m_stats.GuardarScore(m_stats.MostrarPuntajeTotal());
		g.SetScene(new GameOver());
	}
	
	m_stats.actualizarStats();
	m_ball.Update();
	m_player.Update();
}



void Nivel4::Draw(RenderWindow &w){
	w.clear({20,20,20});
	m_ball.Draw(w);
	m_player.Draw(w);
	
	m_stats.DrawStats(w);
	
	for(auto &bloque : m_blocks){
		bloque.Draw(w);
	}
}
