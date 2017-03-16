#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include <SDL.h>
#include "GameState.h"
#include "Player.h"
#include "Sprite.h"
#include "Menu.h"


class MenuState : public GameState, public Menu
{
public:
	void Init(Game* game);
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);
	void CargaMenu(Game* game, int menuSelec);
	void CargaMenuSettings(Game* game, int menuSelec, bool fullScreen, int volSelec);
	//void CargaImgSprite(Game* game, char* nomImg);
	void CanviaVolum(Game* game, int volSelec, bool fullScreen);
	void CanviaScreen(Game* game, int volSelec, bool fullScreen);

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


