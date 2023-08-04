#include "gameObject.h"
#include "textureManager.h"

gameObject::gameObject(const char* texturesheet, SDL_Renderer* ren) {

	renderer = ren;
	objTexture = textureManager::LoadTexture(texturesheet, ren);
}

void gameObject::update() {

	xpos = 0;
	ypos = 0;

	srcRect.h = 128;
	srcRect.w = 128;
	srcRect.x = 0;
	srcRect.y = 0;

	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
	

}

void gameObject::render(){
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);

	


}