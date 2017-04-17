#include "Entity.h"
#include "Sprite.h"


CEntity::CEntity()
{
}

CEntity::CEntity(char * file, float mPosX, float mPosY, int height, int width, SDL_Renderer * window)
{
	this->file = file;
	this->mPosX = mPosX;
	this->mPosY = mPosY;
	this->height = height;
	this->width = width;
	this->window = window;
	this->mCollider.h = this->height;
	this->mCollider.w = this->width;
	this->print = false;
	this->mCollider.x = this->mPosX;
	this->mCollider.y = this->mPosY;
	this->mCollider.h = this->height;
	this->mCollider.w = this->width;
	this->frame = 0;
}


CEntity::~CEntity()
{
}

float CEntity::get_mPosX()
{
	return mPosX;
}

float CEntity::get_mPosY()
{
	return mPosY;
}

int CEntity::get_height()
{
	return height;
}

int CEntity::get_width()
{
	return width;
}

char CEntity::get_file()
{
	return *file;
}


//Dona erroer es te que mirar, tot i que per el moment no es necessari mes endevant pot ser que ho necessitem
/*SDL_Renderer CEntity::get_window() {
return window;
}*/

void CEntity::set_mPosX(float mPosX)
{
	this->mPosX = mPosX;
}

void CEntity::set_mPosY(float mPosY)
{
	this->mPosY = mPosY;
}

void CEntity::set_height(int hight)
{
	this->height = hight;
}

void CEntity::set_width(int width)
{
	this->width = width;
}

void CEntity::set_file(char* file) {
	this->file = file;
}

void CEntity::set_window(SDL_Renderer* window) {
	this->window = window;
}

void CEntity::load()
{
	//Carga la imagen del pj
	image = Sprite::Load(file, window);
}

void CEntity::draw()
{
	//Dibuja el pj
	Sprite::Draw(window, image, (int)mPosX, (int)mPosY, width, height);
}

void CEntity::render(SDL_Renderer* m_WindowRenderer)
{
	SDL_Rect* currentClip = &gSpriteClips[frame];
	gSpriteSheetTexture.render((int)mPosX, (int)mPosY, currentClip, m_WindowRenderer);
}
