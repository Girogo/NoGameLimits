#include "Enemy.h"
#include "Entity.h"

CEnemy::CEnemy(char * file, int x, int y, int hight, int width, SDL_Renderer * window) : CEntity(file, x, y, hight, width, window)
{
	this->mVelX = 150;
	this->mVelY = 150;
	this->direccio = 0;
	this->start = clock();
}

CEnemy::CEnemy()
{
}


CEnemy::~CEnemy()
{
}


void CEnemy::move(const Uint8 *keyboard_state_array)
{

}

void CEnemy::shiftColliders(){}


