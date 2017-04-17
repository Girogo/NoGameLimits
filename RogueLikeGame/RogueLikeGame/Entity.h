#pragma once
#include <SDL.h>
#include "Colission.h"
#include "Texture.h"
#include <list>
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
	bool getDOWN() { return DOWN; };
	bool getUP() { return UP; };
	bool getRIGHT() { return RIGHT; };
	bool getLEFT() { return LEFT; };
	int getFrame() { return frame; };
	bool getFinAnimacion() { return finAnimacion; }

	void setFrame(int frame) { this->frame = frame; };
	void set_file(char* file);
	void set_window(SDL_Renderer*  Window);
	void set_mPosX(float mPosX);
	void set_mPosY(float mPosY);
	void set_height(int hight);
	void set_width(int width);
	void setVida(int i) { vida = i; };
	int getVida() { return vida; };
	bool getPrint() { return print; };
	//Controla el movimiento de la entidad
	virtual void move(const Uint8 *keyboard_state_array) = 0;

	virtual void animation() = 0;
	virtual void render(SDL_Renderer * m_WindowRenderer);
	virtual bool loadMedia(SDL_Renderer* m_WindowRenderer) = 0;

	//Carga la entidad
	void load();
	//Dibuja la entidad
	void draw();

	SDL_Rect getCollider() { return mCollider; };
	int getDead() { return dead; }
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

	//Variable para saber si ha acabado la animación de muerte
	bool finAnimacion = false;

	//Rectangulo colisionador
	SDL_Rect mCollider;

	//Vida 
	int vida;

	//variable para saber si esta por debajo de textura i de esta forma imprimir de una manera u otra
	bool print;

	//Velocidad de movimiento
	float mVelX, mVelY;

	//Sprites de la entidad 
	CTexture gSpriteSheetTexture;
	std::vector<SDL_Rect> gSpriteClips;

	//frame actual
	int frame;

	//temporitzador de frames
	int frameCont = 0;

	//Control de direcciones
	bool UP = false;
	bool DOWN = false;
	bool RIGHT = false;
	bool LEFT = false;

	//int per l'animació de mort
	int dead;
};

