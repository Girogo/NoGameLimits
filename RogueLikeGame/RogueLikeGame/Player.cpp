#include "Player.h"
<<<<<<< HEAD


CPlayer::CPlayer(char * file, int x, int y, int hight, int width, SDL_Renderer * window, std::vector<CEnemy*> enemigos) : CEntity(file, x, y, hight, width, window)
=======
#include "Entity.h"
#include "Mosca.h"

CPlayer::CPlayer(char * file, int x, int y, int hight, int width, SDL_Renderer * window) : CEntity(file, x, y, hight, width, window)
>>>>>>> origin/v.0.1.2-Canvi-de-sales-i-interecció-amb-objectes
{
	this->gSpriteSheetTexture = CTexture::CTexture();
	this->frame = 0;
	this->mVelX = 0;
	this->mVelY = 0;
	this->vida = 3;
	this->coins = 0;
	this->bombs = 0;
	this->keys = 0;
	this->m_WindowRenderer = window;
	this->enemigos = enemigos;
	this->zonaSegura.h = 100;
	this->zonaSegura.w = 100;

	this->zonaDany.h = 45;
	this->zonaDany.w = 33;
	this->dead = 0;
}
CPlayer::CPlayer()
{
	this->gSpriteSheetTexture = CTexture::CTexture();
	this->mVelX = 0;
	this->mVelY = 0;
	this->vida = 3;
	this->coins = 0;
	this->bombs = 0;
	this->keys = 0;
}

//Este movimiento està obsoleto, se le passaba un mapa del teclado
void CPlayer::move(const Uint8 *keyboard_state_array) {
	bool entrat = false;
	if (keyboard_state_array[SDL_SCANCODE_RIGHT] && !keyboard_state_array[SDL_SCANCODE_LEFT])
	{
		if (frame < 27 || frame > 34) {
			frame = 27;
		}
		mPosX += 5;
		if (frame < 35 && frameCont == 2) {
			frame++;
		}
		entrat = true;
	}
	else if (!keyboard_state_array[SDL_SCANCODE_RIGHT] && keyboard_state_array[SDL_SCANCODE_LEFT])
	{

		if (frame > 16 || frame < 9) {
			frame = 9;
		}
		mPosX -= 5;
		if (frame < 17 && frameCont == 2) {
			frame++;
		}
		entrat = true;
	}
	// Move centerpoint of rotation for one of the trees:
	if (keyboard_state_array[SDL_SCANCODE_UP] && !(keyboard_state_array[SDL_SCANCODE_DOWN]))
	{
		if (frame > 7 && entrat != true) {
			frame = 0;
		}
		mPosY -= 5;
		if (frame < 8 && entrat != true && frameCont == 2)
		{
			frame++;
		}

	}
	else if (!keyboard_state_array[SDL_SCANCODE_UP] && keyboard_state_array[SDL_SCANCODE_DOWN])
	{
		if ((frame > 25 || frame < 18) && entrat != true) {
			frame = 18;
		}
		mPosY += 5;
		if (frame < 26 && entrat != true && frameCont == 2) {
			frame++;
		}
	}
	frameCont++;
	if (frameCont > 2) {
		frameCont = 0;
	}


}


