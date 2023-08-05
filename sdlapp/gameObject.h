#pragma once
#include "game.h"
class gameObject
{
public:
	gameObject(const char* texturesheet,int x,int y);
	~gameObject();
		
	void update();
	void render();
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	


};

