#pragma once
#include <SDL.h>
#include<time.h>
#include "Entity.h" 

class CEnemy : public CEntity
{
public:
	CEnemy(char * file, int x, int y, int hight, int width, SDL_Renderer * window);
	CEnemy();
	~CEnemy();
	void move(const Uint8 * keyboard_state_array);
	virtual void move(float timeStep, list<CTile> wall) = 0;
	virtual bool loadMedia(SDL_Renderer* m_WindowRenderer) = 0;
	virtual void animation() = 0;
protected:
	//Array con las posiciones del jugador
	int direccio, cont;
	clock_t start, diff;

	//atributos para el movimiento
	SDL_Rect col1;
	SDL_Rect col2;
	SDL_Rect col3;
	SDL_Rect col4;
	//Colider del da�o;
	SDL_Rect colDa�o;
	bool colision1, colision2, colision3, colision4;
	bool colision;
	bool focus = false;
	bool crash = false;
	bool damage = false;
};

