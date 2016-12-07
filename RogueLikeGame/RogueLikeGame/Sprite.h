#pragma once
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Game.h"
#include <SDL.h>

class Sprite
{
public:

	Sprite();

	static SDL_Surface* Load(char* pImagen, SDL_Surface* mWindowSurface);

	static bool Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y);

	static bool Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, 
						int x2, int y2, int width, int height);
	
	~Sprite();
};
#endif

