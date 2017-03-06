#include "Game.h"
#include "GameState.h"
#include <stdio.h>
#include <SDL_ttf.h>


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
		SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC
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

	//Inicialitzem SDL_ttf
	if (!TTF_Init()) {
		printf("Error al iniciar SDL_ttf");
	}
}


void Game::ChangeState(GameState* state)
{
	//Limpia el estado actual
	if ( !states.empty() )
	{
		states.back()->Clean();
		states.pop_back();
	}

	//Guarda e inicializa el nuevo estado
	states.push_back(state);
	states.back()->Init(this);
}

void Game::PushState(GameState* state)
{
	//Pausa el estado actual
	if ( !states.empty() )
	{
		states.back()->Pause();
	}

	//Guarda e inicializa el nuevo estado
	states.push_back(state);
	states.back()->Init(this);
}

void Game::PopState(GameState* state)
{
	//Limpia el estado actual
	if ( !states.empty() )
	{
		states.back()->Clean();
		states.pop_back();
	}

	//Reanuda el estado anterior
	if ( !states.empty() )
	{
		states.back()->Resume();
	}
}

void Game::HandleEvents()
{
	states.back()->HandleEvents(this);
}


void Game::Update()
{
	states.back()->Update(this);
}


void Game::Draw()
{	
	states.back()->Draw(this);

	//SDL_RenderClear(m_WindowRenderer);
	//SDL_RenderPresent(m_WindowRenderer);
}

void Game::Clean()
{
	while ( !states.empty() )
	{
		states.back()->Clean();
		states.pop_back();
	}

	SDL_Quit();
}
SDL_Surface* Game::GetWindowSurface() {
	SDL_Surface  *windowSurface = SDL_GetWindowSurface(m_Window);
	return windowSurface;
}

SDL_Window* Game::GetWindow() {
	return m_Window;
}