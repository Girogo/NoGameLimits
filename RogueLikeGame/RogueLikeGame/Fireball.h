#pragma once
#include<SDL.h>
#include "Texture.h"
#include "Colission.h"
#include "Enemy.h"


class CFireBall
{
public:
	CFireBall();
	CFireBall(float x, float y, char direccion, SDL_Renderer*  m_WindowRenderer, std::vector<CEnemy*> enemigos);

	~CFireBall();

	std::vector<CEnemy*> getEnemigos() { return enemigos; }

	void loadMedia();

	void animation();


	void move();

	void render();

	bool colision();

	//Gets the collision boxes
	std::vector<SDL_Rect>& getCollidersFront();


private:

	float x;
	float y;

	SDL_Rect rectFb;
	SDL_Rect rectEnemy;

	std::vector<CEnemy*> enemigos;
	//CMosca* mosca;
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

