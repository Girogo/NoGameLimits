#ifndef  _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "SDL.h"
#include "GameState.h"
#include "Sprite.h"
#include "Player.h"
#include "Mosca.h"
#include "Mapa.h"
#include "Timer.h"
#include "GUI.h"
#include "Colission.h"
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
	CMapa mapa;
	CTimer stepTimer;
	CGUI GUI;

	static PlayState m_PlayState;

	SDL_Texture* playSprite;

	list<CTile> collisions;

};
#endif