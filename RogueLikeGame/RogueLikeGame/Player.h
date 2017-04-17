#pragma once
#include<SDL.h>
#include"Sprite.h"
#include "Texture.h"
#include "FireBall.h"
#include <vector>
#include <time.h>
#include "Item.h"
#include "Enemy.h"

class CPlayer : public CEntity
{
public:
	CPlayer(char * file, int x, int y, int hight, int width, SDL_Renderer* window, std::vector<CEnemy*> enemigos);
	CPlayer();

	//GETTERS Y SETTERS
	int getVida() { return vida; };
	int getCoins() { return coins; };
	int getBombs() { return bombs; };
	int getKeys() { return keys; };
	std::vector<CEnemy*> getEnemigos() { return enemigos; }

	void setVida(int i) { vida = i; };
	void setCoins(int i) { coins = i; };
	void setBombs(int i) { bombs = i; };
	void setKeys(int i) { keys = i; };

	int getFrame() { return frame; };
	void setFrame(int frame) { this->frame = frame; };

	//Necesario?
	void move(const Uint8 *keyboard_state_array);
	//
	void handleEvent(SDL_Event& e);
	bool loadMedia(SDL_Renderer* m_WindowRenderer);
	void animation();
	void attack();
	// EN ENTITY 
	void render(SDL_Renderer * m_WindowRenderer);
	void close(SDL_Renderer* m_WindowRenderer);
	
	std::vector<CFireBall*> getAttacks() { return attacks; };


	//--------
	void move(float timeStep);
	void move(float timeStep, list<CTile> wall);

	static const int PLAYER_VEL = 300;
	//-------

	SDL_Rect getZonaSegura() { return zonaSegura; }
	SDL_Rect getZonaDany() { return zonaDany; }
	void setInmortal(bool inmortal) { this->inmortal = inmortal; }
	bool getInmortal() { return inmortal; }
private:
	//EN ENTITY
	//CTexture gSpriteSheetTexture;

	CTexture gSpriteSheetTextureAttack;
	CTexture gSpriteSheetTextureInmortal;
	CTexture gSpriteSheetTextureDead;
	CFireBall fb;

	std::vector<CFireBall*> attacks;
	std::vector<int> colisionsFb;
	int cont = 0;
	int contAttack = 0;
	static const int WALKING_ANIMATION_FRAMES = 36;
	static const int ATTACK_ANIMATION_FRAMES = 28;
	static const int INMORTAL_ANIMATION_FRAMES = 36;
	static const int DEAD_ANIMATION_FRAMES = 12;
	SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES + ATTACK_ANIMATION_FRAMES + INMORTAL_ANIMATION_FRAMES + DEAD_ANIMATION_FRAMES];

	//static const int PLAYER_VEL = 300;

	//SUBSTITUIDOS POR with y height en Entity?
	//static const int DOT_WIDTH = 20;
	//static const int DOT_HEIGHT = 20;
	//------------------------------------------

	//SUBSTITUIDOS POR with y height en Entity?
	//static const int DOT_WIDTH = 20;
	//static const int DOT_HEIGHT = 20;
	//------------------------------------------


	//EN ENTITY?

	//EN ENTITY?

	//float mPosX, mPosY;
	//float mVelX, mVelY;
	//int frame;
	//int cont = 0;
	SDL_Renderer* m_WindowRenderer;
	//--------------------

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

	SDL_Rect zonaSegura;

	SDL_Rect zonaDany;
	//EN ENTITY?
	//int vida;
	int coins;
	int bombs;
	int keys;

	bool inmortal = false;

	int contAnimacioInmortal = 0;
	int contEntradaInmortal = 0;
	//Temporitzador per ser inmortal
	clock_t start;
	clock_t diff;

	//Vector enemics
	std::vector<CEnemy*> enemigos;
};
