#include <stdio.h>

#include "SDL.h"
#include "Game.h"
#include "PlayState.h"
#include "PauseState.h"
#include "Player.h"
#include <vector>

PlayState PlayState::m_PlayState;
void PlayState::Init(Game* game)
{
	//Limpia el renderer
	SDL_RenderClear(game->GetRenderer());
	

	//Cargamos Elementos del mapa i las tiles
	mapa = CMapa("../src/maps/m1.map");

	//Se passa como parametros Array de tiles, Numero de casillas de tiles que tiene el mapa, tamaño de las tyles
	//numero de columnas del mapa, numero de filas del mapa, total de id del tileset
	mapa.setTiles(tileset, 130, 64, 64, 13, 10, 20);
	mapa.load(game->GetRenderer());
	playSprite = Sprite::Load("sprites/playstate.bmp", game->GetRenderer());

	//Constructor del jugador i enemigo, se passa la ubicacion de la imagen i sus datos igual que
	//el renderer donde se carga
	enemy = CEnemy("sprites/crab.bmp", 120, 200, 64, 64, game->GetRenderer());
	player = CPlayer("sprites/macaco.bmp", 200, 200, 64, 64, game->GetRenderer());

	//Cargo la imagen del jugador i enemigo
	enemy.load();
	player.load();

	printf("PlayState Init Successful\n");
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
			//Eventos de teclado depende del que se clique un movimiento o otro
			case SDLK_SPACE:
				game->PushState(PauseState::Instance());
				break;				
			}
			//Moviemiento del jugador, se passa como parametro el evento de teclado realizado
			player.move(event);
			//Movimiento del enemigo, se le passa las cordenadas del jugador
			enemy.move(player.get_x(), player.get_y());
		}

	}
	
}

void PlayState::Update(Game* game)
{
}

void PlayState::Draw(Game* game)
{
	SDL_RenderClear(game->GetRenderer());
	//Dibuja el mapa
	mapa.draw(game->GetRenderer(), tileset);

	//Dibuja el enemigo
	enemy.draw();

	//Dibuja el personaje
	player.draw();
	
	//Implanta los elementos en la pantalla
	SDL_RenderPresent(game->GetRenderer());
}
