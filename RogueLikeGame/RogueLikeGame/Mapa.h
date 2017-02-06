#ifndef _MAPA_
#define _MAPA_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Sprite.h"

using json = nlohmann::json;


class CTile;

class CMapa
{

public:
	CMapa();
	bool setTiles(CTile CtileSet[], int TOTAL_TILES, int TILE_WIDTH, int TILE_HEIGHT, int TOTAL_TILESWIDTH, int TOTAL_TILESHEIGHT, int NUM_TEXTURE, char* mapSrc);

	void load(SDL_Renderer* m_WindowRenderer);

	void draw(SDL_Renderer* m_WindowRendere, CTile tiles[]);

	std::string getMapa() { return rutaMapa; }

private:

	char* rutaMapa = "../src/maps/";
	std::vector <CTile> tileSet;
	//std::ifstream ifs;

	//Se utiliza para guardar las posiciones de donde se encuentra la tile i donde la tendemos que rendarizar
	SDL_Rect posTextureOrigenFloor[168];
	SDL_Rect posTextureDestinoFloor[168];
	SDL_Rect posTextureOrigenWalls[168];
	SDL_Rect posTextureDestinoWalls[168];
	SDL_Texture* textura;

};
#endif

	
