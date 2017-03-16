#pragma once

#include <SDL.h>
#include "Game.h"


class Menu {
public:
	Menu();
	void CargaMainMenu(Game* game, int menuSelec, SDL_Texture* sprite);
	void CargaPauseMenu(Game* game, int menuSelec, SDL_Texture* sprite);
	void CargaImgSprite(Game* game, char* nomImg, SDL_Texture* sprite);
};
