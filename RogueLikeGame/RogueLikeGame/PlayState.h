#ifndef  _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "SDL.h"
#include "GameState.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"

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
	int posicions_x[9] = { 120,130,140,150,160,170,180,190,200 };
	int posicions_y[9] = { 200,200,200,200,200,200,200,200,200 };
	int cont = 0;
	//SDL_Texture *enemy;
	int enemy_x, enemy_y;


	static PlayState m_PlayState;

	SDL_Texture* playSprite;

};
#endif