#ifndef  _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "SDL.h"
#include "GameState.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Mapa.h"
#include "Tile.h"

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
	CEnemy enemy;
	CTile tileset[130];
	CMapa mapa;


	static PlayState m_PlayState;

	SDL_Texture* playSprite;

};
#endif