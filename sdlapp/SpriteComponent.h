#pragma once

#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component
{
private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		setTex(path);
	}

	void setTex(const char* path) {
		texture = textureManager::LoadTexture(path);
	}

	void init() override {

		position = &entity->getComponent<PositionComponent>();
		
		//bug z renderem to trzeba zmienic valuesy
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;
		
	}

	void update() override {
		destRect.x = position->x();
		destRect.y = position->y();
	}
	void draw() override {
		textureManager::draw(texture, srcRect, destRect);
	}
};