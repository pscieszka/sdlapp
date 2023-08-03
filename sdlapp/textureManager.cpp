#include "textureManager.h"


SDL_Texture* textureManager::LoadTexture(const char* fileName, SDL_Renderer* ren) {
	SDL_Surface* tmp = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmp);
	SDL_FreeSurface(tmp);
	return tex;

}
