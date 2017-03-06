#include "TTF.h"
#include <SDL_ttf.h>
#include <iostream>

using namespace std;

CTTF::CTTF()
{
}


CTTF::~CTTF()
{
}

TTF_Font* CTTF::setupTTF(const std::string & name)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if (TTF_Init() == -1)
	{
		std::cout << " Failed to initialize TTF : " << SDL_GetError() << std::endl;
	}

	// Load our fonts, with a huge size
	TTF_Font* font = TTF_OpenFont(name.c_str(), 12);

	// Error check
	if (font == nullptr)
	{
		std::cout << " Failed to load font : " << SDL_GetError() << std::endl;
	}

	return font;
}
SDL_Texture* CTTF::CreateTextTextures(TTF_Font * font, SDL_Color textColor, SDL_Renderer * m_WindowRenderer, const char* number)
{
	SDL_Surface* solid = TTF_RenderText_Solid(font, number, textColor);
	SDL_Texture* solidTexture = SurfaceToTexture(solid, m_WindowRenderer);
	return solidTexture;
}
SDL_Texture * CTTF::SurfaceToTexture(SDL_Surface * surf, SDL_Renderer * m_WindowRenderer)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(m_WindowRenderer, surf);

	SDL_FreeSurface(surf);

	return text;

}


