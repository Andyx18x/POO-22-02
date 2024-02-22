#include "Stats.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <fstream>

#include <iostream>
using namespace std;

Stats::Stats() {
	m_font.loadFromFile("fuente_menu.ttf");
	
	score_text.setFont(m_font);
	score_text.setCharacterSize(16);
	score_text.setFillColor(Color::Black);
	score_text.setPosition(20.f,400.f);
	

	nivel_game.setFont(m_font);
	nivel_game.setCharacterSize(16);
	nivel_game.setFillColor(Color::Black);
	nivel_game.setPosition(20.f,350.f);
	
	
	comenzar_jugar.setFont(m_font);
	comenzar_jugar.setCharacterSize(12);
	comenzar_jugar.setFillColor(Color::White);
	comenzar_jugar.setPosition(500,500);
	
	txt_vidas.setFont(m_font);
	txt_vidas.setCharacterSize(16);
	txt_vidas.setFillColor(Color::Black);
	txt_vidas.setPosition(20.f,300);
	
	is_draw = true;
}


void Stats::aumentarpuntaje(int puntos){
	PuntajeTotal+=puntos;
}

void Stats::restarpuntaje(int puntos){
	PuntajeTotal-=puntos;
}

int Stats::obtenerpuntaje(){
	return PuntajeTotal;
}

void Stats::IncrementarNivel(){
	m_nivel+=1;
}

int Stats::ObtenerNivel(){
	return m_nivel;
}

void Stats::actualizarStats(){
	score_text.setString("Score: " + to_string(PuntajeTotal));
	nivel_game.setString("Nivel: " + to_string(m_nivel));
	comenzar_jugar.setString("Presione SPACE para jugar");
	txt_vidas.setString("Vidas: " + to_string(m_vidas));
}

void Stats::DrawStats(RenderWindow &w){
	w.draw(score_text);
	w.draw(nivel_game);
	w.draw(txt_vidas);
	if(is_draw){
		w.draw(comenzar_jugar);
	};
}



int Stats::MostrarPuntajeTotal(){
	return PuntajeTotal;
}

void Stats::CambiarColores(){
	score_text.setFillColor(Color::White);
	nivel_game.setFillColor(Color::White);
	txt_vidas.setFillColor(Color::White);
}

void Stats::ResetStats(){
	PuntajeTotal = 0;
	m_nivel = 1;
	m_vidas = 3;
}

bool Stats::draw_text(bool dr){
	is_draw = dr;
}

void Stats::decrementar_vidas(int m_v){
	m_vidas -= m_v;
}

int Stats::VerVidas(){
	return m_vidas;
}

void Stats::IncrementarVidas(){
	m_vidas++;
}

void Stats::GuardarScore(int puntos){
	ofstream archi("puntos.txt",ios::trunc);
	
	if(archi.is_open()){
		archi<<puntos;
		archi.close();
		cout<<"Se abrio correctamente"<<endl;
	}
	
}

void Stats::CargarStats(int vidas, int puntaje, int nivel){
	PuntajeTotal = puntaje;
	m_vidas = vidas;
	m_nivel = nivel;
}

void Stats::DobleNivel(){
	m_nivel+=2;
}


Stats m_stats;
