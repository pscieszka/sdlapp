#include "game.h"
#include "textureManager.h"
#include "map.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"



map* mapp;
SDL_Renderer* game::renderer = nullptr;
SDL_Event game::event;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

game::game() {

}
game::~game() {

}

void game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0; 
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialised" << std::endl;

		window = SDL_CreateWindow(title,xpos,ypos,width,height,flags );
		if (window) {
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	
	
	
	mapp = new map();

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/xd.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	
	
	wall.addComponent<TransformComponent>(100.0f, 100.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("assets/dirt.png"); 
	wall.addComponent<ColliderComponent>("wall");
	


}

void game::handleEvents() {
	

	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void game::update() {
	
	manager.refresh();

	manager.update();

	if (Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)) {
		player.getComponent<TransformComponent>().velocity * -1;
		
		std::cout << " wall hit" << std::endl;
	}
	
	

	
}

void game::render() {
	SDL_RenderClear(renderer);
	mapp->drawMap();

	manager.draw();
	SDL_RenderPresent(renderer);
}

void game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << std::endl;

}

