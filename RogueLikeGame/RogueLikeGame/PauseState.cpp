#include <stdio.h>

#include "SDL.h"
#include "Game.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;
int posPauseMenu = 1;
int numOpcionsPause = 3;
int posPauseMenuSettings = 1;
int pauseNumOpcionsSettings = 3;
int pauseMenuIndex = 0;
int pauseVolSelected = 1;
int pauseNumOpcionsVol = 4;
bool pauseFullScreen = false;

void PauseState::Init(Game* game)
{
	pauseSprite = NULL;

	//pauseSprite = Sprite::Load("../src/sprites/menu/paused.bmp", game->GetRenderer());
	pauseSprite = Sprite::Load("../src/sprites/menu/PauseMenuReturn.png", game->GetRenderer());
	posPauseMenu = 1;


	printf("PauseState Init Successful\n");
}

void PauseState::Clean()
{
	printf("PauseState Clean Successful\n");
}

void PauseState::Resume() {}

void PauseState::Pause() {}

void PauseState::HandleEvents(Game* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			game->Quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				/*case SDLK_SPACE:
				game->PopState(PauseState::Instance());
				break;
				*/
				/*case SDLK_ESCAPE:
				game->PopState(PauseState::Instance());
				break;*/

			case SDLK_UP:
				if (pauseMenuIndex == 0) {
					if (posPauseMenu - 1 != 0) {
						posPauseMenu--;
						CargaMenu(game, posPauseMenu);
						//CargaMainMenu(game, posMainMenu, menuSprite);
					}
				}
				if (pauseMenuIndex == 1) {
					if (posPauseMenuSettings - 1 != 0) {
						posPauseMenuSettings--;
						CargaMenuSettings(game, posPauseMenuSettings, pauseFullScreen, pauseVolSelected);
					}
				}
				break;

			case SDLK_DOWN:
				if (pauseMenuIndex == 0) {
					if (posPauseMenu < numOpcionsPause) {
						posPauseMenu++;
						CargaMenu(game, posPauseMenu);
						//CargaMainMenu(game, posMainMenu, menuSprite);
					}
				}
				if (pauseMenuIndex == 1) {
					if (posPauseMenuSettings < pauseNumOpcionsSettings) {
						posPauseMenuSettings++;
						CargaMenuSettings(game, posPauseMenuSettings, pauseFullScreen, pauseVolSelected);
					}
				}
				break;

			case SDLK_RETURN:

				if (pauseMenuIndex == 0) {
					switch (posPauseMenu) {
					case 1:
						game->PopState(PauseState::Instance());
						break;

					case 2:
						//pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1no.png", game->GetRenderer());
						CargaMenuSettings(game, posPauseMenuSettings, pauseFullScreen, pauseVolSelected);
						//CargaImgSprite(game, "SettingsMenuSound1no.png");
						pauseMenuIndex = 1;
						break;

					case 3:
						game->Quit();
						break;

					}
				}
				if (pauseMenuIndex == 1) {
					if (posPauseMenuSettings == 3) {
						pauseMenuIndex = 0;
						posPauseMenu = 2;
						posPauseMenuSettings = 1;
						pauseSprite = Sprite::Load("../src/sprites/menu/PauseMenuSettings.png", game->GetRenderer());
					}
				}
				break;

			case SDLK_RIGHT:
				if (pauseMenuIndex == 1) {
					if (posPauseMenuSettings == 1) {
						if (pauseVolSelected < pauseNumOpcionsVol - 1) {
							pauseVolSelected++;
							CanviaVolum(game, pauseVolSelected, pauseFullScreen);
						}
					}
					if (posPauseMenuSettings == 2) {
						if (pauseFullScreen == true) {
							SDL_SetWindowFullscreen(game->GetWindow(), SDL_FALSE);
							pauseFullScreen = false;
							CanviaScreen(game, pauseVolSelected, pauseFullScreen);
						}
					}
				}
				break;

			case SDLK_LEFT:
				if (pauseMenuIndex == 1) {
					if (posPauseMenuSettings == 1) {
						if (pauseVolSelected - 1 != -1) {
							pauseVolSelected--;
							CanviaVolum(game, pauseVolSelected, pauseFullScreen);
						}
					}
					if (posPauseMenuSettings == 2) {
						if (pauseFullScreen == false) {
							SDL_SetWindowFullscreen(game->GetWindow(), SDL_TRUE);
							pauseFullScreen = true;
							CanviaScreen(game, pauseVolSelected, pauseFullScreen);
						}
					}
				}
				break;

			case SDLK_ESCAPE:
				if (pauseMenuIndex == 1) {
					pauseMenuIndex = 0;
					posPauseMenu = 2;
					posPauseMenuSettings = 1;
					pauseSprite = Sprite::Load("../src/sprites/menu/PauseMenuSettings.png", game->GetRenderer());
				}
				else {
					game->PopState(PauseState::Instance());
				}
				break;

			}

		}
	}
}

