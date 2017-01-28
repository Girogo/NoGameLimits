#include "Player.h"
#include "Entity.h"

CPlayer::CPlayer(char * file, int x, int y, int hight, int width, SDL_Renderer * window) : CEntity(file, x, y, hight, width, window)
{

}
CPlayer::CPlayer()
{
}
void CPlayer::move(SDL_Event evento) {
	switch (evento.key.keysym.sym) {

		//Eventos de teclado depende del que se clique un movimiento o otro
	case SDLK_UP:
		if (y > 20)
			//Se resta la posicion y
			y = y - 10;

		break;
	case SDLK_DOWN:
		if (y < 540)
			//Se suma la posicion y
			y = y + 10;

		break;
	case SDLK_LEFT:
		//Se resta la posicion x
		if (x > 50)
			x = x - 10;

		break;
	case SDLK_RIGHT:
		//Se resta la posicion y
		if (x < 720)
			x = x + 10;
		break;
	}
}

void CPlayer::move(int x, int y)
{
}


