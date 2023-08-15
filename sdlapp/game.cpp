#include "game.h"
#include "textureManager.h"
#include "map.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"



map* mapp;
SDL_Renderer* game::renderer = nullptr;
SDL_Event game::event;

std::vector<ColliderComponent*> game::colliders;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

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
	tile0.addComponent<TileComponent>(200, 200, 32, 32, 0);
	tile1.addComponent<TileComponent>(250, 250, 32, 32, 1);
	tile1.addComponent<ColliderComponent>("dirt");
	tile2.addComponent<TileComponent>(150, 150, 32, 32, 2);
	tile2.addComponent<ColliderComponent>("grass");

	
	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/xd.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	
	
	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
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
	for (auto cc : colliders) {
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
		
	}
	
	
	

	
}

void game::render() {
	SDL_RenderClear(renderer);
	

	manager.draw();
	SDL_RenderPresent(renderer);
}

void game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << std::endl;

}

