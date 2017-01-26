#include <SDL.h>
#include <iostream>
#include "Game.h"
#include "MenuState.h"


using namespace std;

int main(int argc, char ** argv)
{

	Game game;

	game.Init("Videojuego", 600, 400, false);

	game.ChangeState(MenuState::Instance());

	while (game.Running())
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	//cleanup the engine
	game.Clean();
	return 0;
}