#include <SDL.h>
#include <iostream>
#include "Game.h"


using namespace std;

int main(int argc, char ** argv)
{

	Game game;
	game.Init("Videojuego", 600, 400, false);

	while (game.Running())
	{
		game.HandleEvents(&game);
		game.Update();
		game.Draw();
	}

		//cleanup the engine
		game.Clean();
		return 0;
}