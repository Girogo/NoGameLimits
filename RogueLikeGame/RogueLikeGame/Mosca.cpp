#include "Mosca.h"

CMosca::CMosca(char * file, int x, int y, int hight, int width, SDL_Renderer * window) : CEnemy(file, x, y, hight, width, window)
{
	this->vida = 3;
	this->dead = 0;
	//Create the necessary SDL_Rects frontalment
	mCollidersFrontE.resize(17);

	//Initialize the collision boxes' width and height for front walk

	mCollidersFrontE[0].w = 43;
	mCollidersFrontE[0].h = 1;

	mCollidersFrontE[1].w = 47;
	mCollidersFrontE[1].h = 1;

	mCollidersFrontE[2].w = 49;
	mCollidersFrontE[2].h = 2;

	mCollidersFrontE[3].w = 51;
	mCollidersFrontE[3].h = 1;

	mCollidersFrontE[4].w = 35;
	mCollidersFrontE[4].h = 3;

	mCollidersFrontE[5].w = 27;
	mCollidersFrontE[5].h = 1;

	mCollidersFrontE[6].w = 25;
	mCollidersFrontE[6].h = 5;

	mCollidersFrontE[7].w = 17;
	mCollidersFrontE[7].h = 1;

	mCollidersFrontE[8].w = 15;
	mCollidersFrontE[8].h = 1;

	mCollidersFrontE[9].w = 13;
	mCollidersFrontE[9].h = 1;

	mCollidersFrontE[10].w = 15;
	mCollidersFrontE[10].h = 2;

	mCollidersFrontE[11].w = 17;
	mCollidersFrontE[11].h = 1;

	mCollidersFrontE[12].w = 19;
	mCollidersFrontE[12].h = 1;

	mCollidersFrontE[13].w = 21;
	mCollidersFrontE[13].h = 7;

	mCollidersFrontE[14].w = 17;
	mCollidersFrontE[14].h = 1;

	mCollidersFrontE[15].w = 7;
	mCollidersFrontE[15].h = 2;

	mCollidersFrontE[16].w = 11;
	mCollidersFrontE[16].h = 4;

	//Initialize colliders relative to position
	shiftColliders();

}

CMosca::CMosca()
{
}


CMosca::~CMosca()
{
}

