#include "Texture.h"



CTexture::CTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mPixels = NULL;
	mPitch = 0;
}


CTexture::~CTexture()
{
}

bool CTexture::loadFromFile(char * path, SDL_Renderer * m_WindowRenderer)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Convert surface to display format
		SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat(loadedSurface, SDL_PIXELFORMAT_RGBA8888, NULL);
		if (formattedSurface == NULL)
		{
			printf("Unable to convert loaded surface to display format! %s\n", SDL_GetError());
		}
		else
		{
			//Create blank streamable texture
			newTexture = SDL_CreateTexture(m_WindowRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h);
			if (newTexture == NULL)
			{
				printf("Unable to create blank texture! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Enable blending on texture
				SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);

				//Lock texture for manipulation
				SDL_LockTexture(newTexture, &formattedSurface->clip_rect, &mPixels, &mPitch);

				//Copy loaded/formatted surface pixels
				memcpy(mPixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h);

				//Get image dimensions
				mWidth = formattedSurface->w;
				mHeight = formattedSurface->h;

				//Get pixel data in editable format
				Uint32* pixels = (Uint32*)mPixels;
				int pixelCount = (mPitch / 4) * mHeight;

				//Map colors				
				Uint32 colorKey = SDL_MapRGB(formattedSurface->format, 0, 0xFF, 0xFF);
				Uint32 transparent = SDL_MapRGBA(formattedSurface->format, 0x00, 0xFF, 0xFF, 0x00);

				//Color key pixels
				for (int i = 0; i < pixelCount; ++i)
				{
					if (pixels[i] == colorKey)
					{
						pixels[i] = transparent;
					}
				}

				//Unlock texture to update
				SDL_UnlockTexture(newTexture);
				mPixels = NULL;
			}

			//Get rid of old formatted surface
			SDL_FreeSurface(formattedSurface);
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void CTexture::free()
{
	//Libera la texture si esta existe
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void CTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void CTexture::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void CTexture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void CTexture::render(int x, int y, SDL_Rect * clip, SDL_Renderer* m_WindowRenderer)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if (clip != NULL) {
		renderQuad.w = 96;//clip->w;
		renderQuad.h = 96;//clip->h;
	}

	//Renderitza a la pantalla
	SDL_RenderCopy(m_WindowRenderer, mTexture, clip, &renderQuad);
}

int CTexture::getWidth()
{
	return mWidth;
}

int CTexture::getHeight()
{
	return mHeight;
}
