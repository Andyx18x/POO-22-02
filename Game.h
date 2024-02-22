#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include <SFML/Audio/Music.hpp>
#include "Nivel.h"
using namespace sf;

class Game {
public:
	Game();
	void Run();
	void SetScene (Scene *new_scene);
	~Game();
	void CloseGame();
private:
	RenderWindow m_window;
	Scene *m_scene, *m_next_scene = nullptr;
};

#endif

