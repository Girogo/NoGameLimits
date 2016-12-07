#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include "Sprite.h"

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
	

	/*------------------------------------------------------------------------------
	*Metodo HandleEvents:
	*				Controla los eventos que surgen.
	*Parametros:	Puntero a objeto de clase game
	*------------------------------------------------------------------------------*/
	void HandleEvents(Game* game);


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


	/*------------------------------------------------------------------------------
	*Metodo Quit:	
	*Parametros:	
	*------------------------------------------------------------------------------*/
	void Quit();


	/*------------------------------------------------------------------------------
	*Metodo Running:
	*				Devuelve el estado actual del juego (si se ejecuta o no)
	*Parametros:	Titulo de la pantalla, dimensiones(X/Y) FullScreen(true/false)
	*------------------------------------------------------------------------------*/
	bool Running() { return m_bRunning; }


	~Game();

private:

	bool m_bRunning;
	bool m_bFullscreen;
	SDL_Window* m_Window;
	SDL_Renderer* m_WindowRenderer;

	SDL_Texture* testSprite;
};

#endif