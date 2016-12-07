#pragma once

#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include "Sprite.h"

class Game
{

public:

	Game();

	void Init(const char* titulo, int sizeX, int sizeY, bool fullscreen);
	
	void HandleEvents(Game* game);

	void Update();

	void Draw();
	
	void Clean();

	void Quit();

	bool Running() { return m_bRunning; }

	SDL_Surface* WindowSurface() { return mWindowSurface; }

	~Game();

private:

	bool m_bRunning;
	bool m_bFullscreen;
	SDL_Window* Window;
	SDL_Surface* mWindowSurface;

	SDL_Surface* testSprite;
};

#endif