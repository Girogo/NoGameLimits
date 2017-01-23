#include <stdio.h>

#include "SDL.h"
#include "Game.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;

void PauseState::Init(Game* game)
{
	pauseSprite = NULL;

	//pauseSprite = Sprite::Load("sprites/paused.bmp", game->GetRenderer());

	printf("PauseState Init Successful\n");
}

void PauseState::Clean()
{
	printf("PauseState Clean Successful\n");
}

void PauseState::Resume() {}

void PauseState::Pause() {}

void PauseState::HandleEvents(Game* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			game->Quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				game->PopState(PauseState::Instance());
				break;
			}
		}
	}
}

void PauseState::Update(Game* game)
{
}

void PauseState::Draw(Game* game)
{
	//Sprite::DrawFullScreen(game->GetRenderer(), pauseSprite);
	//SDL_RenderPresent(game->GetRenderer());
}
