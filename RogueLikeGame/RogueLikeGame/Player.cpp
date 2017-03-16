#include "Player.h"
#include "Entity.h"
CPlayer::CPlayer(char * file, int x, int y, int hight, int width, SDL_Renderer * window) : CEntity(file, x, y, hight, width, window)
{
	this->gSpriteSheetTexture = CTexture::CTexture();
	this->frame = 0;
	this->mVelX = 0;
	this->mVelY = 0;
	this->vida = 3;
	this->coins = 0;
	this->bombs = 0;
	this->keys = 0;
	this->print = false;
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
	this->print = false;
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
		if (frame < 35 && cont == 2) {
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
		if (frame < 17 && cont == 2) {
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
		if (frame < 8 && entrat != true && cont == 2)
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
		if (frame < 26 && entrat != true && cont == 2) {
			frame++;
		}
	}
	cont++;
	if (cont > 2) {
		cont = 0;
	}


}

void CPlayer::move(int x, int y)
{
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
		case SDLK_UP: mVelY -= PLAYER_VEL; UP = true; break;
		case SDLK_DOWN: mVelY += PLAYER_VEL; DOWN = true; break;
		case SDLK_LEFT: mVelX -= PLAYER_VEL; LEFT = true; break;
		case SDLK_RIGHT: mVelX += PLAYER_VEL; RIGHT = true; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += PLAYER_VEL; UP = false; break;
		case SDLK_DOWN: mVelY -= PLAYER_VEL; DOWN = false; break;
		case SDLK_LEFT: mVelX += PLAYER_VEL; LEFT = false; break;
		case SDLK_RIGHT: mVelX -= PLAYER_VEL; RIGHT = false; break;
		}
	}

}


//movimiento fluido
void CPlayer::move(float timeStep)
{
	//Move the dot left or right
	mPosX += mVelX * timeStep;

	//If the dot went too far to the left or right
	if (mPosX < 0)
	{
		mPosX = 0;
	}
	else if (mPosX > 850 - DOT_WIDTH)
	{
		mPosX = 850 - DOT_WIDTH;
	}

	//Move the dot up or down
	mPosY += mVelY * timeStep;

	//If the dot went too far up or down
	if (mPosY < 0)
	{
		mPosY = 0;
	}
	else if (mPosY > 650 - DOT_HEIGHT)
	{
		mPosY = 650 - DOT_HEIGHT;
	}


}
void CPlayer::move(float timeStep, list<CTile> wall)
{
	//Move the dot left or right
	mPosX += mVelX * timeStep;
	mCollider.x = mPosX;
	//If the dot collided or went too far to the left or right
	if (CColission::checkColission(mCollider, wall, &print))
	{
		bool hola = print;
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
		bool hola = print;
		//Move back
		mPosY -= mVelY * timeStep;
		mCollider.y = mPosY;
	}
}

//Carga todas las sprites
bool CPlayer::loadMedia(SDL_Renderer* m_WindowRenderer)
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("../src/sprites/pj/player.bmp", m_WindowRenderer))
	{
		printf("Failed to load walking animation texture!\n");
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

		gSpriteClips[3].x = 196;
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

		gSpriteClips[12].x = 196;
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

		gSpriteClips[21].x = 196;
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
		gSpriteClips[27].w = 64;
		gSpriteClips[27].h = 62;

		gSpriteClips[28].x = 64;
		gSpriteClips[28].y = 192;
		gSpriteClips[28].w = 64;
		gSpriteClips[28].h = 62;

		gSpriteClips[29].x = 128;
		gSpriteClips[29].y = 192;
		gSpriteClips[29].w = 64;
		gSpriteClips[29].h = 62;

		gSpriteClips[30].x = 196;
		gSpriteClips[30].y = 192;
		gSpriteClips[30].w = 64;
		gSpriteClips[30].h = 62;

		gSpriteClips[31].x = 256;
		gSpriteClips[31].y = 192;
		gSpriteClips[31].w = 64;
		gSpriteClips[31].h = 62;

		gSpriteClips[32].x = 320;
		gSpriteClips[32].y = 192;
		gSpriteClips[32].w = 64;
		gSpriteClips[32].h = 62;

		gSpriteClips[33].x = 384;
		gSpriteClips[33].y = 192;
		gSpriteClips[33].w = 64;
		gSpriteClips[33].h = 62;

		gSpriteClips[34].x = 448;
		gSpriteClips[34].y = 192;
		gSpriteClips[34].w = 64;
		gSpriteClips[34].h = 62;

		gSpriteClips[35].x = 512;
		gSpriteClips[35].y = 192;
		gSpriteClips[35].w = 64;
		gSpriteClips[35].h = 62;
	}

	return success;
}

void CPlayer::render(SDL_Renderer* m_WindowRenderer)
{
	SDL_Rect* currentClip = &gSpriteClips[frame];
	gSpriteSheetTexture.render((int)mPosX, (int)mPosY, currentClip, m_WindowRenderer);
}

void CPlayer::close(SDL_Renderer* m_WindowRenderer)
{
	//Free loaded images
	gSpriteSheetTexture.free();

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
	bool entrat = false;
	if (LEFT) {
		if ((frame > 16 || frame < 9)) {
			frame = 9;
		}
		if (frame < 17 && cont == 6) {
			frame++;
		}
		entrat = true;
	}

	if (RIGHT) {
		if ((frame > 34 || frame < 27)) {
			frame = 27;
		}
		if (frame < 35 && cont == 6) {
			frame++;
		}
		entrat = true;
	}


	if (DOWN && entrat != true) {
		if (frame > 25 || frame < 18) {
			frame = 18;
		}
		if (frame < 26 && cont == 6) {
			frame++;
		}
	}

	if (UP && entrat != true) {
		if (frame > 7) {
		frame = 0;
		}
		if (frame < 8 && cont == 6)
		{
			frame++;
		}
	}



	if (cont > 9) {
		cont = 0;
	}
	cont++;
}



