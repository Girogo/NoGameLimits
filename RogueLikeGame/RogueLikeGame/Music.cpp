#include "Music.h"
#include <stdio.h>


CMusic::CMusic()
{
}


CMusic::~CMusic()
{
}

void CMusic::loadMedia()
{
	gMusic = Mix_LoadMUS("../src/music/celtaMusic.mp3");
	gMusicPartida = Mix_LoadMUS("../src/music/musicaPartida.mp3");
	gEntrarPartida = Mix_LoadWAV("../src/music/entrarPartida.mp3");
	gMoverMenu = Mix_LoadWAV("../src/music/moverMenu.wav");
	gEntrarOpcion = Mix_LoadWAV("../src/music/entrarOpcion.wav");
	gCanviarOpcion = Mix_LoadWAV("../src/music/canviarOpcion.wav");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
	if (gMusicPartida == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
	if (gEntrarPartida == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	if (gEntrarOpcion == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	if (gMoverMenu == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	if (gCanviarOpcion == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void CMusic::close()
{
}
