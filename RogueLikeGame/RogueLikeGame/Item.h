#pragma once
#include "Sprite.h"
class CItem
{
public:
	CItem(char* ruta, int x, int y, int w, int h, SDL_Renderer* m_WindowRenderer);
	CItem();
	~CItem();
	void loadMedia();
	void render();
	SDL_Rect getCollider() { return mCollider; }

private:
	int posX;
	int posY;
	int width;
	int height;
	char* file;
	SDL_Texture* texture;
	SDL_Rect mCollider;
	SDL_Renderer* m_WindowRenderer;
};

