#include "Nivel6.h"
#include "Stats.h"
#include "Menu.h"
#include "GameOver.h"
#include "Nivel7.h"

Nivel6::Nivel6() {
	m_ball.IncrementarVelocidad(10.f);
	m_ball.setBallMoving(false);
	
	m_stats.IncrementarNivel();
	
	
	///Bordes en negrita
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < columnCount; ++j) {
			if (i == 0 || j == 0 || i == rowCount - 1 || j == columnCount - 1) { 
				float x = j * (blockWidth + 6.f) + 5.f;
				float y = i * (blockHeight + 6.f) + 5.f;
				m_blocks.emplace_back(x, y, blockWidth, blockHeight, Color::Black);
			} else {
				float x = j * (blockWidth + 6.f) + 5.f;
				float y = i * (blockHeight + 6.f) + 5.f;
				m_blocks.emplace_back(x, y, blockWidth, blockHeight, Color::Black);
			}
		}
	}
}

void Nivel6::Update(Game &g){
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
		g.SetScene(new Nivel7());
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



void Nivel6::Draw(RenderWindow &w){
	w.clear({20,20,20});
	m_ball.Draw(w);
	m_player.Draw(w);
	
	m_stats.DrawStats(w);
	
	for(auto &bloque : m_blocks){
		bloque.Draw(w);
	}
}

