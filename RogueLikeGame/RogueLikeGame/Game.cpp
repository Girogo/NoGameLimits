#include "Game.h"
#include <stdio.h>


Game::Game()
{

}


//Inicializa todos los componentes de SDL y la pantalla.
//Parametros (Titulo pantalla, longitud, altura y fullscreen(true/false)

void Game::Init(const char* titulo, int sizeX, int sizeY, bool fullscreen)
{
	SDL_INIT_EVERYTHING;
	int flags = 0;
	testSprite = NULL;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_MAXIMIZED;
	}

	//Creación de la pantalla
	Window = SDL_CreateWindow(
		titulo,					//titulo pantalla
		SDL_WINDOWPOS_CENTERED,	//posicion x inicial
		SDL_WINDOWPOS_CENTERED,	//posicion y inicial
		sizeX,					//ancho en px
		sizeY,					//altura en px
		flags
	);

	m_bFullscreen = fullscreen;
	m_bRunning = true;

	mWindowSurface = SDL_GetWindowSurface(Window);
	testSprite = Sprite::Load("sprites/test.bmp", mWindowSurface);
}


//Controlador de eventos (Entrada de teclado, cerrar pantalla...)

void Game::HandleEvents(Game* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		//Si el usuario quiere salir
		case SDL_QUIT:
			game->Quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				game->Quit();
			}
		default:
			break;
		}
	}
}


//Update

void Game::Update()
{
	SDL_UpdateWindowSurface(Window);
}


//Draw

void Game::Draw()
{	
	Sprite::Draw(mWindowSurface, testSprite, 0, 0);

}


//Clean

void Game::Clean()
{

}


//Quit

void Game::Quit()
{
	m_bRunning = false;
}



Game::~Game()
{
}
