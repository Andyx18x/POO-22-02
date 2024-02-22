#include "GameWon.h"
#include <fstream>
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include "Nivel1.h"
using namespace std;

GameWon::GameWon() {
	m_font.loadFromFile("fuente_menu.ttf");
	
	
	
	Game_won.setFont(m_font);
	Game_won.setCharacterSize(54);
	Game_won.setFillColor(Color::White);
	Game_won.setPosition(200.f,100.f);
	
	
	
	score_text.setFont(m_font);
	score_text.setCharacterSize(24);
	score_text.setFillColor(Color::White);
	score_text.setPosition(300.f,250.f);
	
	int Var_y = 500;
	option.resize(max_items);
	
	for(int i=0;i<max_items;i++){
		option[i].setFont(m_font);
		option[i].setCharacterSize(16);
		option[i].setPosition(280,Var_y);
		Var_y +=40;
	}
	
	option[0].setFillColor(Color::Green);
	option[1].setFillColor(Color::White);
	
	option[0].setString("<Volver a Jugar>");
	option[1].setString("<Volver al Menu>");
	
	
	ifstream archi("puntos.txt");
	archi>>m_score;
	archi.close();
	
	
	Game_won.setString("GAME WON");
	score_text.setString("SCORE: "+m_score);
	
	
	selectitem = 0;
}

void GameWon::Update (Game & g) {
	if((option[selectitem].getString()== option[0].getString()) and Keyboard::isKeyPressed(Keyboard::Space)){
		g.SetScene(new Nivel1());
	}
	if((option[selectitem].getString()== option[1].getString()) and Keyboard::isKeyPressed(Keyboard::Space)){
		g.SetScene(new Menu());
	}
}

void GameWon::Draw (RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(Game_won);
	window.draw(score_text);
	for(auto &x : option){
		window.draw(x);
	}
}

void GameWon::MoveUp ( ) {
	if(selectitem - 1 >= 0 ){
		option[selectitem].setFillColor(Color::White);
		selectitem--;
		option[selectitem].setFillColor(Color::Green);
	}
}

void GameWon::MoveDown ( ) {
	if(selectitem + 1 < max_items ){
		option[selectitem].setFillColor(Color::White);
		selectitem++;
		option[selectitem].setFillColor(Color::Green);
	}
}

