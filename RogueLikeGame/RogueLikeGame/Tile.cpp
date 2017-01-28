#include "Tile.h"

CTile::CTile(int Cid, int CposXDestino, int CposYDestino, int CposXOrigen, int CposYOrigen, int CwidthOrigen, int CheightOrigen, int CwidthDestino, int CheightDestino, string Ctipo)
{
	id = Cid;

	posX = CposXDestino;
	posY = CposYDestino;

	rectOrigen.x = CposXOrigen;
	rectOrigen.y = CposYOrigen;
	rectOrigen.w = CwidthOrigen;
	rectOrigen.h = CheightOrigen;

	rectDestino.x = CposXDestino;
	rectDestino.y = CposYDestino;
	rectDestino.w = CwidthDestino;
	rectDestino.h = CwidthDestino;

	tipo = Ctipo;

}


