#pragma once
#include <SDL.h>
#include <list>
#include "Tile.h"
#include <vector>
using namespace std;
class CColission
{
public:
	CColission();
	~CColission();
	static bool checkColission(SDL_Rect a, list<CTile> list, bool* print);
	static void getRectColission(CTile tiles[], list<CTile>* list, char* id);
	static bool checkColission(SDL_Rect a, SDL_Rect b);
	//Box set collision detector
	static bool checkCollisionPixel(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>& b);
};

