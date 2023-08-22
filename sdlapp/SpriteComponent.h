#pragma once

#include "Components.h"
#include"textureManager.h"
#include "SDL.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;

public:

	int animIndex = 0;

	std::map<const char*, Animation> animations;

	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		setTex(path);
	}
	SpriteComponent(const char* path,bool isAnimated) {
		animated = isAnimated;

		Animation idle = Animation(3, 5, 100);
		Animation walk = Animation(1, 2, 100);

		animations.emplace("idle", idle);
		animations.emplace("walk", walk);
		Play("idle");
		
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

		srcRect.y = animIndex * transform->height;

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
		
	}

	void update() override {

		if (animated) {
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}
		destRect.x = static_cast<int>(transform->position.x) - game::camera.x;
		destRect.y = static_cast<int>(transform->position.y) - game::camera.y;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;

	}
	void draw() override {
		textureManager::draw(texture, srcRect, destRect);
	}

	void Play(const char* animName) {
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}
};