#pragma once
#include<SDL.h>
#include"Sprite.h"
#include "Entity.h"
#include "Texture.h"
#include "Colission.h"
#include <list>
class CPlayer : public CEntity
{
public:
	CPlayer(char * file, int x, int y, int hight, int width, SDL_Renderer* window);
	CPlayer();
	void move(const Uint8 *keyboard_state_array);
	void move(int x, int y);
	void handleEvent(SDL_Event& e);
	void move(float timeStep);
	void move(float timeStep, list<CTile> wall);
	bool loadMedia(SDL_Renderer* m_WindowRenderer);

	void render(SDL_Renderer * m_WindowRenderer);

	void close(SDL_Renderer* m_WindowRenderer);

	static const int PLAYER_VEL = 300;
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	int getFrame() { return frame; };
	void setFrame(int frame) { this->frame = frame; };

	bool getDOWN() { return DOWN; };
	bool getUP() { return UP; };
	bool getRIGHT() { return RIGHT; };
	bool getLEFT() { return LEFT; };


	void animation();

	int getVida() { return vida; };
	int getCoins() { return coins; };
	int getBombs() { return bombs; };
	int getKeys() { return keys; };

	void setVida(int i) { vida = i;};
	void setCoins(int i) { coins = i; };
	void setBombs(int i) { bombs = i; };
	void setKeys(int i) { keys = i; };
	bool getPrint() { return print; };
private:
	CTexture gSpriteSheetTexture;
	static const int WALKING_ANIMATION_FRAMES = 36;
	SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];

	//frame de animacion del personaje



	//float mPosX, mPosY;
	float mVelX, mVelY;
	int frame;
	int cont = 0;

	bool UP = false;
	bool DOWN = false;
	bool RIGHT = false;
	bool LEFT = false;
	int vida;
	int coins;
	int bombs;
	int keys;

	//variable para saber si esta por debajo de textura i de esta forma imprimir de una manera u otra
	bool print;
};
 