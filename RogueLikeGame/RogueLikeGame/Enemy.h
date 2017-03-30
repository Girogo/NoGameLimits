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
};