void PauseState::Update(Game* game)
{
}

void PauseState::Draw(Game* game)
{
	Sprite::DrawFullScreen(game->GetRenderer(), pauseSprite);
	SDL_RenderPresent(game->GetRenderer());
}

void PauseState::CargaMenu(Game* game, int menuSelec)
{
	switch (menuSelec) {

	case 1:
		pauseSprite = Sprite::Load("../src/sprites/menu/PauseMenuReturn.png", game->GetRenderer());
		break;

	case 2:
		pauseSprite = Sprite::Load("../src/sprites/menu/PauseMenuSettings.png", game->GetRenderer());
		break;

	case 3:
		pauseSprite = Sprite::Load("../src/sprites/menu/PauseMenuExit.png", game->GetRenderer());
		break;
	}
}

void PauseState::CargaMenuSettings(Game* game, int menuSelec, bool fullScreen, int volSelec)
{
	switch (menuSelec) {

	case 1:
		if (fullScreen == true) {
			switch (volSelec) {
			case 0:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0yes.png", game->GetRenderer());
				break;

			case 1:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1yes.png", game->GetRenderer());
				break;

			case 2:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2yes.png", game->GetRenderer());
				break;

			case 3:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3yes.png", game->GetRenderer());
				break;
			}

		}
		else {
			switch (volSelec) {
			case 0:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0no.png", game->GetRenderer());
				break;

			case 1:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1no.png", game->GetRenderer());
				break;

			case 2:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2no.png", game->GetRenderer());
				break;

			case 3:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3no.png", game->GetRenderer());
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
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen0yes.png", game->GetRenderer());
				break;

			case 1:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen1yes.png", game->GetRenderer());
				break;

			case 2:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen2yes.png", game->GetRenderer());
				break;

			case 3:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen3yes.png", game->GetRenderer());
				break;
			}

		}
		else {
			switch (volSelec) {
			case 0:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen0no.png", game->GetRenderer());
				break;

			case 1:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen1no.png", game->GetRenderer());
				break;

			case 2:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen2no.png", game->GetRenderer());
				break;

			case 3:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen3no.png", game->GetRenderer());
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
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack0yes.png", game->GetRenderer());
				break;

			case 1:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack1yes.png", game->GetRenderer());
				break;

			case 2:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack2yes.png", game->GetRenderer());
				break;

			case 3:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack3yes.png", game->GetRenderer());
				break;
			}

		}
		else {
			switch (volSelec) {
			case 0:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack0no.png", game->GetRenderer());
				break;

			case 1:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack1no.png", game->GetRenderer());
				break;

			case 2:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack2no.png", game->GetRenderer());
				break;

			case 3:
				pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack3no.png", game->GetRenderer());
				break;
			}
		}
		//menuSprite = Sprite::Load("../src/sprites/menu/SettingsMenuBack1no.png", game->GetRenderer());
		//CargaImgSprite(game, "SettingsMenuBack1no.png");
		break;
	}
}

void PauseState::CanviaVolum(Game* game, int volSelec, bool fullScreen)
{

	if (fullScreen == true) {
		switch (volSelec) {
		case 0:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0yes.png", game->GetRenderer());
			break;

		case 1:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1yes.png", game->GetRenderer());
			break;

		case 2:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2yes.png", game->GetRenderer());
			break;

		case 3:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3yes.png", game->GetRenderer());
			break;
		}

	}
	else {
		switch (volSelec) {
		case 0:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound0no.png", game->GetRenderer());
			break;

		case 1:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound1no.png", game->GetRenderer());
			break;

		case 2:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound2no.png", game->GetRenderer());
			break;

		case 3:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuSound3no.png", game->GetRenderer());
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

void PauseState::CanviaScreen(Game* game, int volSelec, bool fullScreen)
{
	if (fullScreen == true) {
		switch (volSelec) {
		case 0:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen0yes.png", game->GetRenderer());
			break;

		case 1:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen1yes.png", game->GetRenderer());
			break;

		case 2:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen2yes.png", game->GetRenderer());
			break;

		case 3:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen3yes.png", game->GetRenderer());
			break;
		}

	}
	else {
		switch (volSelec) {
		case 0:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen0no.png", game->GetRenderer());
			break;

		case 1:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen1no.png", game->GetRenderer());
			break;

		case 2:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen2no.png", game->GetRenderer());
			break;

		case 3:
			pauseSprite = Sprite::Load("../src/sprites/menu/SettingsMenuScreen3no.png", game->GetRenderer());
			break;
		}
	}
}

