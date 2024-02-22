#include "Nivel5.h"
#include "Stats.h"
#include "Menu.h"
#include "GameOver.h"
#include "Nivel6.h"
Nivel5::Nivel5() {
	m_ball.IncrementarVelocidad(10.f);
	m_ball.setBallMoving(false);
	
	m_stats.IncrementarNivel();
	
	
	// Se define una densidad objetivo de bloques
	float targetDensity = 0.5f;
	
	// Se calcula la cantidad total de bloques a colocar
	int totalBlocks = rowCount * columnCount;
	
	// Se calcula la cantidad de bloques que se colocarán según la densidad objetivo
	int numBlocksToPlace = static_cast<int>(targetDensity * totalBlocks);
	
	// Se generan posiciones aleatorias para colocar los bloques
	for (int k = 0; k < numBlocksToPlace; ++k) {
		int randomRow = rand() % rowCount;
		int randomColumn = rand() % columnCount;
		float x = randomColumn * (blockWidth + 6.f) + 5.f;
		float y = randomRow * (blockHeight + 6.f) + 5.f;
		m_blocks.emplace_back(x, y, blockWidth, blockHeight, Color::Black);
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
	
	for(auto it = m_blocks.begin();it!=m_blocks.end();it++){ /// Como se manejan los puntos en el game
		if(m_ball.Colisiona(*it)){
			m_stats.aumentarpuntaje(25);
			m_blocks.erase(it);
			m_ball.Rebotar();
			break;
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
