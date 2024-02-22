#include "Nivel7.h"
#include "GameWon.h"
#include "Menu.h"
#include "GameOver.h"
#include <SFML/Graphics/RenderWindow.hpp>

Nivel7::Nivel7() {
	m_ball.IncrementarVelocidad(13.f);
	m_ball.setBallMoving(false);
	
	m_stats.IncrementarNivel();
	
	
	Color colors[] = {Color::Red, Color::Green, Color::Blue, Color::Yellow, Color::Magenta, Color::Cyan}; /// Vector de colores
	
	for (int i = 0; i < rowCount-2; ++i) { /// Ladrillos cambia colores
		if (i%2!=0){
			for (int j = 0; j < columnCount; ++j) {
				Color blockColor = colors[(i + j) % 6];
				float x = j * ((blockWidth-54) + 60.f) + 30.f;
				float y = i * ((blockHeight+54) + 10.f)+ 5.f;
				m_blocks.emplace_back(x, y, blockWidth - 54, blockHeight + 54, blockColor);
			}
		}else{
			for (int j = 0; j < columnCount-5; ++j) {
				Color blockColor = colors[(i + j) % 6];
				float x = j * ((blockWidth-54) + 140.f) + 43.f;
				float y = i * ((blockHeight+54) + 13.f)+ 25.f;
				m_blocks.emplace_back(x, y, blockWidth , blockHeight , blockColor);
			}
		}
	}
}

void Nivel7::Update (Game & g) {
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
		g.SetScene(new GameWon());
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

void Nivel7::Draw (RenderWindow &w) {
	w.clear({0,0,0});
	m_ball.Draw(w);
	m_player.Draw(w);
	
	m_stats.DrawStats(w);
	
	for(auto &bloque : m_blocks){
		bloque.Draw(w);
	}
}