void CMosca::move(float timeStep, list<CTile> wall, SDL_Rect zonaSegura, CPlayer* player)
{

	colision = CColission::checkColission(mCollider, wall, &print);
	bool colisionDamage = CColission::checkColission(colDany, player->getZonaDany());
	col1 = mCollider;
	col2 = mCollider;
	col3 = mCollider;
	col4 = mCollider;
	col1.x = col1.x + 15;
	col2.x = col2.x - 15;
	col3.y = col1.y + 15;
	col4.y = col2.y - 15;
	colDany = mCollider;

	//Son los tama�os de dimension de la mosca, asi queda mas preciso sino solo seria con  el tama�o de la tile de 64 x 64
	//pero como en realidad la imagen de la mosca es mas peque�a aqui reduzco su tama�o
	colDany.h = colDany.h - 55;
	colDany.w = colDany.w - 55;
	diff = clock() - start;
	int elpasedsec = diff / CLOCKS_PER_SEC;
	if (elpasedsec >= 1 && !colision) {
		direccio = 1 + rand() % (101 - 1);
		start = clock();
		crash = false;
	}
	if (direccio == 0 || colision) {
		if (focus) {
			crash = true;
			focus = false;
		}
		direccio = 1 + rand() % (101 - 1);

		if (!focus) {
			if (direccio > 0 && direccio < 26 && !RIGHT && !CColission::checkColission(col1, wall, &print)) {

				mPosX += mVelX * timeStep;
				RIGHT = true;
				LEFT = false;
				UP = false;
				DOWN = false;
			}

			else if (direccio > 25 && direccio < 51 && !LEFT && !CColission::checkColission(col2, wall, &print)) {

				//Move the dot up or down
				mPosX -= mVelX * timeStep;
				RIGHT = false;
				LEFT = true;
				UP = false;
				DOWN = false;
			}

			if (direccio > 50 && direccio < 76 && !DOWN && !CColission::checkColission(col3, wall, &print)) {

				//Move the dot up or down
				mPosY += mVelY * timeStep;
				RIGHT = false;
				LEFT = false;
				UP = false;
				DOWN = true;

			}

			else if (direccio > 75 && !UP && !CColission::checkColission(col4, wall, &print)) {

				mPosY -= mVelY * timeStep;
				RIGHT = false;
				LEFT = false;
				UP = true;
				DOWN = false;
			}
		}
		else {

        if (direccio > 0 && direccio < 26 && !RIGHT && !colision) {
				mPosX += mVelX * timeStep;
				RIGHT = true;
				LEFT = false;
				UP = false;
				DOWN = false;

			}
			else if (direccio > 25 && direccio < 51 && !LEFT && !colision) {

				//Move the dot up or down
				mPosX -= mVelX * timeStep;
				RIGHT = false;
				LEFT = true;
				UP = false;
				DOWN = false;
			}

			if (direccio > 50 && direccio < 76 && !DOWN && !colision) {

				//Move the dot up or down
				mPosY += mVelY * timeStep;
				RIGHT = false;
				LEFT = false;
				UP = false;
				DOWN = true;
			}
			else if (direccio > 75 && !UP && !colision) {

				mPosY -= mVelY * timeStep;
				RIGHT = false;
				LEFT = false;
				UP = true;
				DOWN = false;
			}
		}

	}
	bool entrat = false;
	if (CColission::checkColission(mCollider, zonaSegura) && !colision && !crash) {
		if (colisionDamage && !player->getInmortal()) {
			player->setVida(player->getVida() - 1);

			player->setInmortal(true);
		}
		focus = true;
		if ((int)mPosX > (int)player->get_mPosX() && !colision) {
			mPosX -= mVelX * timeStep;
			RIGHT = false;
			LEFT = true;
			UP = false;
			DOWN = false;
			entrat = true;
		}
		else if ((int)mPosX < (int)player->get_mPosX() && !colision) {
			mPosX += mVelX * timeStep;
			RIGHT = true;
			LEFT = false;
			UP = false;
			DOWN = false;
			entrat = true;
		}
		if ((int)mPosY >(int)player->get_mPosY() && !colision) {
			mPosY -= mVelY * timeStep;
			if (!entrat) {
				RIGHT = false;
				LEFT = false;
				UP = true;
				DOWN = false;
			}
		}
		else if ((int)mPosY < (int)player->get_mPosY() && !colision) {
			mPosY += mVelY * timeStep;
			if (!entrat) {
				RIGHT = false;
				LEFT = false;
				UP = false;
				DOWN = true;
			}
		}


	}
	else  if (!colision) {
		//Move the dot left or right
		if (direccio > 0 && direccio < 26 && !colision) {
			mPosX += mVelX * timeStep;
			RIGHT = true;
			LEFT = false;
			UP = false;
			DOWN = false;

		}
		else if (direccio > 25 && direccio < 51 && !colision) {
			//Move the dot up or down
			mPosX -= mVelX * timeStep;
			RIGHT = false;
			LEFT = true;
			UP = false;
			DOWN = false;
		}
		if (direccio > 50 && direccio < 76 && !colision) {
			//Move the dot up or down
			mPosY += mVelY * timeStep;
			RIGHT = false;
			LEFT = false;
			UP = false;
			DOWN = true;
		}
		else if (direccio > 75 && !colision) {
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
}



bool CMosca::loadMedia(SDL_Renderer * m_WindowRenderer)
{
	//Loading succes flag
	bool success = true;
	SDL_Rect gSpriteClipsCom;
	//Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("../src/sprites/enemy/mosca.bmp", m_WindowRenderer))
	{
		printf("Failed to load walking animation texture!\n");
	}
	//definimos la posiciones de las sprites
	else
	{
		
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

	if (!gSpriteSheetTextureDead.loadFromFile("../src/sprites/dead/Explosion.bmp", m_WindowRenderer))
	{
		printf("Failed to load damage animation texture!\n");
		success = false;
	}
	else {

		//16
		gSpriteClipsCom.x = 0;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//17
		gSpriteClipsCom.x = 96;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//18
		gSpriteClipsCom.x = 192;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//19
		gSpriteClipsCom.x = 288;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//20
		gSpriteClipsCom.x = 384;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//21
		gSpriteClipsCom.x = 480;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//22
		gSpriteClipsCom.x = 576;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//23
		gSpriteClipsCom.x = 672;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//24
		gSpriteClipsCom.x = 768;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//25
		gSpriteClipsCom.x = 864;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//26
		gSpriteClipsCom.x = 960;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//27
		gSpriteClipsCom.x = 1056;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 96;
		gSpriteClipsCom.h = 96;
		gSpriteClips.push_back(gSpriteClipsCom);

		//28
		gSpriteClipsCom.x = 0;
		gSpriteClipsCom.y = 0;
		gSpriteClipsCom.w = 0;
		gSpriteClipsCom.h = 0;
		gSpriteClips.push_back(gSpriteClipsCom);


	}
	return success;
}

void CMosca::animation()
{

	if (vida > 0) {
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

	}
	else {
		this->mVelX = 0;
		this->mVelY = 0;

		if (dead == 0) {
			frame = 16;
			dead++;
		}
		else if (frame < 28 && frameCont == 9) {
			frame++;
		}
		else if (frame >= 28) {
			finAnimacion = true;
			dead = -1;
		}

	}
	if (frameCont > 9) {
		frameCont = 0;
	}
	frameCont++;
}

void CMosca::render(SDL_Renderer* m_WindowRenderer) {

	SDL_Rect* currentClip = &gSpriteClips[frame];

	if (vida > 0) {

		gSpriteSheetTexture.render((int)mPosX, (int)mPosY, currentClip, m_WindowRenderer);
	}
	else {
		gSpriteSheetTextureDead.render((int)mPosX, (int)mPosY, currentClip, m_WindowRenderer);
	}

}

void CMosca::shiftColliders()
{
	//The row offset
	int r = 0;

	//Go through the dot's collision boxes
	for (int set = 0; set < mCollidersFrontE.size(); ++set)
	{
		//Center the collision box
		mCollidersFrontE[set].x = mPosX + (width - mCollidersFrontE[set].w - 30) / 2;

		//Set the collision box at its row offset
		mCollidersFrontE[set].y = mPosY + r - 40;

		//Move the row offset down the height of the collision box
		r += mCollidersFrontE[set].h;
	}
}

std::vector<SDL_Rect>& CMosca::getCollidersFrontE()
{
	return mCollidersFrontE;
}
