#include <stdio.h>
#include <SDL.h>
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "Player.h"
#include <string.h>


MenuState MenuState::m_MenuState;
int posMainMenu = 1;
int posMainMenuSettings = 1;
int numOpcionsMain = 3;
int mainNumOpcionsSettings = 3;
int mainMenuIndex = 0;
int mainVolSelected = 1;
int mainNumOpcionsVol = 4;
bool mainFullScreen = false;
Menu menu;

void MenuState::Init(Game* game)
{
	//escala la resolucion
	SDL_RenderSetLogicalSize(game->GetRenderer(), 850, 650);

	menuSprite = NULL;
	menuSprite = Sprite::Load("../src/sprites/menu/MainMenuStart.png", game->GetRenderer());
	music.loadMedia();
	//Si no està la musica iniciamos el audio
	if (Mix_PlayingMusic() == 0) {
		Mix_PlayMusic(music.getMusic(), -1);
	}
	printf("MenuState Init Successful\n");
}

void MenuState::Clean()
{
	printf("MenuState Clean Successful\n");
}

void MenuState::Pause()
{
	printf("MenuState Paused\n");
}

void MenuState::Resume()
{
	printf("MenuState Resumed\n");
}

void MenuState::HandleEvents(Game* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			game->Quit();
			break;

		case SDL_KEYDOWN:

			switch (event.key.keysym.sym) {


				/*case SDLK_SPACE:
				game->ChangeState(PlayState::Instance());
				break;
				*/

			case SDLK_UP:
				Mix_PlayChannel(-1, music.getMoverMenu(), 0);
				if (mainMenuIndex == 0) {
					if (posMainMenu - 1 != 0) {
						posMainMenu--;
						CargaMenu(game, posMainMenu);
						//menu.CargaMainMenu(game, posMainMenu, menuSprite);
						//CargaMainMenu(game, posMainMenu, menuSprite);
					}
				}
				if (mainMenuIndex == 1) {
					if (posMainMenuSettings - 1 != 0) {
						posMainMenuSettings--;
						CargaMenuSettings(game, posMainMenuSettings, mainFullScreen, mainVolSelected);
					}
				}
				break;

			case SDLK_DOWN:
				Mix_PlayChannel(-1, music.getMoverMenu(), 0);
				if (mainMenuIndex == 0) {
					if (posMainMenu < numOpcionsMain) {
						posMainMenu++;
						CargaMenu(game, posMainMenu);
						//CargaMainMenu(game, posMainMenu, menuSprite);
					}
				}
				if (mainMenuIndex == 1) {
					if (posMainMenuSettings < mainNumOpcionsSettings) {
						posMainMenuSettings++;
						CargaMenuSettings(game, posMainMenuSettings, mainFullScreen, mainVolSelected);
					}
				}

				break;

			case SDLK_RETURN:
				if (mainMenuIndex == 0) {
					switch (posMainMenu) {
					case 1:
						Mix_HaltMusic();
						Mix_PlayChannel(-1, music.getEntrarPartida(), 0);
						game->ChangeState(PlayState::Instance());
						break;

					case 2:
						Mix_PlayChannel(-1, music.getEntrarOpcion(), 0);
						//menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1no.png", game->GetRenderer());
						CargaMenuSettings(game, posMainMenuSettings, mainFullScreen, mainVolSelected);
						//CargaImgSprite(game, "SettingsMenuSound1no.png");
						mainMenuIndex = 1;
						break;

					case 3:
						Mix_PlayChannel(-1, music.getEntrarOpcion(), 0);
						game->Quit();
						break;

					}
				}
				if (mainMenuIndex == 1) {
					if (posMainMenuSettings == 3) {
						Mix_PlayChannel(-1, music.getEntrarOpcion(), 0);
						mainMenuIndex = 0;
						posMainMenu = 2;
						posMainMenuSettings = 1;
						menuSprite = Sprite::Load("../src/sprites/menu/MainMenuSettings.png", game->GetRenderer());
					}
				}
				break;

			case SDLK_RIGHT:
				if (mainMenuIndex == 1) {
					Mix_PlayChannel(-1, music.getCanviarOpcion(), 0);
					if (posMainMenuSettings == 1) {
						if (mainVolSelected < mainNumOpcionsVol - 1) {
							mainVolSelected++;
							CanviaVolum(game, mainVolSelected, mainFullScreen);
						}
					}
					if (posMainMenuSettings == 2) {
						if (mainFullScreen == true) {
							mainFullScreen = false;
							SDL_SetWindowFullscreen(game->GetWindow(), SDL_FALSE);
							//game->SDL_SetRendererViewportRatio_4_3(game->GetWindow(), game->GetRenderer(), NULL);
							CanviaScreen(game, mainVolSelected, mainFullScreen);
						}
					}
				}
				break;

			case SDLK_LEFT:
				if (mainMenuIndex == 1) {
					Mix_PlayChannel(-1, music.getCanviarOpcion(), 0);
					if (posMainMenuSettings == 1) {
						if (mainVolSelected - 1 != -1) {
							mainVolSelected--;
							CanviaVolum(game, mainVolSelected, mainFullScreen);
						}
					}
					if (posMainMenuSettings == 2) {
						if (mainFullScreen == false) {
							mainFullScreen = true;
							SDL_SetWindowFullscreen(game->GetWindow(), SDL_TRUE);
							CanviaScreen(game, mainVolSelected, mainFullScreen);
						}
					}
				}
				break;

			case SDLK_ESCAPE:
				if (mainMenuIndex == 1) {
					mainMenuIndex = 0;
					posMainMenu = 2;
					posMainMenuSettings = 1;
					menuSprite = Sprite::Load("../src/sprites/menu/MainMenuSettings.png", game->GetRenderer());
				}
				break;

			}

		}
	}
}

