#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "gameWindow.h"

class ResourcesManager {

private:
	GameWindow& wnd;

public:
	ResourcesManager(GameWindow& wnd);
	~ResourcesManager();

	SDL_Surface* loadSurfaceImage(const char* imageFileDir);
	SDL_Texture* loadTextureImage(const char* imageFileDir);

	Mix_Chunk* loadSound(char* soundFileDir);
	Mix_Music* loadMusic(char* MusicFileDir);

	TTF_Font* loadFont(char* fontFileDir, int fontSize);

	//void clean();

};