#include <stdio.h>
#include <SDL.h>
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"


MenuState MenuState::m_MenuState;

void MenuState::Init(Game* game)
{
	menuSprite = NULL;
	menuSprite = Sprite::Load("sprites/atlas.bmp", game->GetRenderer());
	printf("MenuState Init Successful\n");
}

void MenuState::Clean()
{
	printf("MenuState Clean Successful\n");
}

void MenuState::Pause()
{
	printf("MenuState Paused\n");
}

void MenuState::Resume()
{
	printf("MenuState Resumed\n");
}

void MenuState::HandleEvents(Game* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			game->Quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {

			case SDLK_SPACE:
				game->ChangeState(PlayState::Instance());
				break;
			}
		}
	}
}

void MenuState::Update(Game* game)
{

}

void MenuState::Draw(Game* game)
{
	//Sprite::DrawFullScreen(game->GetRenderer(), menuSprite);
	//Sprite::Draw(game->GetRenderer(), menuSprite,0,0,32,32,480,352);
	//Sprite::Draw(game->GetRenderer(), menuSprite,32,0,32,32,480,352);


	//480 352 32 32

	//SDL_RenderClear(game->GetRenderer());
	  SDL_RenderPresent(game->GetRenderer());
}