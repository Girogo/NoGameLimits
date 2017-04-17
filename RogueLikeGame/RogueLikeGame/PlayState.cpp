#include <stdio.h>

#include "SDL.h"
#include "Game.h"
#include "PlayState.h"
#include "PauseState.h"
#include "Timer.h"
#include "GUI.h"
#include <vector>


PlayState PlayState::m_PlayState;
//CMosca moscaGlobal;
void PlayState::Init(Game* game)
{

	fpsTimer.start();

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
	mapa2 = CMapa();
	//Se passa como parametros Array de tiles, Numero de casillas de tiles que tiene el mapa, tamaño de las tyles
	//numero de columnas del mapa, numero de filas del mapa, total de id del tileset

	mapa.setTiles(floor, 130, 64, 64, 13, 10, 29, "../src/maps/SpawnFloor.map");
	mapa.setTiles(walls, 130, 64, 64, 13, 10, 29, "../src/maps/Spawn.map");
	mapa2.setTiles(floor2, 130, 64, 64, 13, 10, 29, "../src/maps/mapa2Floor.map");
	mapa2.setTiles(walls2, 130, 64, 64, 13, 10, 29, "../src/maps/mapa2.map");
	mapa3.setTiles(floor3, 130, 64, 64, 13, 10, 29, "../src/maps/mapa3Floor.map");
	mapa3.setTiles(walls3, 130, 64, 64, 13, 10, 29, "../src/maps/mapa3.map");
	mapa4.setTiles(floor4, 130, 64, 64, 13, 10, 29, "../src/maps/mapa4Floor.map");
	mapa4.setTiles(walls4, 130, 64, 64, 13, 10, 29, "../src/maps/mapa4.map");
	mapa5.setTiles(floor5, 130, 64, 64, 13, 10, 29, "../src/maps/mapa5Floor.map");
	mapa5.setTiles(walls5, 130, 64, 64, 13, 10, 29, "../src/maps/mapa5.map");
	mapa.load(game->GetRenderer());
	mapa2.load(game->GetRenderer());
	mapa3.load(game->GetRenderer());
	mapa4.load(game->GetRenderer());
	mapa5.load(game->GetRenderer());
	//Constructor del jugador i enemigo, se passa la ubicacion de la imagen i sus datos igual que
	//el renderer donde se carga
	mosca = CMosca("../src/sprites/enemy/crab.bmp", 120, 200, 64, 64, game->GetRenderer());
	enemigos.push_back(&mosca);

	player = CPlayer("../src/sprites/pj/player.bmp", 180, 400, 64, 64, game->GetRenderer(), enemigos);
	
	
	
	//Crea un coin i lo guarda en el vector
	CCoin coin = CCoin("../src/sprites/gui/coin.bmp", 120, 200, 32, 32, game->GetRenderer());
	items.push_back(coin);
	
	//Carga todos los items
	for (int i = 0; i < items.size(); i++)
	{
		items[i].loadMedia();
	}
	
	
	//Inicialicamos la GUI i la cargamos
	GUI = CGUI(&player);
	GUI.loadMedia(game->GetRenderer());

	//Cargo la imagen del jugador i enemigo
	mosca.loadMedia(game->GetRenderer());
	player.loadMedia(game->GetRenderer());
//	item.load();

	printf("PlayState Init Successful\n");

	CColission::getRectColission(walls, &collisions, "wall");
	CColission::getRectColission(floor, &collisions, "wall");
	CColission::getRectColission(walls, &doorCollisions, "door");
	CColission::getRectColission(walls3, &collisionsMap3, "wall");
	CColission::getRectColission(walls4, &collisionsMap4, "wall");
	CColission::getRectColission(walls5, &collisionsMap5, "wall");
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
	if (player.getDead() != -1) {
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
					player.setInmortal(true);
					if (player.getVida() == 25) {
						player.setVida(0);
					}
				}
				if (event.key.keysym.sym == SDLK_c) {
					player.setCoins(player.getCoins() + 1);
					items.clear();
				}
				if (event.key.keysym.sym == SDLK_b) {
					player.setBombs(player.getBombs() + 1);
				}
				if (event.key.keysym.sym == SDLK_k) {
					player.setKeys(player.getKeys() + 1);
				}
				if (event.key.keysym.sym == SDLK_SPACE) {
					bool print;
					if (CColission::checkColission(player.getCollider(), doorCollisions, &print) && player.getKeys() >= 10) {
						printf("Porta");
						player.set_mPosY(player.get_mPosY() - 64);
						player.setKeys(player.getKeys() - 10);
					}
				}
				if (event.key.keysym.sym == SDLK_p) {
					player.set_mPosY(player.get_mPosY() + 64);
				}
			}
			//Eventos del teclado, mira que evento ha ocurrido
			player.handleEvent(event);

			//Movimiento del enemigo, se le passa las cordenadas del jugador
			//enemy.move(player.get_x(), player.get_y());
		}
		//Coje los ticks
		float timeStep = stepTimer.getTicks() / 1000.f;

