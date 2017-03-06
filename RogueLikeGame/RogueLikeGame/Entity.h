#pragma once
#include <SDL.h>
class CEntity
{
public:
	CEntity();
	CEntity(char * file, float mPosX, float mPosY, int hight, int width, SDL_Renderer* window);
	~CEntity();
	float get_mPosX();
	float get_mPosY();
	int get_height();
	int get_width();
	char get_file();
	void set_file(char* file);
	void set_window(SDL_Renderer*  Window);
	void set_mPosX(float mPosX);
	void set_mPosY(float mPosY);
	void set_height(int hight);
	void set_width(int width);

	//Controla el movimiento de la entidad
	virtual void move(int x, int y) = 0;
	virtual void move(const Uint8 *keyboard_state_array) = 0;


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
	int height;
	int width;
	//Posicion
	float mPosX;
	float mPosY;

};

