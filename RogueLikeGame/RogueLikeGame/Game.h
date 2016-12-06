#pragma once

#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>


class Game
{

public:

	Game();

	void Init(const char* titulo, int sizeX, int sizeY, bool fullscreen);
	
	void HandleEvents(Game* game);

	bool Running() { return m_bRunning; }

	void Update();

	void Draw();
	
	void Clean();

	void Quit();

	~Game();

private:

	bool m_bRunning;
	bool m_bFullscreen;
	SDL_Window* Window;
};

#endif