//eventos del teclado
void CPlayer::handleEvent(SDL_Event & e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_w: mVelY -= PLAYER_VEL;	w = true;		break;
		case SDLK_s: mVelY += PLAYER_VEL;	s = true;		break;
		case SDLK_a: mVelX -= PLAYER_VEL;	a = true;		break;
		case SDLK_d: mVelX += PLAYER_VEL;	d = true;		break;

		case SDLK_UP:						atkUP = true;		break;
		case SDLK_LEFT:						atkLEFT = true;		break;
		case SDLK_DOWN:						atkDOWN = true;		break;
		case SDLK_RIGHT:					atkRIGHT = true;		break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_w: mVelY += PLAYER_VEL;	w = false;	movimiento = false;		frame = 0;	 break;
		case SDLK_a: mVelX += PLAYER_VEL;	a = false;	movimiento = false;		frame = 9;	 break;
		case SDLK_s: mVelY -= PLAYER_VEL;	s = false;	movimiento = false;		frame = 18;  break;
		case SDLK_d: mVelX -= PLAYER_VEL;	d = false;	movimiento = false;		frame = 27;  break;

		case SDLK_UP:
			atkdirection = 'U'; if (frame == 41)attack();	battack = true;
			atkUP = false;							frame = 0;	break;

		case SDLK_LEFT:
			atkdirection = 'L'; if (frame == 48)attack();	battack = true;
			atkLEFT = false;							frame = 9;	break;

		case SDLK_DOWN:
			atkdirection = 'D'; if (frame == 55)attack();	battack = true;
			atkDOWN = false;							frame = 18;	break;

		case SDLK_RIGHT:
			atkdirection = 'R'; if (frame == 62)attack();	battack = true;
			atkRIGHT = false;							frame = 27; break;
		}
	}

}


//movimiento fluido
void CPlayer::move(float timeStep)
{
	if (vida > 0) {
		//Move the dot left or right
		mPosX += mVelX * timeStep;

		//If the dot went too far to the left or right
		if (mPosX < 0)
		{
			mPosX = 0;
		}
		else if (mPosX > 850 - width)
		{
			mPosX = 850 - width;
		}

		//Move the dot up or down
		mPosY += mVelY * timeStep;

		//If the dot went too far up or down
		if (mPosY < 0)
		{
			mPosY = 0;
		}
		else if (mPosY > 650 - height)
		{
			mPosY = 650 - height;
		}
	}

}
void CPlayer::move(float timeStep, list<CTile> wall)
{
	if (vida > 0) {
		//Move the dot left or right
		mPosX += mVelX * timeStep;
		mCollider.x = mPosX;
		//If the dot collided or went too far to the left or right
		if (CColission::checkColission(mCollider, wall, &print))
		{
			//Move back
			mPosX -= mVelX * timeStep;
			mCollider.x = mPosX;
		}

		//Move the dot up or down
		mPosY += mVelY * timeStep;
		mCollider.y = mPosY;

		//If the dot collided or went too far up or down
		if (CColission::checkColission(mCollider, wall, &print))
		{
			//Move back
			mPosY -= mVelY * timeStep;
			mCollider.y = mPosY;
		}
		zonaSegura.x = mPosX;
		zonaSegura.y = mPosY;
		zonaDany.x = mPosX;
		zonaDany.y = mPosY;

	}
}

