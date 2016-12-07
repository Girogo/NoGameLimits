#include "Game.h"
#include <stdio.h>


Game::Game()
{

}


void Game::Init(const char* titulo, int sizeX, int sizeY, bool fullscreen)
{
	SDL_INIT_EVERYTHING;

	int flags = 0;

	m_Window = NULL;
	m_WindowRenderer = NULL;

	testSprite = NULL;

	if (fullscreen)
	{
		flags = SDL_WINDOW_MAXIMIZED;
	}

	//Creación de la pantalla
	m_Window = SDL_CreateWindow(
		titulo,					//titulo pantalla
		SDL_WINDOWPOS_UNDEFINED,	//posicion x inicial
		SDL_WINDOWPOS_UNDEFINED,	//posicion y inicial
		sizeX,					//ancho en px
		sizeY,					//altura en px
		flags
	);

	//Creación del Renderizador
	m_WindowRenderer = SDL_CreateRenderer(
		m_Window,
		-1,
		SDL_RENDERER_ACCELERATED
	);

	/*SDL_SetRenderDrawColor
	(
		m_WindowRenderer,
		125,
		255,
		137,
		255
	);*/
	
	m_bFullscreen = fullscreen;
	m_bRunning = true;

	testSprite = Sprite::Load("sprites/test.bmp", m_WindowRenderer);
}


void Game::HandleEvents(Game* game)
{
	SDL_Event event;

	//si hay un evento en cola
	if (SDL_PollEvent(&event))
	{

		//switch entre diferentes tipos de evento.
		switch (event.type)
		{

		//Si el usuario pulsa la cruceta para salir, para la ejecución.
		case SDL_QUIT:
			game->Quit();
			break;

		//Si se pulsa una tecla
		case SDL_KEYDOWN:

			//switch entre la tecla pulsada.
			switch (event.key.keysym.sym)
			{
				//Si se pulsa Esc. cierra la ejecución.
			case SDLK_ESCAPE:
				game->Quit();
			}
		default:
			break;
		}
	}
}


void Game::Update()
{
}


void Game::Draw()
{	
	//SDL_RenderClear(m_WindowRenderer);
	Sprite::Draw(m_WindowRenderer, testSprite, 50, 50, 100, 100);
	Sprite::DrawFullScreen(m_WindowRenderer, testSprite);
	SDL_RenderPresent(m_WindowRenderer);
}


void Game::Clean()
{
}


void Game::Quit()
{
	m_bRunning = false;
}


Game::~Game()
{
}
