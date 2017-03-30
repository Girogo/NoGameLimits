#pragma once
#include "Enemy.h"
#include "Player.h"
class CMosca : public CEnemy
{
public:
	CMosca(char * file, int x, int y, int hight, int width, SDL_Renderer * window);
	CMosca();
	~CMosca();
	void move(float timeStep, list<CTile> wall, SDL_Rect  zonaSegura, CPlayer* player);
	void move(float timeStep, list<CTile> wall);
	bool loadMedia(SDL_Renderer* m_WindowRenderer);
	void animation();
};

