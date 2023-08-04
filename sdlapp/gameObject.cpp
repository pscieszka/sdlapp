#include "gameObject.h"
#include "textureManager.h"

gameObject::gameObject(const char* texturesheet, SDL_Renderer* ren,int x, int y ) {

	renderer = ren;
	objTexture = textureManager::LoadTexture(texturesheet, ren);
	xpos = x;
	ypos = y;
}

void gameObject::update() {

	xpos++;
	ypos++;


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