//Carga todas las sprites
bool CPlayer::loadMedia(SDL_Renderer* m_WindowRenderer)
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture | MOVIMIENTO
	if (!gSpriteSheetTexture.loadFromFile("../src/sprites/pj/player.bmp", m_WindowRenderer))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		//Set sprite clips || MOVIMIENTO
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

		gSpriteClips[8].x = 512;
		gSpriteClips[8].y = 0;
		gSpriteClips[8].w = 64;
		gSpriteClips[8].h = 64;

		gSpriteClips[9].x = 0;
		gSpriteClips[9].y = 64;
		gSpriteClips[9].w = 64;
		gSpriteClips[9].h = 64;

		gSpriteClips[10].x = 64;
		gSpriteClips[10].y = 64;
		gSpriteClips[10].w = 64;
		gSpriteClips[10].h = 64;

		gSpriteClips[11].x = 128;
		gSpriteClips[11].y = 64;
		gSpriteClips[11].w = 64;
		gSpriteClips[11].h = 64;

		gSpriteClips[12].x = 192;
		gSpriteClips[12].y = 64;
		gSpriteClips[12].w = 64;
		gSpriteClips[12].h = 64;

		gSpriteClips[13].x = 256;
		gSpriteClips[13].y = 64;
		gSpriteClips[13].w = 64;
		gSpriteClips[13].h = 64;

		gSpriteClips[14].x = 320;
		gSpriteClips[14].y = 64;
		gSpriteClips[14].w = 64;
		gSpriteClips[14].h = 64;

		gSpriteClips[15].x = 384;
		gSpriteClips[15].y = 64;
		gSpriteClips[15].w = 64;
		gSpriteClips[15].h = 64;

		gSpriteClips[16].x = 448;
		gSpriteClips[16].y = 64;
		gSpriteClips[16].w = 64;
		gSpriteClips[16].h = 64;

		gSpriteClips[17].x = 512;
		gSpriteClips[17].y = 64;
		gSpriteClips[17].w = 64;
		gSpriteClips[17].h = 64;

		gSpriteClips[18].x = 0;
		gSpriteClips[18].y = 128;
		gSpriteClips[18].w = 64;
		gSpriteClips[18].h = 64;

		gSpriteClips[19].x = 64;
		gSpriteClips[19].y = 128;
		gSpriteClips[19].w = 64;
		gSpriteClips[19].h = 64;

		gSpriteClips[20].x = 128;
		gSpriteClips[20].y = 128;
		gSpriteClips[20].w = 64;
		gSpriteClips[20].h = 64;

		gSpriteClips[21].x = 192;
		gSpriteClips[21].y = 128;
		gSpriteClips[21].w = 64;
		gSpriteClips[21].h = 64;

		gSpriteClips[22].x = 256;
		gSpriteClips[22].y = 128;
		gSpriteClips[22].w = 64;
		gSpriteClips[22].h = 64;

		gSpriteClips[23].x = 320;
		gSpriteClips[23].y = 128;
		gSpriteClips[23].w = 64;
		gSpriteClips[23].h = 64;

		gSpriteClips[24].x = 384;
		gSpriteClips[24].y = 128;
		gSpriteClips[24].w = 64;
		gSpriteClips[24].h = 64;

		gSpriteClips[25].x = 448;
		gSpriteClips[25].y = 128;
		gSpriteClips[25].w = 64;
		gSpriteClips[25].h = 64;

		gSpriteClips[26].x = 512;
		gSpriteClips[26].y = 128;
		gSpriteClips[26].w = 64;
		gSpriteClips[26].h = 64;

		gSpriteClips[27].x = 0;
		gSpriteClips[27].y = 192;
		gSpriteClips[27].w = 63;
		gSpriteClips[27].h = 63;

		gSpriteClips[28].x = 64;
		gSpriteClips[28].y = 192;
		gSpriteClips[28].w = 63;
		gSpriteClips[28].h = 63;

		gSpriteClips[29].x = 128;
		gSpriteClips[29].y = 192;
		gSpriteClips[29].w = 63;
		gSpriteClips[29].h = 63;

		gSpriteClips[30].x = 192;
		gSpriteClips[30].y = 192;
		gSpriteClips[30].w = 63;
		gSpriteClips[30].h = 63;

		gSpriteClips[31].x = 256;
		gSpriteClips[31].y = 192;
		gSpriteClips[31].w = 63;
		gSpriteClips[31].h = 63;

		gSpriteClips[32].x = 320;
		gSpriteClips[32].y = 192;
		gSpriteClips[32].w = 63;
		gSpriteClips[32].h = 63;

		gSpriteClips[33].x = 384;
		gSpriteClips[33].y = 192;
		gSpriteClips[33].w = 63;
		gSpriteClips[33].h = 63;

		gSpriteClips[34].x = 448;
		gSpriteClips[34].y = 192;
		gSpriteClips[34].w = 63;
		gSpriteClips[34].h = 63;

		gSpriteClips[35].x = 512;
		gSpriteClips[35].y = 192;
		gSpriteClips[35].w = 63;
		gSpriteClips[35].h = 63;
	}

	if (!gSpriteSheetTextureAttack.loadFromFile("../src/sprites/pj/playerAttack2.bmp", m_WindowRenderer))
	{
		printf("Failed to load attack animation texture!\n");
		success = false;
	}
	else
	{
		//Set sprite clips || ATAQUE
		gSpriteClips[36].x = 0;
		gSpriteClips[36].y = 0;
		gSpriteClips[36].w = 64;
		gSpriteClips[36].h = 64;

		gSpriteClips[37].x = 64;
		gSpriteClips[37].y = 0;
		gSpriteClips[37].w = 64;
		gSpriteClips[37].h = 64;

		gSpriteClips[38].x = 128;
		gSpriteClips[38].y = 0;
		gSpriteClips[38].w = 64;
		gSpriteClips[38].h = 64;

		gSpriteClips[39].x = 192;
		gSpriteClips[39].y = 0;
		gSpriteClips[39].w = 64;
		gSpriteClips[39].h = 64;

		gSpriteClips[40].x = 256;
		gSpriteClips[40].y = 0;
		gSpriteClips[40].w = 64;
		gSpriteClips[40].h = 64;

		gSpriteClips[41].x = 320;
		gSpriteClips[41].y = 0;
		gSpriteClips[41].w = 64;
		gSpriteClips[41].h = 64;

		gSpriteClips[42].x = 384;
		gSpriteClips[42].y = 0;
		gSpriteClips[42].w = 64;
		gSpriteClips[42].h = 64;

		gSpriteClips[43].x = 0;
		gSpriteClips[43].y = 64;
		gSpriteClips[43].w = 64;
		gSpriteClips[43].h = 64;

		gSpriteClips[44].x = 64;
		gSpriteClips[44].y = 64;
		gSpriteClips[44].w = 64;
		gSpriteClips[44].h = 64;

		gSpriteClips[45].x = 128;
		gSpriteClips[45].y = 64;
		gSpriteClips[45].w = 64;
		gSpriteClips[45].h = 64;

		gSpriteClips[46].x = 192;
		gSpriteClips[46].y = 64;
		gSpriteClips[46].w = 64;
		gSpriteClips[46].h = 64;

		gSpriteClips[47].x = 256;
		gSpriteClips[47].y = 64;
		gSpriteClips[47].w = 64;
		gSpriteClips[47].h = 64;

		gSpriteClips[48].x = 320;
		gSpriteClips[48].y = 64;
		gSpriteClips[48].w = 64;
		gSpriteClips[48].h = 64;

		gSpriteClips[49].x = 384;
		gSpriteClips[49].y = 64;
		gSpriteClips[49].w = 64;
		gSpriteClips[49].h = 64;

		gSpriteClips[50].x = 0;
		gSpriteClips[50].y = 128;
		gSpriteClips[50].w = 64;
		gSpriteClips[50].h = 64;

		gSpriteClips[51].x = 64;
		gSpriteClips[51].y = 128;
		gSpriteClips[51].w = 64;
		gSpriteClips[51].h = 64;

		gSpriteClips[52].x = 128;
		gSpriteClips[52].y = 128;
		gSpriteClips[52].w = 64;
		gSpriteClips[52].h = 64;

		gSpriteClips[53].x = 192;
		gSpriteClips[53].y = 128;
		gSpriteClips[53].w = 64;
		gSpriteClips[53].h = 64;

		gSpriteClips[54].x = 256;
		gSpriteClips[54].y = 128;
		gSpriteClips[54].w = 64;
		gSpriteClips[54].h = 64;

		gSpriteClips[55].x = 320;
		gSpriteClips[55].y = 128;
		gSpriteClips[55].w = 64;
		gSpriteClips[55].h = 64;

		gSpriteClips[56].x = 384;
		gSpriteClips[56].y = 128;
		gSpriteClips[56].w = 64;
		gSpriteClips[56].h = 64;

		gSpriteClips[57].x = 0;
		gSpriteClips[57].y = 192;
		gSpriteClips[57].w = 64;
		gSpriteClips[57].h = 64;

		gSpriteClips[58].x = 64;
		gSpriteClips[58].y = 192;
		gSpriteClips[58].w = 64;
		gSpriteClips[58].h = 64;

		gSpriteClips[59].x = 128;
		gSpriteClips[59].y = 192;
		gSpriteClips[59].w = 64;
		gSpriteClips[59].h = 64;

		gSpriteClips[60].x = 192;
		gSpriteClips[60].y = 192;
		gSpriteClips[60].w = 64;
		gSpriteClips[60].h = 64;

		gSpriteClips[61].x = 256;
		gSpriteClips[61].y = 192;
		gSpriteClips[61].w = 64;
		gSpriteClips[61].h = 64;

		gSpriteClips[62].x = 320;
		gSpriteClips[62].y = 192;
		gSpriteClips[62].w = 64;
		gSpriteClips[62].h = 64;

		gSpriteClips[63].x = 384;
		gSpriteClips[63].y = 192;
		gSpriteClips[63].w = 64;
		gSpriteClips[63].h = 64;

	}
	if (!gSpriteSheetTextureInmortal.loadFromFile("../src/sprites/pj/player_inmortal.bmp", m_WindowRenderer))
	{
		printf("Failed to load damage animation texture!\n");
		success = false;
	}
	else {
		gSpriteClips[64].x = 0;
		gSpriteClips[64].y = 0;
		gSpriteClips[64].w = 64;
		gSpriteClips[64].h = 64;

		gSpriteClips[65].x = 64;
		gSpriteClips[65].y = 0;
		gSpriteClips[65].w = 64;
		gSpriteClips[65].h = 64;

		gSpriteClips[66].x = 128;
		gSpriteClips[66].y = 0;
		gSpriteClips[66].w = 64;
		gSpriteClips[66].h = 64;

		gSpriteClips[67].x = 192;
		gSpriteClips[67].y = 0;
		gSpriteClips[67].w = 64;
		gSpriteClips[67].h = 64;

		gSpriteClips[68].x = 256;
		gSpriteClips[68].y = 0;
		gSpriteClips[68].w = 64;
		gSpriteClips[68].h = 64;

		gSpriteClips[69].x = 320;
		gSpriteClips[69].y = 0;
		gSpriteClips[69].w = 64;
		gSpriteClips[69].h = 64;

		gSpriteClips[70].x = 384;
		gSpriteClips[70].y = 0;
		gSpriteClips[70].w = 64;
		gSpriteClips[70].h = 64;

		gSpriteClips[71].x = 448;
		gSpriteClips[71].y = 0;
		gSpriteClips[71].w = 64;
		gSpriteClips[71].h = 64;

		gSpriteClips[72].x = 512;
		gSpriteClips[72].y = 0;
		gSpriteClips[72].w = 64;
		gSpriteClips[72].h = 64;

		gSpriteClips[73].x = 0;
		gSpriteClips[73].y = 64;
		gSpriteClips[73].w = 64;
		gSpriteClips[73].h = 64;

		gSpriteClips[74].x = 64;
		gSpriteClips[74].y = 64;
		gSpriteClips[74].w = 64;
		gSpriteClips[74].h = 64;

		gSpriteClips[75].x = 128;
		gSpriteClips[75].y = 64;
		gSpriteClips[75].w = 64;
		gSpriteClips[75].h = 64;

		gSpriteClips[76].x = 192;
		gSpriteClips[76].y = 64;
		gSpriteClips[76].w = 64;
		gSpriteClips[76].h = 64;

		gSpriteClips[77].x = 256;
		gSpriteClips[77].y = 64;
		gSpriteClips[77].w = 64;
		gSpriteClips[77].h = 64;

		gSpriteClips[78].x = 320;
		gSpriteClips[78].y = 64;
		gSpriteClips[78].w = 64;
		gSpriteClips[78].h = 64;

		gSpriteClips[79].x = 384;
		gSpriteClips[79].y = 64;
		gSpriteClips[79].w = 64;
		gSpriteClips[79].h = 64;

		gSpriteClips[80].x = 448;
		gSpriteClips[80].y = 64;
		gSpriteClips[80].w = 64;
		gSpriteClips[80].h = 64;

		gSpriteClips[81].x = 512;
		gSpriteClips[81].y = 64;
		gSpriteClips[81].w = 64;
		gSpriteClips[81].h = 64;

		gSpriteClips[82].x = 0;
		gSpriteClips[82].y = 128;
		gSpriteClips[82].w = 64;
		gSpriteClips[82].h = 64;

		gSpriteClips[83].x = 64;
		gSpriteClips[83].y = 128;
		gSpriteClips[83].w = 64;
		gSpriteClips[83].h = 64;

		gSpriteClips[84].x = 128;
		gSpriteClips[84].y = 128;
		gSpriteClips[84].w = 64;
		gSpriteClips[84].h = 64;

		gSpriteClips[85].x = 192;
		gSpriteClips[85].y = 128;
		gSpriteClips[85].w = 64;
		gSpriteClips[85].h = 64;

		gSpriteClips[86].x = 256;
		gSpriteClips[86].y = 128;
		gSpriteClips[86].w = 64;
		gSpriteClips[86].h = 64;

		gSpriteClips[87].x = 320;
		gSpriteClips[87].y = 128;
		gSpriteClips[87].w = 64;
		gSpriteClips[87].h = 64;

		gSpriteClips[88].x = 384;
		gSpriteClips[88].y = 128;
		gSpriteClips[88].w = 64;
		gSpriteClips[88].h = 64;

		gSpriteClips[89].x = 448;
		gSpriteClips[89].y = 128;
		gSpriteClips[89].w = 64;
		gSpriteClips[89].h = 64;

		gSpriteClips[90].x = 512;
		gSpriteClips[90].y = 128;
		gSpriteClips[90].w = 64;
		gSpriteClips[90].h = 64;

		gSpriteClips[91].x = 0;
		gSpriteClips[91].y = 192;
		gSpriteClips[91].w = 63;
		gSpriteClips[91].h = 63;

		gSpriteClips[92].x = 64;
		gSpriteClips[92].y = 192;
		gSpriteClips[92].w = 63;
		gSpriteClips[92].h = 63;

		gSpriteClips[93].x = 128;
		gSpriteClips[93].y = 192;
		gSpriteClips[93].w = 63;
		gSpriteClips[93].h = 63;

		gSpriteClips[94].x = 192;
		gSpriteClips[94].y = 192;
		gSpriteClips[94].w = 63;
		gSpriteClips[94].h = 63;

		gSpriteClips[95].x = 256;
		gSpriteClips[95].y = 192;
		gSpriteClips[95].w = 63;
		gSpriteClips[95].h = 63;

		gSpriteClips[96].x = 320;
		gSpriteClips[96].y = 192;
		gSpriteClips[96].w = 63;
		gSpriteClips[96].h = 63;

		gSpriteClips[97].x = 384;
		gSpriteClips[97].y = 192;
		gSpriteClips[97].w = 63;
		gSpriteClips[97].h = 63;

		gSpriteClips[98].x = 448;
		gSpriteClips[98].y = 192;
		gSpriteClips[98].w = 63;
		gSpriteClips[98].h = 63;

		gSpriteClips[99].x = 512;
		gSpriteClips[99].y = 192;
		gSpriteClips[99].w = 63;
		gSpriteClips[99].h = 63;

	}
	if (!gSpriteSheetTextureDead.loadFromFile("../src/sprites/dead/Explosion.bmp", m_WindowRenderer))
	{
		printf("Failed to load damage animation texture!\n");
		success = false;
	}
	else {
		gSpriteClips[100].x = 0;
		gSpriteClips[100].y = 0;
		gSpriteClips[100].w = 96;
		gSpriteClips[100].h = 96;

		gSpriteClips[101].x = 96;
		gSpriteClips[101].y = 0;
		gSpriteClips[101].w = 96;
		gSpriteClips[101].h = 96;

		gSpriteClips[102].x = 192;
		gSpriteClips[102].y = 0;
		gSpriteClips[102].w = 96;
		gSpriteClips[102].h = 96;

		gSpriteClips[103].x = 288;
		gSpriteClips[103].y = 0;
		gSpriteClips[103].w = 96;
		gSpriteClips[103].h = 96;

		gSpriteClips[104].x = 384;
		gSpriteClips[104].y = 0;
		gSpriteClips[104].w = 96;
		gSpriteClips[104].h = 96;

		gSpriteClips[105].x = 480;
		gSpriteClips[105].y = 0;
		gSpriteClips[105].w = 96;
		gSpriteClips[105].h = 96;

		gSpriteClips[106].x = 576;
		gSpriteClips[106].y = 0;
		gSpriteClips[106].w = 96;
		gSpriteClips[106].h = 96;

		gSpriteClips[107].x = 672;
		gSpriteClips[107].y = 0;
		gSpriteClips[107].w = 96;
		gSpriteClips[107].h = 96;

		gSpriteClips[108].x = 768;
		gSpriteClips[108].y = 0;
		gSpriteClips[108].w = 96;
		gSpriteClips[108].h = 96;

		gSpriteClips[109].x = 864;
		gSpriteClips[109].y = 0;
		gSpriteClips[109].w = 96;
		gSpriteClips[109].h = 96;

		gSpriteClips[110].x = 960;
		gSpriteClips[110].y = 0;
		gSpriteClips[110].w = 96;
		gSpriteClips[110].h = 96;

		gSpriteClips[111].x = 1056;
		gSpriteClips[111].y = 0;
		gSpriteClips[111].w = 96;
		gSpriteClips[111].h = 96;


	}
	return success;
}


