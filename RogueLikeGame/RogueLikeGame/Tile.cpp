#include "Tile.h"

CTile::CTile(int Cid, int CposX, int CposY, int CpixelX, int CpixelY, int Cwidth, int Cheight, string Ctipo)
{
	id = Cid;

	posX = CposX;
	posY = CposY;

	rectOrigen.x = CpixelX;
	rectOrigen.y = CpixelY;
	rectOrigen.w = Cwidth;
	rectOrigen.h = Cheight;

	rectDestino.x = CposX;
	rectDestino.y = CposY;
	rectDestino.w = Cwidth;
	rectDestino.h = Cheight;

	tipo = Ctipo;

}


