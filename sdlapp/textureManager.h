#pragma once

#include "Game.h"
class textureManager{

public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

