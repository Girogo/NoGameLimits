
#include "PlayState.h"

PlayState PlayState::m_PlayState;
void PlayState::Init(Game* game)
{
	//Limpia el renderer
	SDL_RenderClear(game->GetRenderer());
	

	//Cargamos Elementos del mapa i las tiles
	mapa = CMapa();

	//Se passa como parametros Array de tiles, Numero de casillas de tiles que tiene el mapa, tamaño de las tyles
	//numero de columnas del mapa, numero de filas del mapa, total de id del tileset
	mapa.setTiles(floor, 130, 64, 64, 13, 10, 21, "../src/maps/m1.map");
	mapa.setTiles(walls, 130, 64, 64, 13, 10, 21, "../src/maps/m2.map");

	mapa.load(game->GetRenderer());

	//Constructor del jugador i enemigo, se passa la ubicacion de la imagen i sus datos igual que
	//el renderer donde se carga
	enemy = CEnemy("../src/sprites/enemy/crab.bmp", 120, 200, 64, 64, game->GetRenderer());
	player = CPlayer("../src/sprites/pj/player.bmp", 200, 200, 64, 64, game->GetRenderer());


	//Inicialicamos la GUI i la cargamos
	GUI = CGUI(&player);
	GUI.loadMedia(game->GetRenderer());

	//Cargo la imagen del jugador i enemigo
	enemy.load();
	player.loadMedia(game->GetRenderer());

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

	while (SDL_PollEvent(&event) != 0) {

		if (event.type == SDL_QUIT) {
			game->Quit();
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_SPACE) {
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
	player.move(timeStep);

	//Reinicia el timer
	stepTimer.start();

	//animacion del personaje
	player.animation();
}

void PlayState::Update(Game* game)
{
}

void PlayState::Draw(Game* game)
{
	SDL_RenderClear(game->GetRenderer());
	//Dibuja el mapa
	
	mapa.draw(game->GetRenderer(), floor);
	mapa.draw(game->GetRenderer(), walls);
	
	//Dibuja el enemigo
	enemy.draw();

	//Dibuja el personaje
	player.render(game->GetRenderer());

	//playerAttacks = player.getAttacks();
	/*for (CFireBall &fb : playerAttacks) {
		//fb.animation();
		//fb.move();
		fb.render();
	}*/
	
	GUI.drawGUI(game->GetRenderer());
	//Implanta los elementos en la pantalla
	SDL_RenderPresent(game->GetRenderer());
}
