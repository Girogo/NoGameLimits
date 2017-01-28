#pragma once
#include<SDL.h>
#include"Sprite.h"
#include "Entity.h"
class CPlayer : public CEntity
{
public:
	CPlayer(char * file, int x, int y, int hight, int width, SDL_Renderer* window);
	CPlayer();
	void move(SDL_Event evento);
	void move(int x, int y);

private:
};

