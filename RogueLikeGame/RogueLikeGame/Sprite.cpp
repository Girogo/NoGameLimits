#include "Sprite.h"
#include "Game.h"
#include <SDL_image.h>
#include <stdio.h>



Sprite::Sprite()
{
}

SDL_Surface* Sprite::Load(char* File, SDL_Surface* mWindowSurface)
{
	SDL_Surface* loadedSurface = NULL;
	SDL_Surface* optimizedSurface = NULL;

	if ((loadedSurface = IMG_Load(File)) == NULL)
	{
		printf("No se ha encontrado la imagen");
		return NULL;
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, mWindowSurface->format, NULL);
		SDL_FreeSurface(loadedSurface);

		return optimizedSurface;
	}
}

bool Sprite::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y)
{
	if (dest == NULL || src == NULL)
	{
		return false;
	}

	SDL_Rect destR;
	destR.x = x;
	destR.y = y;

	//SDL_Blit -> Copia una Surface a otra Surface
	SDL_BlitSurface(src, NULL, dest, &destR);
	
	/*SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = dest->w;
	stretchRect.h = dest->h;
	SDL_BlitScaled(src, NULL, dest, &stretchRect);*/

	return true;
}

bool Sprite::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x2, int y2, int width, int height)
{
	if (dest == NULL || src == NULL)
	{
		return false;
	}

	SDL_Rect destR;

	destR.x = x;
	destR.y = y;

	SDL_Rect srcR;

	srcR.x = x2;
	srcR.y = y2;
	srcR.w = width;
	srcR.h = height;

	SDL_BlitSurface(src, &srcR, dest, &destR);

	return true;
}
Sprite::~Sprite()
{
}
