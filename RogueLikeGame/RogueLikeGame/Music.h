#pragma once
#include<SDL_mixer.h>
class CMusic
{
public:
	CMusic();
	~CMusic();
	void loadMedia();
	void close();
	Mix_Music* getMusic() { return gMusic; }
	Mix_Music* getMusicPartida() { return gMusicPartida; }
	Mix_Chunk* getEntrarPartida() { return gEntrarPartida; }
	Mix_Chunk* getEntrarOpcion() { return gEntrarOpcion; }
	Mix_Chunk* getMoverMenu() { return gMoverMenu; }
	Mix_Chunk* getCanviarOpcion() { return gCanviarOpcion; }
private:
	Mix_Music* gMusic;
	Mix_Music* gMusicPartida;
	Mix_Chunk* gEntrarPartida;
	Mix_Chunk* gEntrarOpcion;
	Mix_Chunk* gMoverMenu;
	Mix_Chunk* gCanviarOpcion;
};

