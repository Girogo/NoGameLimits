#include "Mosca.h"



CMosca::CMosca(char * file, int x, int y, int hight, int width, SDL_Renderer * window) : CEnemy(file, x, y, hight, width, window)
{
}

CMosca::CMosca()
{
}


CMosca::~CMosca()
{
}

void CMosca::move(float timeStep, list<CTile> wall, SDL_Rect zonaSegura, CPlayer* player)
{
	diff = clock() - start;
	int elpasedsec = diff / CLOCKS_PER_SEC;
	if (elpasedsec >= 1 && !CColission::checkColission(mCollider, wall, &print)) {
		direccio = 1 + rand() % (101 - 1);
		start = clock();
	}
	bool entrat = false;
	if (CColission::checkColission(mCollider, zonaSegura)){
		if (mPosX > player->get_mPosX()) {
			mPosX -= mVelX * timeStep;
			RIGHT = false;
			LEFT = true;
			UP = false;
			DOWN = false;
			entrat = true;
		}
		else if (mPosX < player->get_mPosX()) {
			mPosX += mVelX * timeStep;
			RIGHT = true;
			LEFT = false;
			UP = false;
			DOWN = false;
			entrat = true;
		}
		if (mPosY > player->get_mPosY()) {
			mPosY -= mVelY * timeStep;
			if (!entrat) {
				RIGHT = false;
				LEFT = false;
				UP = true;
				DOWN = false;
			}
		}
		else if (mPosY < player->get_mPosY()) {
			mPosY += mVelY * timeStep;
			if (!entrat) {
				RIGHT = false;
				LEFT = false;
				UP = false;
				DOWN = true;
			}
		}

	}
	else {
		if (direccio == 0 || CColission::checkColission(mCollider, wall, &print)) {
			direccio = 1 + rand() % (101 - 1);
			if (direccio > 0 && direccio < 26 && !RIGHT) {
				mPosX += mVelX * timeStep;
				RIGHT = true;
				LEFT = false;
				UP = false;
				DOWN = false;
			}
			else if (direccio > 25 && direccio < 51 && !LEFT) {
				//Move the dot up or down
				mPosX -= mVelX * timeStep;
				RIGHT = false;
				LEFT = true;
				UP = false;
				DOWN = false;
			}
			if (direccio > 50 && direccio < 76 && !DOWN) {
				//Move the dot up or down
				mPosY += mVelY * timeStep;
				RIGHT = false;
				LEFT = false;
				UP = false;
				DOWN = true;

			}
			else if (direccio > 75 && !UP) {
				mPosY -= mVelY * timeStep;
				RIGHT = false;
				LEFT = false;
				UP = true;
				DOWN = false;
			}
		}
		else {
			//Move the dot left or right
			if (direccio > 0 && direccio < 26 && !CColission::checkColission(mCollider, wall, &print)) {
				mPosX += mVelX * timeStep;
				RIGHT = true;
				LEFT = false;
				UP = false;
				DOWN = false;

			}
			else if (direccio > 25 && direccio < 51 && !CColission::checkColission(mCollider, wall, &print)) {
				//Move the dot up or down
				mPosX -= mVelX * timeStep;
				RIGHT = false;
				LEFT = true;
				UP = false;
				DOWN = false;
			}
			if (direccio > 50 && direccio < 76 && !CColission::checkColission(mCollider, wall, &print)) {
				//Move the dot up or down
				mPosY += mVelY * timeStep;
				RIGHT = false;
				LEFT = false;
				UP = false;
				DOWN = true;
			}
			else if (direccio > 75 && !CColission::checkColission(mCollider, wall, &print)) {
				mPosY -= mVelY * timeStep;
				RIGHT = false;
				LEFT = false;
				UP = true;
				DOWN = false;
			}
		}
		if (DOWN || RIGHT) {
			mCollider.x = mPosX + 1;
			mCollider.y = mPosY + 1;
		}
		else {
			mCollider.x = mPosX - 1;
			mCollider.y = mPosY - 1;
		}

		//If the dot collided or went too far up or down
		/*if (CColission::checkColission(mCollider, wall, &print))
		{

		bool hola = print;
		//Move back
		mPosY -= mVelY * timeStep;
		mCollider.y = mPosY;
		}*/
	}
}
void CMosca::move(float timeStep, list<CTile> wall)
{
	diff = clock() - start;
	int elpasedsec = diff / CLOCKS_PER_SEC;
	if (elpasedsec >= 1 && !CColission::checkColission(mCollider, wall, &print)) {
		direccio = 1 + rand() % (101 - 1);
		start = clock();
	}
	if (direccio == 0 || CColission::checkColission(mCollider, wall, &print)) {
		direccio = 1 + rand() % (101 - 1);
		if (direccio > 0 && direccio < 26 && !RIGHT) {
			mPosX += mVelX * timeStep;
			RIGHT = true;
			LEFT = false;
			UP = false;
			DOWN = false;
		}
		else if (direccio > 25 && direccio < 51 && !LEFT) {
			//Move the dot up or down
			mPosX -= mVelX * timeStep;
			RIGHT = false;
			LEFT = true;
			UP = false;
			DOWN = false;
		}
		if (direccio > 50 && direccio < 76 && !DOWN) {
			//Move the dot up or down
			mPosY += mVelY * timeStep;
			RIGHT = false;
			LEFT = false;
			UP = false;
			DOWN = true;

		}
		else if (direccio > 75 && !UP) {
			mPosY -= mVelY * timeStep;
			RIGHT = false;
			LEFT = false;
			UP = true;
			DOWN = false;
		}
	}
	else {
		//Move the dot left or right
		if (direccio > 0 && direccio < 26 && !CColission::checkColission(mCollider, wall, &print)) {
			mPosX += mVelX * timeStep;
			RIGHT = true;
			LEFT = false;
			UP = false;
			DOWN = false;

		}
		else if (direccio > 25 && direccio < 51 && !CColission::checkColission(mCollider, wall, &print)) {
			//Move the dot up or down
			mPosX -= mVelX * timeStep;
			RIGHT = false;
			LEFT = true;
			UP = false;
			DOWN = false;
		}
		if (direccio > 50 && direccio < 76 && !CColission::checkColission(mCollider, wall, &print)) {
			//Move the dot up or down
			mPosY += mVelY * timeStep;
			RIGHT = false;
			LEFT = false;
			UP = false;
			DOWN = true;
		}
		else if (direccio > 75 && !CColission::checkColission(mCollider, wall, &print)) {
			mPosY -= mVelY * timeStep;
			RIGHT = false;
			LEFT = false;
			UP = true;
			DOWN = false;
		}
	}
	if (DOWN || RIGHT) {
		mCollider.x = mPosX + 1;
		mCollider.y = mPosY + 1;
	}
	else {
		mCollider.x = mPosX - 1;
		mCollider.y = mPosY - 1;
	}
	//If the dot collided or went too far up or down
	/*if (CColission::checkColission(mCollider, wall, &print))
	{

	bool hola = print;
	//Move back
	mPosY -= mVelY * timeStep;
	mCollider.y = mPosY;
	}*/
}

