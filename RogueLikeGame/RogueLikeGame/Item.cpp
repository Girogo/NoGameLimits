#include "Item.h"



CItem::CItem(char * ruta, int x, int y, int w, int h, SDL_Renderer * m_WindowRenderer)
{
	this->posX = x;
	this->posY = y;
	this->width = w;
	this->height = h;
	this->m_WindowRenderer = m_WindowRenderer;
	this->mCollider.h = 10;
	this->mCollider.w = 10;
	this->mCollider.x = x;
	this->mCollider.y = y;
	this->file = ruta;
}

CItem::CItem()
{
}


CItem::~CItem()
{
}

void CItem::loadMedia()
{
	texture = Sprite::Load(file, m_WindowRenderer);
}

void CItem::render()
{
	Sprite::Draw(m_WindowRenderer, texture, posX, posY, width, height);
}
