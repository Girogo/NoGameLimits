#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include "Game.h"
#include "Music.h"


class GameState
{
public:
	virtual void Init(Game* game) = 0;
	virtual void Clean() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(Game* game) = 0;
	virtual void Update(Game* game) = 0;
	virtual void Draw(Game* game) = 0;

	void ChangeState(Game* game, GameState* state)
	{
		game->ChangeState(state);
	}
protected:
	GameState() { }
	CMusic music;
private:

};
#endif
