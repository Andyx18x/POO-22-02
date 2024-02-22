#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


using namespace sf;

class Stats {
public:
	Stats();
	void aumentarpuntaje(int puntos);
	void restarpuntaje(int puntos);
	int obtenerpuntaje();
	int MostrarPuntajeTotal();
	void actualizarStats();
	void DrawStats(RenderWindow &w);
	void IncrementarNivel();
	int ObtenerNivel();
	void CambiarColores();
	void ResetStats();
	void decrementar_vidas(int m_v);
	bool draw_text(bool dr);
	int VerVidas();
	void IncrementarVidas ();
	void CargarStats(int vidas, int puntaje, int nivel);
	void GuardarScore(int puntos);
	void DobleNivel();
	
private:
	
	int m_nivel = 1, PuntajeTotal = 0,  m_vidas = 3;
	Font m_font; bool is_draw;
	
	Text score_text; Text txt_vidas;
	Text nivel_game;
	Text comenzar_jugar;
};

extern Stats m_stats; /// SE UTILIZA PARA DECLARAR ESA VARIABLE COMO GLOBAL.
#endif

