#ifndef _TILE_
#define _TILE

#include <string>
#include <SDL.h>

using namespace std;

class CTile

{
public:

	CTile() {};
	CTile(int Cid, int CposXDestino, int CposYDestino, int CposXOrigen, int CposYOrigen, int CwidthOrigen, int CheightOrigen, int CwidthDestino, int CheightDestino, string Ctipo);
	
	//void renderTile(CTile tiles[], CMapa mapa, SDL_Renderer* m_WindowRenderer);
	int getWidth() { return width; }
	int getHeight() { return height; }

	int getposX() { return posX; }
	int getposY() { return posY; }

	int getpixelX() { return pixelX; }
	int getpixelY() { return pixelY; }

	SDL_Rect getRectOrigen() { return rectOrigen; }
	SDL_Rect getRectDestino() { return rectDestino; }

	std::string getTipo() { return tipo; }

private:
	int id, posX, posY, pixelX, pixelY, width, height;
	SDL_Rect rectOrigen;
	SDL_Rect rectDestino;
	string tipo;
	
};
#endif
