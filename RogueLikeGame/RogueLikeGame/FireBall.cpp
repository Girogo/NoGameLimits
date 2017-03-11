#include "FireBall.h"

CFireBall::CFireBall(){}
CFireBall::CFireBall(float x, float y, char direccion, SDL_Renderer*  m_WindowRenderer)
{
	this->x					= x;
	this->y					= y;
	this->direccion			= direccion;
	this->m_WindowRenderer	= m_WindowRenderer;

}

CFireBall::~CFireBall()
{
}

bool CFireBall::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture | MOVIMIENTO
	if (!gSpriteSheetTexture.loadFromFile("../src/sprites/attack/fireball_02.bmp", m_WindowRenderer))
	{
		printf("Failed to load animation texture!\n");
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 64;
		gSpriteClips[0].h = 64;

		gSpriteClips[1].x = 64;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 64;
		gSpriteClips[1].h = 64;

		gSpriteClips[2].x = 128;
		gSpriteClips[2].y = 0;
		gSpriteClips[2].w = 64;
		gSpriteClips[2].h = 64;

		gSpriteClips[3].x = 192;
		gSpriteClips[3].y = 0;
		gSpriteClips[3].w = 64;
		gSpriteClips[3].h = 64;

		gSpriteClips[4].x = 256;
		gSpriteClips[4].y = 0;
		gSpriteClips[4].w = 64;
		gSpriteClips[4].h = 64;

		gSpriteClips[5].x = 320;
		gSpriteClips[5].y = 0;
		gSpriteClips[5].w = 64;
		gSpriteClips[5].h = 64;

		gSpriteClips[6].x = 384;
		gSpriteClips[6].y = 0;
		gSpriteClips[6].w = 64;
		gSpriteClips[6].h = 64;

		gSpriteClips[7].x = 448;
		gSpriteClips[7].y = 0;
		gSpriteClips[7].w = 64;
		gSpriteClips[7].h = 64;

		gSpriteClips[8].x = 0;
		gSpriteClips[8].y = 64;
		gSpriteClips[8].w = 64;
		gSpriteClips[8].h = 64;

		gSpriteClips[9].x = 64;
		gSpriteClips[9].y = 64;
		gSpriteClips[9].w = 64;
		gSpriteClips[9].h = 64;

		gSpriteClips[10].x = 128;
		gSpriteClips[10].y = 64;
		gSpriteClips[10].w = 64;
		gSpriteClips[10].h = 64;

		gSpriteClips[11].x = 192;
		gSpriteClips[11].y = 64;
		gSpriteClips[11].w = 64;
		gSpriteClips[11].h = 64;

		gSpriteClips[12].x = 256;
		gSpriteClips[12].y = 64;
		gSpriteClips[12].w = 64;
		gSpriteClips[12].h = 64;

		gSpriteClips[13].x = 320;
		gSpriteClips[13].y = 64;
		gSpriteClips[13].w = 64;
		gSpriteClips[13].h = 64;

		gSpriteClips[14].x = 384;
		gSpriteClips[14].y = 64;
		gSpriteClips[14].w = 64;
		gSpriteClips[14].h = 64;

		gSpriteClips[15].x = 448;
		gSpriteClips[15].y = 64;
		gSpriteClips[15].w = 64;
		gSpriteClips[15].h = 64;

		gSpriteClips[16].x = 0;
		gSpriteClips[16].y = 128;
		gSpriteClips[16].w = 64;
		gSpriteClips[16].h = 64;

		gSpriteClips[17].x = 64;
		gSpriteClips[17].y = 128;
		gSpriteClips[17].w = 64;
		gSpriteClips[17].h = 64;

		gSpriteClips[18].x = 128;
		gSpriteClips[18].y = 128;
		gSpriteClips[18].w = 64;
		gSpriteClips[18].h = 64;

		gSpriteClips[19].x = 192;
		gSpriteClips[19].y = 128;
		gSpriteClips[19].w = 64;
		gSpriteClips[19].h = 64;

		gSpriteClips[20].x = 256;
		gSpriteClips[20].y = 128;
		gSpriteClips[20].w = 64;
		gSpriteClips[20].h = 64;

		gSpriteClips[21].x = 320;
		gSpriteClips[21].y = 128;
		gSpriteClips[21].w = 64;
		gSpriteClips[21].h = 64;

		gSpriteClips[22].x = 384;
		gSpriteClips[22].y = 128;
		gSpriteClips[22].w = 64;
		gSpriteClips[22].h = 64;

		gSpriteClips[23].x = 448;
		gSpriteClips[23].y = 128;
		gSpriteClips[23].w = 64;
		gSpriteClips[23].h = 64;

		gSpriteClips[24].x = 0;
		gSpriteClips[24].y = 192;
		gSpriteClips[24].w = 64;
		gSpriteClips[24].h = 64;

		gSpriteClips[25].x = 64;
		gSpriteClips[25].y = 192;
		gSpriteClips[25].w = 64;
		gSpriteClips[25].h = 64;

		gSpriteClips[26].x = 128;
		gSpriteClips[26].y = 192;
		gSpriteClips[26].w = 64;
		gSpriteClips[26].h = 64;

		gSpriteClips[27].x = 192;
		gSpriteClips[27].y = 192;
		gSpriteClips[27].w = 64;
		gSpriteClips[27].h = 64;

		gSpriteClips[28].x = 256;
		gSpriteClips[28].y = 192;
		gSpriteClips[28].w = 64;
		gSpriteClips[28].h = 64;

		gSpriteClips[29].x = 320;
		gSpriteClips[29].y = 192;
		gSpriteClips[29].w = 64;
		gSpriteClips[29].h = 64;

		gSpriteClips[30].x = 384;
		gSpriteClips[30].y = 192;
		gSpriteClips[30].w = 64;
		gSpriteClips[30].h = 64;

		gSpriteClips[31].x = 448;
		gSpriteClips[31].y = 192;
		gSpriteClips[31].w = 64;
		gSpriteClips[31].h = 64;

		gSpriteClips[32].x = 0;
		gSpriteClips[32].y = 256;
		gSpriteClips[32].w = 64;
		gSpriteClips[32].h = 64;

		gSpriteClips[33].x = 64;
		gSpriteClips[33].y = 256;
		gSpriteClips[33].w = 64;
		gSpriteClips[33].h = 64;

		gSpriteClips[34].x = 128;
		gSpriteClips[34].y = 256;
		gSpriteClips[34].w = 64;
		gSpriteClips[34].h = 64;

		gSpriteClips[35].x = 192;
		gSpriteClips[35].y = 256;
		gSpriteClips[35].w = 64;
		gSpriteClips[35].h = 64;

		gSpriteClips[36].x = 256;
		gSpriteClips[36].y = 256;
		gSpriteClips[36].w = 64;
		gSpriteClips[36].h = 64;

		gSpriteClips[37].x = 320;
		gSpriteClips[37].y = 256;
		gSpriteClips[37].w = 64;
		gSpriteClips[37].h = 64;

		gSpriteClips[38].x = 384;
		gSpriteClips[38].y = 256;
		gSpriteClips[38].w = 64;
		gSpriteClips[38].h = 64;

		gSpriteClips[39].x = 448;
		gSpriteClips[39].y = 256;
		gSpriteClips[39].w = 64;
		gSpriteClips[39].h = 64;

		gSpriteClips[40].x = 0;
		gSpriteClips[40].y = 320;
		gSpriteClips[40].w = 64;
		gSpriteClips[40].h = 64;

		gSpriteClips[41].x = 64;
		gSpriteClips[41].y = 320;
		gSpriteClips[41].w = 64;
		gSpriteClips[41].h = 64;

		gSpriteClips[42].x = 128;
		gSpriteClips[42].y = 320;
		gSpriteClips[42].w = 64;
		gSpriteClips[42].h = 64;

		gSpriteClips[43].x = 192;
		gSpriteClips[43].y = 320;
		gSpriteClips[43].w = 64;
		gSpriteClips[43].h = 64;

		gSpriteClips[44].x = 256;
		gSpriteClips[44].y = 320;
		gSpriteClips[44].w = 64;
		gSpriteClips[44].h = 64;

		gSpriteClips[45].x = 320;
		gSpriteClips[45].y = 320;
		gSpriteClips[45].w = 64;
		gSpriteClips[45].h = 64;

		gSpriteClips[46].x = 384;
		gSpriteClips[46].y = 320;
		gSpriteClips[46].w = 64;
		gSpriteClips[46].h = 64;

		gSpriteClips[47].x = 448;
		gSpriteClips[47].y = 320;
		gSpriteClips[47].w = 64;
		gSpriteClips[47].h = 64;

		gSpriteClips[48].x = 0;
		gSpriteClips[48].y = 384;
		gSpriteClips[48].w = 64;
		gSpriteClips[48].h = 64;

		gSpriteClips[49].x = 64;
		gSpriteClips[49].y = 384;
		gSpriteClips[49].w = 64;
		gSpriteClips[49].h = 64;

		gSpriteClips[50].x = 128;
		gSpriteClips[50].y = 384;
		gSpriteClips[50].w = 64;
		gSpriteClips[50].h = 64;

		gSpriteClips[51].x = 192;
		gSpriteClips[51].y = 384;
		gSpriteClips[51].w = 64;
		gSpriteClips[51].h = 64;

		gSpriteClips[52].x = 256;
		gSpriteClips[52].y = 384;
		gSpriteClips[52].w = 64;
		gSpriteClips[52].h = 64;

		gSpriteClips[53].x = 320;
		gSpriteClips[53].y = 384;
		gSpriteClips[53].w = 64;
		gSpriteClips[53].h = 64;

		gSpriteClips[54].x = 384;
		gSpriteClips[54].y = 384;
		gSpriteClips[54].w = 64;
		gSpriteClips[54].h = 64;

		gSpriteClips[55].x = 448;
		gSpriteClips[55].y = 384;
		gSpriteClips[55].w = 64;
		gSpriteClips[55].h = 64;

		gSpriteClips[56].x = 0;
		gSpriteClips[56].y = 448;
		gSpriteClips[56].w = 64;
		gSpriteClips[56].h = 64;

		gSpriteClips[57].x = 64;
		gSpriteClips[57].y = 448;
		gSpriteClips[57].w = 64;
		gSpriteClips[57].h = 64;

		gSpriteClips[58].x = 128;
		gSpriteClips[58].y = 448;
		gSpriteClips[58].w = 64;
		gSpriteClips[58].h = 64;

		gSpriteClips[59].x = 192;
		gSpriteClips[59].y = 448;
		gSpriteClips[59].w = 64;
		gSpriteClips[59].h = 64;

		gSpriteClips[60].x = 256;
		gSpriteClips[60].y = 448;
		gSpriteClips[60].w = 64;
		gSpriteClips[60].h = 64;

		gSpriteClips[61].x = 320;
		gSpriteClips[61].y = 448;
		gSpriteClips[61].w = 64;
		gSpriteClips[61].h = 64;

		gSpriteClips[62].x = 384;
		gSpriteClips[62].y = 448;
		gSpriteClips[62].w = 64;
		gSpriteClips[62].h = 64;

		gSpriteClips[63].x = 448;
		gSpriteClips[63].y = 448;
		gSpriteClips[63].w = 64;
		gSpriteClips[63].h = 64;
	}

	return success;
}

