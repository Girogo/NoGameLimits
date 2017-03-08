#include "Colission.h"

CColission::CColission()
{
}


CColission::~CColission()
{
}

//SDL_Rect a es la posicion dle jugador, list es una lista de CTile que
//contiene todas las tiles con colision
bool CColission::checkColission(SDL_Rect a, list<SDL_Rect> lista)
{
	bool collision = true;
	int cont = 0;

	for (list<SDL_Rect>::iterator it = lista.begin(); it != lista.end(); it++) {
		collision = true;

		//The sides of the rectangles
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		//Calculate the sides of rect A
		leftA = a.x;
		rightA = a.x + a.w;
		topA = a.y;
		bottomA = a.y + a.h;

		//Calculate the sides of rect B
		leftB = it->x;
		rightB = it->x + it->w;
		topB = it->y;
		bottomB = it->y + it->h;

		//If any of the sides from A are outside of B
		if (bottomA <= topB)
		{
			collision = false;
		}

		if (topA >= bottomB)
		{
			collision = false;
		}

		if (rightA <= leftB)
		{
			collision = false;
		}

		if (leftA >= rightB)
		{
			collision = false;
		}

		if (collision) {
			cont++;
		}
	}
	//If none of the sides from A are outside B
	if (cont != 0) {
		return true;
	}
	else {
		return false;
	}
}

void CColission::getRectColission(CTile tiles[], list<SDL_Rect>* list, char* id)
{
	for (int i = 0; i < 130; i++)
	{
		if (tiles[i].getTipo() == id) {
			list->push_back(tiles[i].getRectDestino());
		}
	}
}
