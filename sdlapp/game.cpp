#include "game.h"
#include "textureManager.h"
#include "gameObject.h"


gameObject* player;
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

	
	
	player = new gameObject("assets/xd.png", renderer);
	

}

void game::handleEvents() {
	SDL_Event event;
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
	player->update();
}

void game::render() {
	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);
}

void game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << std::endl;

}

