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
	static bool checkColission(SDL_Rect a, list<CTile> list, bool* print);
	static void getRectColission(CTile tiles[], list<CTile>* list, char* id);
};