void MenuState::Update(Game* game)
{

}

void MenuState::Draw(Game* game)
{
	Sprite::DrawFullScreen(game->GetRenderer(), menuSprite);
	SDL_RenderPresent(game->GetRenderer());
}

void MenuState::CargaMenu(Game* game, int menuSelec)
{
	switch (menuSelec) {

	case 1:
		menuSprite = Sprite::Load("../src/sprites/menu/MainMenuStart.png", game->GetRenderer());
		//CargaImgSprite(game, "MainMenuStart.png");
		break;

	case 2:
		menuSprite = Sprite::Load("../src/sprites/menu/MainMenuSettings.png", game->GetRenderer());
		//CargaImgSprite(game, "MainMenuSettings.png");
		break;

	case 3:
		menuSprite = Sprite::Load("../src/sprites/menu/MainMenuExit.png", game->GetRenderer());
		//CargaImgSprite(game, "MainMenuExit.png");
		break;
	}
}

void MenuState::CargaMenuSettings(Game* game, int menuSelec, bool fullScreen, int volSelec)
{
	switch (menuSelec) {

	case 1:
		if (fullScreen == true) {
			switch (volSelec) {
			case 0:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0yes.png", game->GetRenderer());
				break;

			case 1:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1yes.png", game->GetRenderer());
				break;

			case 2:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2yes.png", game->GetRenderer());
				break;

			case 3:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3yes.png", game->GetRenderer());
				break;
			}

		}
		else {
			switch (volSelec) {
			case 0:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0no.png", game->GetRenderer());
				break;

			case 1:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1no.png", game->GetRenderer());
				break;

			case 2:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2no.png", game->GetRenderer());
				break;

			case 3:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3no.png", game->GetRenderer());
				break;
			}
		}
		//menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1no.png", game->GetRenderer());
		//CargaImgSprite(game, "SettingsMenuSound1no.png");
		break;

	case 2:
		if (fullScreen == true) {
			switch (volSelec) {
			case 0:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen0yes.png", game->GetRenderer());
				break;

			case 1:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen1yes.png", game->GetRenderer());
				break;

			case 2:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen2yes.png", game->GetRenderer());
				break;

			case 3:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen3yes.png", game->GetRenderer());
				break;
			}

		}
		else {
			switch (volSelec) {
			case 0:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen0no.png", game->GetRenderer());
				break;

			case 1:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen1no.png", game->GetRenderer());
				break;

			case 2:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen2no.png", game->GetRenderer());
				break;

			case 3:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen3no.png", game->GetRenderer());
				break;
			}
		}
		//menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen1no.png", game->GetRenderer());
		//CargaImgSprite(game, "SettingsMenuScreen1no.png");
		break;

	case 3:
		if (fullScreen == true) {
			switch (volSelec) {
			case 0:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack0yes.png", game->GetRenderer());
				break;

			case 1:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack1yes.png", game->GetRenderer());
				break;

			case 2:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack2yes.png", game->GetRenderer());
				break;

			case 3:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack3yes.png", game->GetRenderer());
				break;
			}

		}
		else {
			switch (volSelec) {
			case 0:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack0no.png", game->GetRenderer());
				break;

			case 1:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack1no.png", game->GetRenderer());
				break;

			case 2:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack2no.png", game->GetRenderer());
				break;

			case 3:
				menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack3no.png", game->GetRenderer());
				break;
			}
		}
		//menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack1no.png", game->GetRenderer());
		//CargaImgSprite(game, "SettingsMenuBack1no.png");
		break;
	}
}

