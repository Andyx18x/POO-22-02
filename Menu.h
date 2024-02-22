#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

using namespace std;

class Menu : public Scene {
public:
	Menu();
	void Update(Game &g) override;
	void Draw(RenderWindow &window) override;
	void MoveUp() override;
	void MoveDown()override;
private:
	vector<Text>option;
	
	int Max_Items_Menu = 4;
	int selectItem;
	Sprite s_logo;
	Texture t_logo;
	Font m_font;
};

#endif

