#pragma once
#include<SDL.h>
#include "Texture.h"
#include "Colission.h"

class CFireBall
{
public:
	CFireBall();
	CFireBall(float x, float y, char direccion, SDL_Renderer*  m_WindowRenderer);

	~CFireBall();

	bool loadMedia();

	void animation();

	void move(std::vector<SDL_Rect>& mCollidersFornt);

	void render();

	bool colision(std::vector<SDL_Rect>& mCollidersFornt);

	//Gets the collision boxes
	std::vector<SDL_Rect>& getCollidersFront();

private:

	float x;
	float y;
	float xIni;
	float yIni;
	char direccion;
	int frame = 0;
	int cont = 0;
	SDL_Renderer* m_WindowRenderer;

	static const int ANIMATION_FRAMES = 64;
	CTexture gSpriteSheetTexture;
	SDL_Rect gSpriteClips[ANIMATION_FRAMES];

	//Player collision boxes
	std::vector<SDL_Rect> mCollidersFront;
	//Moves the collision boxes relative to the dot's offset
	void shiftColliders();
};

