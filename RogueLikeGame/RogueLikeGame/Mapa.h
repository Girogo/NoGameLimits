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
	CMapa(char* mapSrc);
	CMapa();
	bool setTiles(CTile CtileSet[]);

	void load(CTile tiles[], SDL_Renderer* m_WindowRenderer);

	void draw(SDL_Renderer* m_WindowRenderer);

	std::string getMapa() { return rutaMapa; }

private:

	char* rutaMapa = "../src/maps/";
	std::vector <CTile> tileSet;
	//std::ifstream ifs;

	//Se utiliza para guardar las posiciones de donde se encuentra la tile i donde la tendemos que rendarizar
	SDL_Rect posTextureOrigen[168];
	SDL_Rect posTextureDestino[168];
	SDL_Texture* textura;

};
#endif

	