bool CMosca::loadMedia(SDL_Renderer * m_WindowRenderer)
{
	//Loading succes flag
	bool success = true;

	//Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("../src/sprites/enemy/mosca.bmp", m_WindowRenderer))
	{
		printf("Failed to load walking animation texture!\n");
	}
	//definimos la posiciones de las sprites
	else
	{
		SDL_Rect gSpriteClipsCom;
		//0
		gSpriteClipsCom.x = 1;
		gSpriteClipsCom.y = 1;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//1
		gSpriteClipsCom.x = 66;
		gSpriteClipsCom.y = 1;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//2
		gSpriteClipsCom.x = 131;
		gSpriteClipsCom.y = 1;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//3
		gSpriteClipsCom.x = 196;
		gSpriteClipsCom.y = 1;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//4
		gSpriteClipsCom.x = 1;
		gSpriteClipsCom.y = 66;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//5
		gSpriteClipsCom.x = 66;
		gSpriteClipsCom.y = 66;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//6
		gSpriteClipsCom.x = 131;
		gSpriteClipsCom.y = 66;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//7
		gSpriteClipsCom.x = 196;
		gSpriteClipsCom.y = 66;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//8
		gSpriteClipsCom.x = 1;
		gSpriteClipsCom.y = 131;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//9
		gSpriteClipsCom.x = 66;
		gSpriteClipsCom.y = 131;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//10
		gSpriteClipsCom.x = 131;
		gSpriteClipsCom.y = 131;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//11
		gSpriteClipsCom.x = 196;
		gSpriteClipsCom.y = 131;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//12
		gSpriteClipsCom.x = 1;
		gSpriteClipsCom.y = 196;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//13
		gSpriteClipsCom.x = 66;
		gSpriteClipsCom.y = 196;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//14
		gSpriteClipsCom.x = 131;
		gSpriteClipsCom.y = 196;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);

		//15
		gSpriteClipsCom.x = 196;
		gSpriteClipsCom.y = 196;
		gSpriteClipsCom.w = 64;
		gSpriteClipsCom.h = 64;
		gSpriteClips.push_back(gSpriteClipsCom);
	}
	return success;
}

void CMosca::animation()
{
	if (frameCont == 9) {
		frame++;
	}
	bool entrat = false;
	if (frame == 16) {
		printf("HOLA");
	}
	if (LEFT) {
		if (frame < 12 || frame > 15) {
			frame = 12;
		}
	
	}
	if (RIGHT) {
		if (frame < 8 || frame > 11) {
			frame = 8;
		}
		
	}
	if (DOWN && !entrat) {
		if (frame < 0 || frame > 3) {
			frame = 0;
		}
	}
	if (UP && !entrat) {
		if (frame < 4 || frame > 7) {
			frame = 4;
		}
	}
	if (frameCont > 9) {
		frameCont = 0;
	}
	frameCont++;
}
