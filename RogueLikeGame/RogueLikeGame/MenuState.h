#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include <SDL.h>
#include "GameState.h"
#include "Player.h"
#include "Sprite.h"


class MenuState : public GameState
{
public:
	void Init(Game* game);
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);

	//Implement Singleton Pattern
	static MenuState* Instance()
	{
		return &m_MenuState;
	}

protected:
	MenuState() {}

private:
	static MenuState m_MenuState;
	SDL_Texture* menuSprite;

};
#endif