void CPlayer::close(SDL_Renderer* m_WindowRenderer)
{
	//Free loaded images
	gSpriteSheetTexture.free();
	gSpriteSheetTextureAttack.free();

	//Destroy window	
	//SDL_DestroyRenderer(gRenderer);
	//SDL_DestroyWindow(gWindow);
	//gWindow = NULL;
	//gRenderer = NULL;

	//Quit SDL subsystems
	//IMG_Quit();
	//SDL_Quit();
}

void CPlayer::animation()
{
	if (vida >= 1) {
		if (!inmortal) {
			bool entrat = false;

			// 0 - 8


			// 9 - 17
			if (a) {
				movimiento = true;

				if (frame > 16 || frame < 9) {
					frame = 9;
				}
				if (frame < 18 && cont == 1) {
					frame++;
				}

				entrat = true;
			}

			//19 - 26


			//27 - 35
			if (d) {
				movimiento = true;
				if (frame > 34 || frame < 27) {
					frame = 27;
				}
				if (frame < 35 && cont == 1) {
					frame++;
				}
				entrat = true;
			}
			if (s && entrat != true) {
				movimiento = true;
				if (frame > 25 || frame < 18) {
					frame = 18;
				}
				if (frame < 26 && cont == 1) {
					frame++;
				}

				if (frame == 18) {
					frame++;
				}
			}
			if (w && entrat != true) {
				movimiento = true;

				if (frame > 7) {
					frame = 0;
				}

				if (frame < 8 && cont == 1)
				{
					frame++;
				}

				if (frame == 0) {
					frame++;
				}
			}

			//36 - 42
			if (atkUP) {
				if (frame > 42 || frame < 36) {
					frame = 36;

				}

				if (frame < 42 && contAttack == 1) {

					frame++;
				}

				if (frame == 41) {
					contAttack = -1;
				}
			}


			//43 - 49
			if (atkLEFT) {
				if (frame > 49 || frame < 43) {
					frame = 43;
				}
				if (frame < 49 && contAttack == 1) {
					frame++;
				}

				if (frame == 48) {
					contAttack = -1;
				}
			}

			//50 - 56
			if (atkDOWN) {
				if ((frame > 56 || frame < 50)) {
					frame = 50;
				}
				if (frame < 56 && contAttack == 1) {
					frame++;
				}

				if (frame == 55) {
					contAttack = -1;
				}
			}

			//57 - 63
			if (atkRIGHT) {
				//No cal >62, perque si es == 62 para el moviment
				if (frame > 63 || frame < 57) {
					frame = 57;
				}

				if (frame < 63 && contAttack == 1) {
					frame++;
				}

				if (frame == 62) {
					contAttack = -1;
				}

			}

			if (frame == 41) {
				cont = -1;
			}
		}
		if (inmortal) {


			if (contEntradaInmortal == 0) {
				start = clock();
				contEntradaInmortal++;
			}
			diff = clock() - start;
			float elpasedsec = diff / CLOCKS_PER_SEC;
			if (elpasedsec >= 5) {
				inmortal = false;
				contEntradaInmortal = 0;
				contAnimacioInmortal = 0;
			}
			else {
				bool entrat = false;
				if (a) {


					if (frame > 80 || frame < 73) {
						frame = 73;
					}
					if (frame < 82 && cont == 1) {
						frame++;
					}

					entrat = true;
				}

				//19 - 26


				//27 - 35
				if (d) {

					if (frame > 98 || frame < 91) {
						frame = 91;
					}
					if (frame < 99 && cont == 1) {
						frame++;
					}
					entrat = true;
				}
				if (s && entrat != true) {

					if (frame > 89 || frame < 82) {
						frame = 82;
					}
					if (frame < 90 && cont == 1) {
						frame++;
					}

					if (frame == 82) {
						frame++;
					}
				}
				if (w && entrat != true) {
					if (frame > 71 || frame < 64) {
						frame = 64;
					}

					if (frame < 72 && cont == 1)
					{
						frame++;
					}

					if (frame == 64) {
						frame++;
					}
				}
			}

			if (frame == 48) {
				cont = -1;
			}
		}
	}
	else {
		if (dead == 0) {
			frame = 100;
			dead++;
		}
		else if (frame < 111 && cont == 10) {
				frame++;
		}
		else if (frame >= 111){
			dead = -1;
		}
	}
	//Velocidad de transición entre frames.
	if (cont > 10) {
		cont = 0;
	}
	if (contAttack > 5) {
		contAttack = 0;
	}
	cont++;
	contAttack++;
}