#pragma region spawn
		if (room == 1) {
			//Mueve el jugador
			player.move(timeStep, collisions);
			if (items.size() > 0) {
				SDL_Rect col = player.getCollider();

				col.w = 32;
				col.y = col.y + 32;

				for (int i = 0; i < items.size(); i++)
				{

					if (CColission::checkColission(items[i].getCollider(), col)) {
						player.setCoins(player.getCoins() + 1);
						items.erase(items.begin() + i);
					}
				}
			}
			if (player.get_mPosX() < 0 || player.get_mPosY() < 0) {
				room = 2;
				player.set_mPosX(200);
				player.set_mPosY(200);
			}
			if (player.get_mPosX() > 850 && room == 1) {
				room = 3;
				player.set_mPosX(23);
				player.set_mPosY(276);
			}
			if (player.get_mPosY() > 650 && room == 1) {
				room = 4;
				player.set_mPosX(400);
				player.set_mPosY(4);
			}

			mosca.move(timeStep, collisions, player.getZonaSegura(), &player);
			//Reinicia el timer
			stepTimer.start();

			//animacion del personaje
			player.animation();


			for (int i = 0; i < enemigos.size(); i++)
			{
				enemigos.at(i)->animation();
				enemigos.at(i)->shiftColliders();
			}
			//mosca.animation();

			//mosca.shiftColliders();
			//moscaGlobal = mosca;
		}

#pragma endregion
#pragma region room2
		else if (room == 2) {
			//Mueve el jugador
			player.move(timeStep, collisions);
			if (items.size() > 0) {
				SDL_Rect col = player.getCollider();

				col.w = 32;
				col.y = col.y + 32;

				for (int i = 0; i < items.size(); i++)
				{

					if (CColission::checkColission(items[i].getCollider(), col)) {
						player.setCoins(player.getCoins() + 1);
						items.erase(items.begin() + i);
					}
				}
			}


			mosca.move(timeStep, collisions, player.getZonaSegura(), &player);
			//Reinicia el timer
			stepTimer.start();

			//animacion del personaje
			player.animation();
			mosca.animation();

			mosca.shiftColliders();
			//moscaGlobal = mosca;
		}
#pragma endregion
#pragma region room3
		else if (room == 3) {
			//Mueve el jugador
			player.move(timeStep, collisionsMap3);
			
			if (player.get_mPosX() < 0 && room == 3) {
				room = 1;
				player.set_mPosX(743);
				player.set_mPosY(261);
			}
			if (player.get_mPosY() > 650 && room == 3) {
				room = 5;
				player.set_mPosX(400);
				player.set_mPosY(4);
			}
			//mosca.move(timeStep, collisions, player.getZonaSegura(), &player);
			//Reinicia el timer
			stepTimer.start();

			//animacion del personaje
			player.animation();
			//mosca.animation();

			//mosca.shiftColliders();
			//moscaGlobal = mosca;
		}
