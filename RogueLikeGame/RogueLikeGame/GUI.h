#pragma once
#include "Player.h"
#include "Sprite.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "TTF.h"
class CGUI
{
public:
	CGUI(CPlayer* player);
	CGUI();
	~CGUI();
	void loadMedia(SDL_Renderer* m_WindowRenderer);
	void drawGUI(SDL_Renderer* m_WindowRenderer, int fps);
	void drawHeart(SDL_Renderer* m_WindowRenderer);
	void drawKey(SDL_Renderer * m_WindowRenderer);
	void drawCoin(SDL_Renderer * m_WindowRenderer);
	void drawBomb(SDL_Renderer * m_WindowRenderer);
	void drawFPS(SDL_Renderer * m_WindowRenderer, int fps);
private:
	CPlayer* player;
	CTexture gTexture;
	SDL_Texture* heart;
	SDL_Texture* key;
	SDL_Texture* coin;
	SDL_Texture* bomb;
	SDL_Texture* FPS;
	SDL_Texture* text;
	TTF_Font* font;
};

