#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
class CTTF
{
public:
	CTTF();
	~CTTF();
	static TTF_Font* setupTTF(const std::string &name);
	static  SDL_Texture* CreateTextTextures(TTF_Font * font, SDL_Color textColor, SDL_Renderer * m_WindowRenderer, const char* number);
	static SDL_Texture* SurfaceToTexture(SDL_Surface* surf, SDL_Renderer* m_WindowRenderer);
};