void MenuState::CanviaVolum(Game* game, int volSelec, bool fullScreen)
{

	if (fullScreen == true) {
		switch (volSelec) {
		case 0:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0yes.png", game->GetRenderer());
			break;

		case 1:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1yes.png", game->GetRenderer());
			break;

		case 2:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2yes.png", game->GetRenderer());
			break;

		case 3:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3yes.png", game->GetRenderer());
			break;
		}

	}
	else {
		switch (volSelec) {
		case 0:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0no.png", game->GetRenderer());
			break;

		case 1:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1no.png", game->GetRenderer());
			break;

		case 2:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2no.png", game->GetRenderer());
			break;

		case 3:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3no.png", game->GetRenderer());
			break;
		}
	}
	/*switch (volSelec) {

	case 0:
	if (fullScreen == true) {
	menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0yes.png", game->GetRenderer());
	}
	else {
	menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0no.png", game->GetRenderer());
	}
	//CargaImgSprite(game, "SettingsMenuSound0no.png");
	break;

	case 1:
	if (fullScreen == true) {
	menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1yes.png", game->GetRenderer());
	}
	else {
	menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1no.png", game->GetRenderer());
	}
	//CargaImgSprite(game, "SettingsMenuSound1no.png");
	break;

	case 2:
	if (fullScreen == true) {
	menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2yes.png", game->GetRenderer());
	}
	else {
	menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2no.png", game->GetRenderer());
	}
	//CargaImgSprite(game, "SettingsMenuSound2no.png");
	break;

	case 3:
	if (fullScreen == true) {
	menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3yes.png", game->GetRenderer());
	}
	else {
	menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3no.png", game->GetRenderer());
	}
	//CargaImgSprite(game, "SettingsMenuSound3no.png");
	break;
	}*/
}

void MenuState::CanviaScreen(Game* game, int volSelec, bool fullScreen)
{
	if (fullScreen == true) {
		switch (volSelec) {
		case 0:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen0yes.png", game->GetRenderer());
			break;

		case 1:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen1yes.png", game->GetRenderer());
			break;

		case 2:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen2yes.png", game->GetRenderer());
			break;

		case 3:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen3yes.png", game->GetRenderer());
			break;
		}

	}
	else {
		switch (volSelec) {
		case 0:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen0no.png", game->GetRenderer());
			break;

		case 1:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen1no.png", game->GetRenderer());
			break;

		case 2:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen2no.png", game->GetRenderer());
			break;

		case 3:
			menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen3no.png", game->GetRenderer());
			break;
		}
	}
}



