#include "textureManager.h"


SDL_Texture* textureManager::LoadTexture(const char* fileName) {
	SDL_Surface* tmp = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(game::renderer, tmp);
	SDL_FreeSurface(tmp);
	return tex;

}

void textureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(game::renderer, tex, &src, &dest);
}
