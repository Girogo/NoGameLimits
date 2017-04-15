#pragma once
#include "Item.h"
class CCoin :
	public CItem
{
public:
	CCoin(char* ruta, int x, int y, int w, int h, SDL_Renderer* m_WindowRenderer);
	~CCoin();
};