#pragma endregion
#pragma region room4
		else if (room == 4) {
			//Mueve el jugador
			player.move(timeStep, collisionsMap4);

			if (player.get_mPosY() < 0 && room == 4) {
				room = 1;
				player.set_mPosX(521);
				player.set_mPosY(534);
			}
			if (player.get_mPosX() > 850) {
				room = 5;
				player.set_mPosX(23);
				player.set_mPosY(276);
			}
			//mosca.move(timeStep, collisions, player.getZonaSegura(), &player);
			//Reinicia el timer
			stepTimer.start();

			//animacion del personaje
			player.animation();
			//mosca.animation();

			//mosca.shiftColliders();
			//moscaGlobal = mosca;
		}
#pragma endregion
#pragma region room5
		else if (room == 5) {
			//Mueve el jugador
			player.move(timeStep, collisionsMap5);

			if (player.get_mPosX() < 0) {
				room = 4;
				player.set_mPosX(743);
				player.set_mPosY(261);
			}
			if (player.get_mPosY() < 0) {
				room = 3;
				player.set_mPosX(365);
				player.set_mPosY(537);
			}
			//mosca.move(timeStep, collisions, player.getZonaSegura(), &player);
			//Reinicia el timer
			stepTimer.start();

			//animacion del personaje
			player.animation();
			//mosca.animation();

			//mosca.shiftColliders();
		}
#pragma endregion

	}
}

void PlayState::Update(Game* game)
{
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(music.getMusicPartida(), -1);
	}

	enemigos = player.getEnemigos();
}

void PlayState::Draw(Game* game)
{
	SDL_RenderClear(game->GetRenderer());
	//Dibuja el mapa
#pragma region spawn


	if (room == 1) {
		mapa.draw(game->GetRenderer(), floor);

		//Dibuja el enemigo
		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos.at(i)->render(game->GetRenderer());
		}
		//mosca.render(game->GetRenderer());

		//Dibuja el personaje
		player.render(game->GetRenderer());

		mapa.draw(game->GetRenderer(), walls);

		//recorre todos los items i los dibuja
		for (int i = 0; i < items.size(); i++)
		{
			items[i].render();
		}

	}

#pragma endregion
#pragma region room2



	else if (room == 2) {
		mapa2.draw(game->GetRenderer(), floor2);

		//Dibuja el enemigo
		mosca.render(game->GetRenderer());

		//Dibuja el personaje
		player.render(game->GetRenderer());

		mapa2.draw(game->GetRenderer(), walls2);

		//recorre todos los items i los dibuja
		for (int i = 0; i < items.size(); i++)
		{
			items[i].render();
		}
	}
#pragma endregion
#pragma region room3



	else if (room == 3) {
		mapa3.draw(game->GetRenderer(), floor3);
		//Dibuja el enemigo

		//Dibuja el personaje
		player.render(game->GetRenderer());

		mapa3.draw(game->GetRenderer(), walls3);

	}
#pragma endregion

#pragma region room4
	else if (room == 4) {
		mapa4.draw(game->GetRenderer(), floor4);
		//Dibuja el enemigo

		//Dibuja el personaje
		player.render(game->GetRenderer());

		mapa4.draw(game->GetRenderer(), walls4);

	}
#pragma endregion
#pragma region room5
	else if (room == 5) {
		mapa5.draw(game->GetRenderer(), floor5);
		//Dibuja el enemigo

		//Dibuja el personaje
		player.render(game->GetRenderer());

		mapa5.draw(game->GetRenderer(), walls5);

	}
#pragma endregion

	if (player.getPrint()) {
		player.render(game->GetRenderer());
	}
	if (mosca.getPrint()) {
		mosca.render(game->GetRenderer());
	}

	avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
	if (avgFPS > 2000000) {
		avgFPS = 0;
	}



	GUI.drawGUI(game->GetRenderer(), avgFPS);

	//Implanta los elementos en la pantalla
	SDL_RenderPresent(game->GetRenderer());
	++countedFrames;
}
