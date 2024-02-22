#ifndef HIGHSCORES_H
#define HIGHSCORES_H
#include "Scene.h"
#include <vector>
#include <SFML/Graphics/Text.hpp>
using namespace std;

struct PlayerScore{
	string m_name;
	int m_puntos;
};

bool comparing_score(PlayerScore &a, PlayerScore &b);


class HighScores : public Scene{
public:
	HighScores();
	void Update(Game &g)override;
	void Draw(RenderWindow &window)override;
private:
	vector<Text>draw_scores; Font m_font;
	Text volver_menu;
	vector<PlayerScore>Scores;
};

#endif

