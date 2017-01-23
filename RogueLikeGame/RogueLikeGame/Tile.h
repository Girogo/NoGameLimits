#ifndef _TILE_
#define _TILE

#include <string>
#include <SDL.h>

using namespace std;

class CTile

{
public:

	CTile(int Cid, int CposX, int CposY, int CpixelX, int CpixelY, int Cwidth, int Cheight, string Ctipo);

	//void renderTile(CTile tiles[], CMapa mapa, SDL_Renderer* m_WindowRenderer);
	int getWidth() { return width; }
	int getHeight() { return height; }

	int getposX() { return posX; }
	int getposY() { return posY; }

	int getpixelX() { return pixelX; }
	int getpixelY() { return pixelY; }

private:
	int id, posX, posY, pixelX, pixelY, width, height;
	SDL_Rect rect;
	string tipo;
};
#endif
