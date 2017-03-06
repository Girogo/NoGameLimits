#include "GUI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "TTF.h"
#include <iostream>

using namespace std;
CGUI::CGUI(CPlayer* player)
{
	this->player = player;
}

CGUI::CGUI()
{
}


CGUI::~CGUI()
{
}

void CGUI::loadMedia(SDL_Renderer * m_WindowRenderer)
{
	coin = Sprite::Load("../src/sprites/gui/coin.bmp", m_WindowRenderer);
	heart = Sprite::Load("../src/sprites/gui/heart.bmp", m_WindowRenderer);
	key = Sprite::Load("../src/sprites/gui/key.bmp", m_WindowRenderer);
	bomb = Sprite::Load("../src/sprites/gui/bomb.bmp", m_WindowRenderer);
	font = CTTF::setupTTF("../src/ttf/font.ttf");
	
}

void CGUI::drawGUI(SDL_Renderer* m_WindowRenderer)
{
	drawHeart(m_WindowRenderer);
	drawKey(m_WindowRenderer);
	drawBomb(m_WindowRenderer);
	drawCoin(m_WindowRenderer);
}

void CGUI::drawHeart(SDL_Renderer * m_WindowRenderer)
{

	int heart = player->getVida();
	int posInitX = 100;
	int posInitY = 10;
	for (int i = 0; i < heart; i++)
	{
		Sprite::Draw(m_WindowRenderer, this->heart, posInitX, posInitY, 25, 25);
		posInitX += 20;
	}
}

void CGUI::drawKey(SDL_Renderer * m_WindowRenderer)
{
	int keys = player->getKeys();
	std::string cadena = "";
	if (keys <= 9) {
		cadena = "0";
	}

	cadena = cadena + std::to_string(keys);
	const char* numCoins = cadena.c_str();
	int coins = player->getCoins();
	text = CTTF::CreateTextTextures(font, SDL_Color{ 255, 255, 255 }, m_WindowRenderer, numCoins);
	int posInitX = 6;
	int posInitY = 125;

	Sprite::Draw(m_WindowRenderer, this->key, posInitX, posInitY, 40, 40);
	SDL_Rect solidRect;
	solidRect.x = 40;
	solidRect.y = 125;
	solidRect.h = 25;
	solidRect.w = 25;
	SDL_RenderCopy(m_WindowRenderer, text, nullptr, &solidRect);
}

void CGUI::drawCoin(SDL_Renderer * m_WindowRenderer)
{

	int coins = player->getCoins();
	std::string cadena = "";
	if (coins <= 9) {
		cadena = "0";
	}
	
	cadena = cadena + std::to_string(coins);
	const char* numCoins = cadena.c_str();
	text = CTTF::CreateTextTextures(font, SDL_Color{ 255, 255, 255 }, m_WindowRenderer, numCoins);
	int posInitX = 10;
	int posInitY = 65;
	SDL_Rect solidRect;
	solidRect.x = 40;
	solidRect.y = 65;
	solidRect.h = 25;
	solidRect.w = 25;
	SDL_RenderCopy(m_WindowRenderer, text, nullptr, &solidRect);
	Sprite::Draw(m_WindowRenderer, this->coin, posInitX, posInitY, 25, 25);
}

void CGUI::drawBomb(SDL_Renderer * m_WindowRenderer)
{
	int bombs = player->getBombs();
	std::string cadena = "";
	if (bombs <= 9) {
		cadena = "0";
	}

	cadena = cadena + std::to_string(bombs);
	const char* numCoins = cadena.c_str();
	text = CTTF::CreateTextTextures(font, SDL_Color{ 255, 255, 255 }, m_WindowRenderer, numCoins);
	int posInitX = 10;
	int posInitY = 95;
	SDL_Rect solidRect;
	solidRect.x = 40;
	solidRect.y = 95;
	solidRect.h = 25;
	solidRect.w = 25;
	SDL_RenderCopy(m_WindowRenderer, text, nullptr, &solidRect);
	Sprite::Draw(m_WindowRenderer, this->bomb, posInitX, posInitY, 25, 25);
}
