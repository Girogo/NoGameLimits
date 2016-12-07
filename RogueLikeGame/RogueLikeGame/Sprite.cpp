#include "Sprite.h"
#include "Game.h"
#include <SDL_image.h>
#include <stdio.h>



Sprite::Sprite()
{
}


SDL_Texture* Sprite::Load(char* File, SDL_Renderer* m_WindowRenderer)
{
	//Se inicializa una surface para cargar la imagen y la textura
	SDL_Surface* loadedSurface = NULL;
	SDL_Texture* optimizedTexture = NULL;


	if ((loadedSurface = IMG_Load(File)) == NULL)
	{
		printf("No se ha encontrado la imagen");
		return NULL;
	}
	else
	{
		/*Crea la textura a base del renderer donde se va a mostrar y la superficie para
		 *que sea optimizado*/

		optimizedTexture = SDL_CreateTextureFromSurface(m_WindowRenderer, loadedSurface);
		SDL_FreeSurface(loadedSurface);

		//Devuelve la textura optimizada
		return optimizedTexture;
	}
}


bool Sprite::Draw(SDL_Renderer* dest, SDL_Texture* src, int x, int y, int w, int h)
{
	if (dest == NULL || src == NULL)
	{
		return false;
	}

	//Se crea el rectangulo destino
	SDL_Rect destR;
	destR.x = x;
	destR.y = y;
	destR.w = w;
	destR.h = h;

	//Copia la textura al renderer
	SDL_RenderCopy(dest, src, NULL, &destR);

	return true;
}


bool Sprite::Draw(SDL_Renderer* dest, SDL_Texture* src, int x, int y, int width, int height, int x2, int y2, int width2, int height2)
{
	if (dest == NULL || src == NULL)
	{
		return false;
	}

	//Se crea el rectangulo destino.
	SDL_Rect destR;

	destR.x = x;
	destR.y = y;
	destR.w = width;
	destR.h = height;

	//Se crea el rectangulo src.
	SDL_Rect srcR;

	srcR.x = x2;
	srcR.y = y2;
	srcR.w = width2;
	srcR.h = height2;

	//Copia la textura al renderer.
	SDL_RenderCopy(dest, src, &srcR, &destR);

	return true;
}


bool Sprite::DrawFullScreen(SDL_Renderer* dest, SDL_Texture* src)
{
	if (dest == NULL || src == NULL)
	{
		return false;
	}

	//Copia la textura al renderer en pantalla completa.
	SDL_RenderCopy(dest, src, NULL, NULL);
	return true;
}


Sprite::~Sprite()
{
}
