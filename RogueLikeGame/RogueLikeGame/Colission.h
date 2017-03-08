#pragma once
#include <SDL.h>
#include <list>
#include "Tile.h"
using namespace std;
class CColission
{
public:
	CColission();
	~CColission();
	static bool checkColission(SDL_Rect a, list<SDL_Rect> list);
	static void getRectColission(CTile tiles[], list<SDL_Rect>* list, char* id);
};

