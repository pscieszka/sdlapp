#pragma once

#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
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
	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}

	void init() override {

		transform = &entity->getComponent<TransformComponent>();
		
		//bug z renderem to trzeba zmienic valuesy
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
		
	}

	void update() override {
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
	}
	void draw() override {
		textureManager::draw(texture, srcRect, destRect);
	}
};