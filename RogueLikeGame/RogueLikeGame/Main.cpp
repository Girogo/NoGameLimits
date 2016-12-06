#include <SDL.h>
#include <iostream>
#include "Game.h"


using namespace std;

int main(int argc, char ** argv)
{
	Game game;
	game.Init("Videojuego", 600, 400, true);

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
/*

	//Declaración de variables.
	SDL_Window* Window;
	SDL_Renderer* Renderer;
	int posX = 500;
	int posY = 250;
	int sizeX = 800;
	int sizeY = 600;
	bool quit = false;



	//Inicializa SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{	//Si no se crea...
		cout << "ERROR al inicializar SDL: " << SDL_GetError() << endl;
		return -1;
	}

	
	//Creación de la ventana.
	Window = SDL_CreateWindow(
		"Videojuego",			//titulo pantalla
		posX,					//posicion x inicial
		posY,					//posicion y inicial
		sizeX,					//ancho en px
		sizeY,					//altura en px
		SDL_WINDOW_MAXIMIZED	//maximizada
	);

	//Comprobamos que se ha creado correctamente
	if (Window == nullptr)
	{
		//Si no se crea...
		cout << "ERROR al inicializar la ventana : " << SDL_GetError() << endl;
		return -1;
	}


	//Creación del Renderer.
	Renderer = SDL_CreateRenderer
	(
		Window,						//ventana a la que se aplica
		-1,							//controlador que usa, -1 = primero que encuentra
		SDL_RENDERER_ACCELERATED	//permite usar la tarjeta gráfica
	);

	//Comprobamos que se ha creado correctamente
	if (Renderer == nullptr)
	{
		//Si no se crea...
		cout << "ERROR al inicializar el renderer : " << SDL_GetError() << endl;
		return -1;
	}

	//Creación de la configuración para el renderer
	SDL_RenderSetLogicalSize
	(
		Renderer,		//renderer al que se aplica
		sizeX,			//tamañoX
		sizeY			//tamañoY
	);

	//Creación del color para el render.
	SDL_SetRenderDrawColor
	(
		Renderer,		//renderer al que se aplica
		255,			//cantidad de rojo [0-255]
		255,			//cantidad de verde [0-255]
		255,			//cantidad de azul [0-255]
		255				//transparencia [0-255]
	);

	//Aplica el color a la pantalla (No se muestra aún)
	SDL_RenderClear(Renderer);

	//Muestra lo anterior (hasta ahora se ejecutaba en un "segundo plano")
	SDL_RenderPresent(Renderer);


	//Creación del rectangulo
	//IMPORTANTE TENER EN CUENTA QUE SI ++y EL OBJETO BAJA, NO SUBE
	SDL_Rect r;
	r.x = 50;				//posicion x de la pantalla
	r.y = 50;				//posicion y de la pantalla
	r.w = (sizeX - 2*r.x);	//ancho
	r.h = (sizeY - 2*r.y);	//alto

					//Cambia el color del render a azul
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);

	//Rellena el rectangulo con el color del renderer
	//SDL_RenderFillRect(Renderer, &r);

	//o

	//Dibuja el rectangulo con el color del renderer
	SDL_RenderDrawRect(Renderer, &r);

	//Muestra el rectangulo
	SDL_RenderPresent(Renderer);



	//Aplica un delay para que se muestre la pantalla durante 10s (10000ms)
	SDL_Delay(10000);
	*/