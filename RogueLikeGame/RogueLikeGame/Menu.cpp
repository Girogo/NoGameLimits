#include <string>
#include <SDL.h>
#include "Game.h"
#include "Menu.h"
#include <stdio.h>
#include "PauseState.h"

using namespace std;

//De moment no es funcional

Menu::Menu(){

}

void Menu::CargaMainMenu(Game* game, int menuSelec, SDL_Texture* sprite)
{
	switch (menuSelec) {

	case 1:
		sprite = Sprite::Load("../src/sprites/menu/MainMenuStart.png", game->GetRenderer());
		//CargaImgSprite(game, "MainMenuStart.png");
		break;

	case 2:
		sprite = Sprite::Load("../src/sprites/menu/MainMenuSettings.png", game->GetRenderer());
		//CargaImgSprite(game, "MainMenuSettings.png");
		break;

	case 3:
		sprite = Sprite::Load("../src/sprites/menu/MainMenuExit.png", game->GetRenderer());
		//CargaImgSprite(game, "MainMenuExit.png");
		break;
	}
}

void Menu::CargaPauseMenu(Game* game, int menuSelec, SDL_Texture* sprite)
{
	switch (menuSelec) {

	case 1:
		sprite = Sprite::Load("../src/sprites/menu/PauseMenuReturn.png", game->GetRenderer());
		break;

	case 2:
		sprite = Sprite::Load("../src/sprites/menu/PauseMenuSettings.png", game->GetRenderer());
		break;

	case 3:
		sprite = Sprite::Load("../src/sprites/menu/PauseMenuExit.png", game->GetRenderer());
		break;
	}
}


/*void Menu::CargaImgSprite(Game* game, char* nomImg, SDL_Texture* sprite)
{
	char* src;
	strcat(src, "../src/sprites/menu/");
	strcat(src, nomImg);
	sprite = Sprite::Load(src, game->GetRenderer());
}*/
