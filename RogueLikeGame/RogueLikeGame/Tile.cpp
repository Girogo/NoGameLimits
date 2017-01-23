#include "Tile.h"

CTile::CTile(int Cid, int CposX, int CposY, int CpixelX, int CpixelY, int Cwidth, int Cheight, string Ctipo)
{
	id = Cid;

	posX = CposX;
	posY = CposY;

	rect.x = CpixelX;
	rect.y = CpixelY;
	rect.w = Cwidth;
	rect.h = Cheight;

	tipo = Ctipo;

}


