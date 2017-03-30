#include <stdio.h>

#include "SDL.h"
#include "Game.h"
#include "PlayState.h"
#include "PauseState.h"
#include "Player.h"
#include "Timer.h"
#include "GUI.h"
#include <vector>


PlayState PlayState::m_PlayState;
void PlayState::Init(Game* game)
{
	
	//Carga la musica
	music.loadMedia();
	//Inicializa la musica
	if (Mix_PlayingMusic() == 0) {
		Mix_PlayMusic(music.getMusicPartida(), -1);
	}


	//Limpia el renderer
	SDL_RenderClear(game->GetRenderer());
	

	//Cargamos Elementos del mapa i las tiles
	mapa = CMapa();

	//Se passa como parametros Array de tiles, Numero de casillas de tiles que tiene el mapa, tamaño de las tyles
	//numero de columnas del mapa, numero de filas del mapa, total de id del tileset
	mapa.setTiles(floor, 130, 64, 64, 13, 10, 25, "../src/maps/m1.map");
	mapa.setTiles(walls, 130, 64, 64, 13, 10, 25, "../src/maps/m2.map");

	mapa.load(game->GetRenderer());

	//Constructor del jugador i enemigo, se passa la ubicacion de la imagen i sus datos igual que
	//el renderer donde se carga
	mosca = CMosca("../src/sprites/enemy/crab.bmp", 120, 200, 64, 64, game->GetRenderer());
	player = CPlayer("../src/sprites/pj/player.bmp", 180, 200, 64, 64, game->GetRenderer());


	//Inicialicamos la GUI i la cargamos
	GUI = CGUI(&player);
	GUI.loadMedia(game->GetRenderer());

	//Cargo la imagen del jugador i enemigo
	mosca.loadMedia(game->GetRenderer());
	player.loadMedia(game->GetRenderer());

	printf("PlayState Init Successful\n");

	CColission::getRectColission(walls, &collisions, "wall");
	CColission::getRectColission(floor, &collisions, "wall");

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

	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			game->Quit();
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				Mix_PauseMusic();
				game->PushState(PauseState::Instance());
			}
			if (event.key.keysym.sym == SDLK_f) {
				player.setVida(player.getVida() + 1);
				if (player.getVida() == 25) {
					player.setVida(0);
				}
			}
			if (event.key.keysym.sym == SDLK_c) {
				player.setCoins(player.getCoins() + 1);
			}
			if (event.key.keysym.sym == SDLK_b) {
				player.setBombs(player.getBombs() + 1);
			}
			if (event.key.keysym.sym == SDLK_k) {
				player.setKeys(player.getKeys() + 1);
			}
		}
		//Eventos del teclado, mira que evento ha ocurrido
		player.handleEvent(event);

		//Movimiento del enemigo, se le passa las cordenadas del jugador
		//enemy.move(player.get_x(), player.get_y());
	}
	//Coje los ticks
	float timeStep = stepTimer.getTicks() / 1000.f;

	//Mueve el jugador
	player.move(timeStep, collisions);
	mosca.move(timeStep, collisions, player.getZonaSegura(), &player);
	//Reinicia el timer
	stepTimer.start();

	//animacion del personaje
	player.animation();
	mosca.animation();
}

void PlayState::Update(Game* game)
{
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(music.getMusicPartida(), -1);
	}
}

void PlayState::Draw(Game* game)
{
	SDL_RenderClear(game->GetRenderer());
	//Dibuja el mapa
	
	mapa.draw(game->GetRenderer(), floor);
	
	//Dibuja el enemigo
	mosca.render(game->GetRenderer());

	//Dibuja el personaje
	player.render(game->GetRenderer());
	
	mapa.draw(game->GetRenderer(), walls);
	if (player.getPrint()) {
		player.render(game->GetRenderer());
	}
	if (mosca.getPrint()) {
		mosca.render(game->GetRenderer());
	}
	GUI.drawGUI(game->GetRenderer());
	//Implanta los elementos en la pantalla
	SDL_RenderPresent(game->GetRenderer());
}
