#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include "Sprite.h"
#include <vector>

class GameState;

/*==============================================================*
 *Clase Game: Tiene los metodos principales del flujo del juego *
 *==============================================================*/
class Game
{
public:

	Game();
	/*------------------------------------------------------------------------------
	 *Metodo Init:	Inicializa SDL, crea una pantalla y un renderer
	 *Parametros:	Titulo de la pantalla, dimensiones(X/Y) FullScreen(true/false)
	 *------------------------------------------------------------------------------*/
	void Init(const char* titulo, int sizeX, int sizeY, bool fullscreen);
	
	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState(GameState* state);
	/*------------------------------------------------------------------------------
	*Metodo HandleEvents:
	*				Controla los eventos que surgen.
	*Parametros:	Puntero a objeto de clase game
	*------------------------------------------------------------------------------*/
	void HandleEvents();


	/*------------------------------------------------------------------------------
	*Metodo Update:	
	*Parametros:	
	*------------------------------------------------------------------------------*/
	void Update();


	/*------------------------------------------------------------------------------
	*Metodo Draw:	
	*Parametros:	
	*------------------------------------------------------------------------------*/
	void Draw();
	

	/*------------------------------------------------------------------------------
	*Metodo Clean:	
	*Parametros:	
	*------------------------------------------------------------------------------*/
	void Clean();

	SDL_Surface* GetWindowSurface();

	SDL_Window* GetWindow();

	/*------------------------------------------------------------------------------
	*Metodo Quit:	
	*Parametros:	
	*------------------------------------------------------------------------------*/
	void Quit() { m_bRunning = false; };


	/*------------------------------------------------------------------------------
	*Metodo Running:
	*				Devuelve el estado actual del juego (si se ejecuta o no)
	*Parametros:	Titulo de la pantalla, dimensiones(X/Y) FullScreen(true/false)
	*------------------------------------------------------------------------------*/
	bool Running() { return m_bRunning; }

	SDL_Renderer* GetRenderer() { return m_WindowRenderer; }

private:

	bool m_bRunning;
	bool m_bFullscreen;

	SDL_Window* m_Window;
	SDL_Surface *screen;
	SDL_Renderer* m_WindowRenderer;

	std::vector<GameState*> states;

	SDL_Texture* testSprite;
};
#endif