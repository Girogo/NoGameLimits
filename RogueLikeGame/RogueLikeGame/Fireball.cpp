#include "FireBall.h"
#include "Mosca.h"


CFireBall::CFireBall() {}
CFireBall::CFireBall(float x, float y, char direccion, SDL_Renderer*  m_WindowRenderer)
{
	this->x = x;
	this->xIni = x;
	this->y = y;
	this->yIni = y;
	this->direccion = direccion;
	this->m_WindowRenderer = m_WindowRenderer;


	//Load sprite sheet texture | MOVIMIENTO
	if (!gSpriteSheetTexture.loadFromFile("../src/sprites/attack/fireball_02.bmp", m_WindowRenderer))
	{
		printf("Failed to load animation texture!\n");
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

	//Create the necessary SDL_Rects frontalment
	mCollidersFront.resize(9);

	//Create the necessary SDL_Rects lateral
	//mCollidersLateral.resize(31);

	//Initialize the collision boxes' width and height for front walk
	mCollidersFront[0].w = 14;
	mCollidersFront[0].h = 1;

	mCollidersFront[1].w = 38;
	mCollidersFront[1].h = 2;

	mCollidersFront[2].w = 40;
	mCollidersFront[2].h = 1;

	mCollidersFront[3].w = 42;
	mCollidersFront[3].h = 1;

	mCollidersFront[4].w = 44;
	mCollidersFront[4].h = 1;

	mCollidersFront[5].w = 41;
	mCollidersFront[5].h = 1;

	mCollidersFront[6].w = 42;
	mCollidersFront[6].h = 4;

	mCollidersFront[7].w = 20;
	mCollidersFront[7].h = 1;

	mCollidersFront[8].w = 15;
	mCollidersFront[8].h = 1;

	//Initialize the collision boxes' width and height from lateral walk
	/*mCollidersLateral[0].w = 10;
	mCollidersLateral[0].h = 1;

	mCollidersLateral[1].w = 12;
	mCollidersLateral[1].h = 1;

	mCollidersLateral[2].w = 14;
	mCollidersLateral[2].h = 2;

	mCollidersLateral[3].w = 16;
	mCollidersLateral[3].h = 2;

	mCollidersLateral[4].w = 18;
	mCollidersLateral[4].h = 1;

	mCollidersLateral[5].w = 20;
	mCollidersLateral[5].h = 3;

	mCollidersLateral[6].w = 22;
	mCollidersLateral[6].h = 1;

	mCollidersLateral[7].w = 24;
	mCollidersLateral[7].h = 1;

	mCollidersLateral[8].w = 30;
	mCollidersLateral[8].h = 2;

	mCollidersLateral[9].w = 28;
	mCollidersLateral[9].h = 1;

	mCollidersLateral[10].w = 26;
	mCollidersLateral[10].h = 1;

	mCollidersLateral[11].w = 22;
	mCollidersLateral[11].h = 1;

	mCollidersLateral[12].w = 18;
	mCollidersLateral[12].h = 5;

	mCollidersLateral[13].w = 18;
	mCollidersLateral[13].h = 2;

	mCollidersLateral[14].w = 16;
	mCollidersLateral[14].h = 1;

	mCollidersLateral[15].w = 18;
	mCollidersLateral[15].h = 1;

	mCollidersLateral[16].w = 19;
	mCollidersLateral[16].h = 1;

	mCollidersLateral[17].w = 20;
	mCollidersLateral[17].h = 3;

	mCollidersLateral[18].w = 20;
	mCollidersLateral[18].h = 5;

	mCollidersLateral[19].w = 20;
	mCollidersLateral[19].h = 2;

	mCollidersLateral[20].w = 20;
	mCollidersLateral[20].h = 4;

	mCollidersLateral[21].w = 18;
	mCollidersLateral[21].h = 1;

	mCollidersLateral[22].w = 16;
	mCollidersLateral[22].h = 1;

	mCollidersLateral[23].w = 15;
	mCollidersLateral[23].h = 1;

	mCollidersLateral[24].w = 14;
	mCollidersLateral[24].h = 3;

	mCollidersLateral[25].w = 13;
	mCollidersLateral[25].h = 1;

	mCollidersLateral[26].w = 14;
	mCollidersLateral[26].h = 1;

	mCollidersLateral[27].w = 16;
	mCollidersLateral[27].h = 1;

	mCollidersLateral[28].w = 17;
	mCollidersLateral[28].h = 3;

	mCollidersLateral[29].w = 9;
	mCollidersLateral[29].h = 1;

	mCollidersLateral[30].w = 7;
	mCollidersLateral[30].h = 1;*/

	//Initialize colliders relative to position
	shiftColliders();

}

CFireBall::~CFireBall()
{
}
/*
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
}*/

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

void CFireBall::move(std::vector<SDL_Rect>& mCollidersForntE) {
	int vel = 5;
	switch (direccion) {
		//UP
	case 'U':
		y -= vel;
		shiftColliders();

		//If the dot collided or went too far to the left or right
		if (CColission::checkCollisionPixel(mCollidersFront, mCollidersForntE))
		{
			//Move back
			shiftColliders();
			printf("FUNCIONA");

		}
		break;
		//LEFT
	case 'L':
		x -= vel;
		shiftColliders();

		//If the dot collided or went too far to the left or right
		if (CColission::checkCollisionPixel(mCollidersFront, mCollidersForntE))
		{
			//Move back
			shiftColliders();
			printf("FUNCIONA");

		}
		break;
		//DOWN
	case 'D':
		y += vel;
		shiftColliders();

		//If the dot collided or went too far to the left or right
		if (CColission::checkCollisionPixel(mCollidersFront, mCollidersForntE))
		{
			//Move back
			shiftColliders();
			printf("FUNCIONA");

		}
		break;
		//RIGHT
	case 'R':
		x += vel;
		shiftColliders();

		//If the dot collided or went too far to the left or right
		if (CColission::checkCollisionPixel(mCollidersFront, mCollidersForntE))
		{
			//Move back
			shiftColliders();
			printf("FUNCIONA");
		}
		break;

	}
}
void CFireBall::render() {

	SDL_Rect* currentClip = &gSpriteClips[frame];

	gSpriteSheetTexture.render((int)x, (int)y, currentClip, m_WindowRenderer);

}

CMosca mosca;

bool CFireBall::colision(std::vector<SDL_Rect>& mCollidersForntE) {

	if (CColission::checkCollisionPixel(mCollidersFront, mCollidersForntE))
	{
		return true;
		printf("COLISION");

	}
	else {
		return false;
	}
	/*
	int dist = 500;
	if (x == xIni - dist)
	return true;
	else if (x == xIni + dist)
	return true;
	else if (y == yIni - dist)
	return true;
	else if (y == yIni + dist)
	return true;
	else return false;
	*/
}

std::vector<SDL_Rect>& CFireBall::getCollidersFront()
{
	return mCollidersFront;
}

void CFireBall::shiftColliders()
{
	//The row offset
	int r = 0;

	//Go through the dot's collision boxes
	for (int set = 0; set < mCollidersFront.size(); ++set)
	{
		//Center the collision box
		mCollidersFront[set].x = (int)x + (mCollidersFront[set].w) / 2;

		//Set the collision box at its row offset
		mCollidersFront[set].y = (int)y + r;

		//Move the row offset down the height of the collision box
		r += mCollidersFront[set].h;
	}
}