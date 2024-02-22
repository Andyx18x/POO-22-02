#ifndef GAMEWON_H
#define GAMEWON_H
#include "Scene.h"
#include <SFML/Graphics/Text.hpp>
#include <vector>
using namespace std;

class GameWon : public Scene {
public:
	GameWon();
	void Update (Game & g);
	void Draw (RenderWindow & window);
	void MoveUp ( );
	void MoveDown ( );
private:
	Text Game_won; Font m_font;
	string m_score; Text score_text;
	vector<Text>option;
	int max_items = 2;
	int selectitem;
};

#endif

