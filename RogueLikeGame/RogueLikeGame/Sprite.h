#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Game.h"
#include <SDL.h>

/*=========================================================*
* Clase Sprite, permite dibujar una imagen sobre un render *
*==========================================================*/
class Sprite
{
public:

	/*-----------------------------------------------------------
	 *Metodo Load:	Carga una imagen en GPU (Optimizado).
	 *Parametros:	Path a la imagen, Renderer al que se aplica.
	 *Return:		Textura optimizada.
	 *-----------------------------------------------------------*/

	static SDL_Texture* Load(char* pImagen, SDL_Renderer* m_WindowRenderer);



	/*Metodo Draw:	Dibuja una imagen cargada anteriormente.
	 *Parametros:	Renderer destino, textura cargada, posicion(x/y) donde se aplica, dimensiones(w/h) que aplica.
	 *Return:		True = se ha creado, False = no se ha creado.*/

	static bool Draw(SDL_Renderer* dest, SDL_Texture* src, int x, int y, int w, int h);


	/*Metodo Draw:	Dibuja una imagen cargada anteriormente. Util para cargar imagenes de SpriteSheets.
	 *
	 *Parametros:	Renderer destino, textura cargada, posicion(x/y) donde se aplica, dimensiones(w/h) que aplica
	 *				posicion(x/y) de la imagen, dimensiones(w/h) de la imagen.
	 *
	 *Return:		True = se ha creado, False = no se ha creado.*/

	static bool Draw(SDL_Renderer* dest, SDL_Texture* src, int x, int y, int width, int height,
															int x2, int y2, int width2, int height2);

	 static bool Draw(SDL_Renderer * dest, SDL_Texture * src, SDL_Rect origen, SDL_Rect destino);

	 
	 


	/*Metodo DrawFullScreen:
	 *				Dibuja una imagen cargada anteriormente en pantalla completa.
	 *
	 *Parametros:	Renderer destino, textura cargada.
	 *Return:		True = se ha creado, False = no se ha creado.*/

	static bool DrawFullScreen(SDL_Renderer* dest, SDL_Texture* src);

};
#endif

