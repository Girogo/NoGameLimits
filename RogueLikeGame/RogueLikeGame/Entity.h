#pragma once
#include <SDL.h>
class CEntity
{
public:
	CEntity();
	CEntity(char * file, int x, int y, int hight, int width, SDL_Renderer* window);
	~CEntity();
	int get_x();
	int get_y();
	int get_hight();
	int get_width();
	char get_file();
	void set_file(char* file);
	void set_window(SDL_Renderer*  Window);
	void set_x(int x);
	void set_y(int y);
	void set_hight(int hight);
	void set_width(int width);

	//Controla el movimiento de la entidad
	virtual void move(int x, int y) = 0;
	virtual void move(SDL_Event evento) = 0;
	
	//Carga la entidad
	void load();
	//Dibuja la entidad
	void draw();

private:
	//Pantalla donde se carga la entidad
	SDL_Renderer* window;
	//Imagen de la entidad
	SDL_Texture* image;
	//Ruta de la imagen de la entidad
	char* file;

protected:
	//Tamaño
	int hight;
	int width;
	//Posicion
	int x;
	int y;

};