void CFireBall::animation() {

	switch (direccion) {

		// 0 - 7
	case 'L':
		if (frame > 6) {
			frame = 0;
		}
		if (frame < 7 && cont == 1) {
			frame++;
		}
		break;

	case 'U':
		//16-23 inc
		if (frame > 22 || frame < 16) {
			frame = 16;
		}
		if (frame < 23 && cont == 1)
		{
			frame++;
		}

		/*if (frame == 0) {
			frame++;
		}*/
		break;

		//32 - 39
	case 'R':

		if (frame > 38 || frame < 32) {
			frame = 32;
		}
		if (frame < 39 && cont == 1) {
			frame++;
		}
		break;
	
		//48 - 55
	case 'D':
		if (frame > 54 || frame < 48) {
			frame = 48;
		}
		if (frame < 55 && cont == 1) {
			frame++;
		}

		/*
		if (frame == 18) {
			frame++;
		}*/
		break;

		
	}

	//Velocidad de transición entre frames.
	if (cont > 10) {
		cont = 0;
	}
	cont++;
}

void CFireBall::move(){

	switch (direccion) {
		//UP
	case 'U':
		y -= 5;
		break;
		//LEFT
	case 'L':
		x -= 5;
		break;
		//DOWN
	case 'D':
		y += 5;
		break;
		//RIGHT
	case 'R':
		x += 5;
		break;

	}
}
void CFireBall::render() {

	SDL_Rect* currentClip = &gSpriteClips[frame];

	gSpriteSheetTexture.render((int)x, (int)y, currentClip, m_WindowRenderer);

}

bool CFireBall::colision() {
	//If colision con enemigo -X de vida
	//If colision con objeto delete
	return true;
}