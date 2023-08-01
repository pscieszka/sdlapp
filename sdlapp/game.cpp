#include "game.h"


SDL_Texture* playerTexture;
SDL_Rect srcR, destR;

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

	SDL_Surface* tmp = IMG_Load("assets/xd.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_FreeSurface(tmp);
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
	cnt++;
	destR.h = 128;
	destR.w = 128;
	destR.x = cnt;
	std::cout << cnt << std::endl;
}

void game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture,NULL,&destR);
	SDL_RenderPresent(renderer);
}

void game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << std::endl;

}

