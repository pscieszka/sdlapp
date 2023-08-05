#include "gameObject.h"
#include "textureManager.h"

gameObject::gameObject(const char* texturesheet,int x, int y ) {

	
	objTexture = textureManager::LoadTexture(texturesheet);
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
	SDL_RenderCopy(game::renderer, objTexture, &srcRect, &destRect);

	


}