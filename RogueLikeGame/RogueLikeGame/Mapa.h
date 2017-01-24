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
	CMapa (char* mapSrc);
	
	bool setTiles (CTile CtileSet[]);

	void renderMap(CTile tiles[], SDL_Renderer* m_WindowRenderer);

	std::string getMapa() { return rutaMapa; }

private:

	char* rutaMapa = "../src/maps/";
	std::vector <CTile> tileSet;
	//std::ifstream ifs;



	
};
#endif