#ifndef  _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "SDL.h"
#include "GameState.h"
#include "Sprite.h"
#include "Mosca.h"
#include "Mapa.h"
#include "Timer.h"
#include "GUI.h"
#include "Colission.h"
#include "Item.h"
#include "Coin.h"
#include <list>

class PlayState : public GameState
{
public:
	void Init(Game* game);
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);

	// Implement Singleton Pattern
	static PlayState* Instance()
	{
		return &m_PlayState;
	}

protected:

	PlayState() {}

private:

	//Atributs necessaris per els personatges
	CPlayer player;
	CMosca mosca;
	CTile floor[130];
	CTile walls[130];
	CTile floor2[130];
	CTile walls2[130];
	CTile floor3[130];
	CTile walls3[130];
	CTile floor4[130];
	CTile walls4[130];
	CTile floor5[130];
	CTile walls5[130];
	CTile floor6[130];
	CTile walls6[130];
	CTile floor7[130];
	CTile walls7[130];
	CTile floor8[130];
	CTile walls8[130];

	CMapa mapa;
	CMapa mapa2;
	CMapa mapa3;
	CMapa mapa4;
	CMapa mapa5;
	CMapa mapa6;
	CMapa mapa7;
	CMapa mapa8;
	list<CTile> collisionsMap2;
	list<CTile> collisionsMap3;
	std::vector<CEnemy*> enemigos;
	CTimer stepTimer;
	CGUI GUI;
	std::vector<CItem> items;
	static PlayState m_PlayState;

	SDL_Texture* playSprite;

	list<CTile> collisions;
	list<CTile> doorCollisions;
	//FPS
	CTimer fpsTimer;
	int countedFrames = 0;
	float avgFPS;
	int room = 1;
};
#endif