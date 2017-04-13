#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Game.h"

class CTexture
{
public:
	//Initializes variables
	CTexture();

	//Deallocates memory
	~CTexture();

	//Loads image at specified path
	bool loadFromFile(char * path, SDL_Renderer* m_WindowRenderer);

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Rennderiza la imagen a un punto, se passa como parametro el tamaño de la pantalla
	void render(int x, int y, SDL_Rect* clip, SDL_Renderer* m_WindowRenderer);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
	void* mPixels;
	int mPitch;
};

