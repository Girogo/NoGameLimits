#pragma once
#include "Player.h"
#include "Entity.h"
class CItem
{
public:
	CItem(char * file, int x, int y, int hight, int width, SDL_Renderer * window);
	CItem();
	~CItem();
};

