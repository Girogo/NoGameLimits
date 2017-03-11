#pragma once
#include<SDL.h>
#include"Sprite.h"
#include "Entity.h"
#include "Texture.h"
#include "FireBall.h"

class CPlayer : public CEntity
{
public:
	CPlayer(char * file, int x, int y, int height, int width, SDL_Renderer* window);
	CPlayer();

	//Necesarios??
	bool getDOWN() { return s; };
	bool getUP() { return w; };
	bool getRIGHT() { return d; };
	bool getLEFT() { return a; };
	//

	int getVida() { return vida; };
	int getCoins() { return coins; };
	int getBombs() { return bombs; };
	int getKeys() { return keys; };

	void setVida(int i) { vida = i; };
	void setCoins(int i) { coins = i; };
	void setBombs(int i) { bombs = i; };
	void setKeys(int i) { keys = i; };
	
	int getFrame() { return frame; };
	void setFrame(int frame) { this->frame = frame; };

	//Necesarios?
	void move(const Uint8 *keyboard_state_array);
	void move(int x, int y);
	//

	void move(float timeStep);
	void attack();

	void handleEvent(SDL_Event& e);
	
	bool loadMedia(SDL_Renderer* m_WindowRenderer);
	void animation();
	void render(SDL_Renderer * m_WindowRenderer);
	void close(SDL_Renderer* m_WindowRenderer);

private:
	CTexture gSpriteSheetTexture;
	CTexture gSpriteSheetTextureAttack;
	CFireBall fb;

	static const int WALKING_ANIMATION_FRAMES = 36;
	static const int ATTACK_ANIMATION_FRAMES = 28;

	static const int PLAYER_VEL = 300;
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES + ATTACK_ANIMATION_FRAMES];

	//frame de animacion del personaje



	//float mPosX, mPosY;
	float mVelX, mVelY;
	int frame;
	int cont = 0;
	SDL_Renderer* m_WindowRenderer;

	//Triggers teclas
	bool movimiento = false;
	bool battack = false;
	char atkdirection;

	bool w = false;
	bool s = false;
	bool d = false;
	bool a = false;

	bool atkUP = false;
	bool atkDOWN = false;
	bool atkLEFT = false;
	bool atkRIGHT = false;

	int vida;
	int coins;
	int bombs;
	int keys;
};
 