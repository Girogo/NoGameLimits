#pragma once
#include<SDL.h>
#include "Texture.h"

class CFireBall
{
public:
	CFireBall();
	CFireBall(float x, float y, char direccion, SDL_Renderer*  m_WindowRenderer);

	~CFireBall();

	bool loadMedia();

	void animation();

	void move();

	void render();

	bool colision();

private:

	float x;
	float y;
	char direccion;
	int frame = 0;
	int cont = 0;
	SDL_Renderer* m_WindowRenderer;

	static const int ANIMATION_FRAMES = 64;
	CTexture gSpriteSheetTexture;
	SDL_Rect gSpriteClips[ANIMATION_FRAMES];
};