void CPlayer::render(SDL_Renderer* m_WindowRenderer)
{
	SDL_Rect* currentClip = &gSpriteClips[frame];
	if (vida < 1) {
		gSpriteSheetTextureDead.render((int)mPosX, (int)mPosY, currentClip, m_WindowRenderer);
	}
	else if (movimiento && !inmortal) {
		gSpriteSheetTexture.render((int)mPosX, (int)mPosY, currentClip, m_WindowRenderer);

	}
	else  if (!inmortal) {
		gSpriteSheetTextureAttack.render((int)mPosX, (int)mPosY, currentClip, m_WindowRenderer);

	}
	else if (inmortal) {
		gSpriteSheetTextureInmortal.render((int)mPosX, (int)mPosY + 6, currentClip, m_WindowRenderer);
	}


	if (!attacks.empty()) {
		
		int i = 0;
		int deleteElement = 0;
		bool borrar = false;

		for (CFireBall* atac : attacks) {
			enemigos = atac->getEnemigos();
			atac->animation();
			atac->move();
			atac->render();

			if (atac->colision()) {
				borrar = true;
				colisionsFb.push_back(i);
			}

			++i;

		}
		if (borrar) {

			if (attacks.size() > 1) {
				for (int i = 0; i < colisionsFb.size(); i++)
				{
					attacks.erase(attacks.begin() + i);
				}
			}
			else {
				attacks.clear();
			}
			colisionsFb.clear();
			borrar = false;
		}
	}
}

void CPlayer::attack() {
	CFireBall* fb = new CFireBall(mPosX, mPosY, atkdirection, m_WindowRenderer, enemigos);
	attacks.push_back(fb);

}