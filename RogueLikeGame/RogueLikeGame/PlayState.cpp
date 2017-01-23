#include <stdio.h>

#include "SDL.h"
#include "Game.h"
#include "PlayState.h"
#include "PauseState.h"
#include <vector>

PlayState PlayState::m_PlayState;

void PlayState::Init(Game* game)
{
	CTile tile1 = CTile(0,0,0,0,0,32,32,"suelo");
	CTile tile2 = CTile(0, 0, 0, 0, 0, 32, 32, "suelo");

	CTile tileset[2] = { tile1,tile2 };

	CMapa mapa = CMapa("../src/maps/m1.map");

	bool funciona;

	funciona = mapa.setTiles(tileset);

	mapa.renderMap(tileset, game->GetRenderer());

	//playSprite = NULL;

	//playSprite = Sprite::Load("../src/sprites/atlas.bmp", game->GetRenderer());

	////playSprite = Sprite::Load("sprites/playstate.bmp", game->GetRenderer());

	//printf("PlayState Init Successful\n");

}

void PlayState::Clean()
{
	printf("PlayState Clean Successful\n");
}

void PlayState::Pause()
{
	printf("PlayState Paused\n");
}

void PlayState::Resume()
{
	printf("PlayState Resumed\n");
}

void PlayState::HandleEvents(Game* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			game->Quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {

				//En presionar Space canvia el estado del juego a PAUSA
			case SDLK_SPACE:
				game->PushState(PauseState::Instance());
				break;
			}
		}
	}
}

void PlayState::Update(Game* game)
{
}

void PlayState::Draw(Game* game)
{
	Sprite::DrawFullScreen(game->GetRenderer(), playSprite);
	SDL_RenderPresent(game->GetRenderer());
}
