#include "Entity.h"
#include "Sprite.h"


CEntity::CEntity()
{
}

CEntity::CEntity(char * file, int x, int y, int hight, int width, SDL_Renderer * window)
{
	this->file = file;
	this->x = x;
	this->y = y;
	this->hight = hight;
	this->width = width;
	this->window = window;
}


CEntity::~CEntity()
{
}

int CEntity::get_x()
{
	return x;
}

int CEntity::get_y()
{
	return y;
}

int CEntity::get_hight()
{
	return hight;
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

void CEntity::set_x(int x)
{
	this->x = x;
}

void CEntity::set_y(int y)
{
	this->y = y;
}

void CEntity::set_hight(int hight)
{
	this->hight = hight;
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
	Sprite::Draw(window, image, x, y, width, hight);
}
