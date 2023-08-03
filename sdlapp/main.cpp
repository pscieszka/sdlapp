#include <iostream>
#include "SDL.h"
#include "game.h"

game* gamee = nullptr;

int main(int argc,char *argv[]) {


	const int FPS = 100;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;


	gamee = new game();
	gamee->init("test",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,800, false);
	while (gamee->running()) {

		frameStart = SDL_GetTicks();

		gamee->handleEvents();
		gamee->update();
		gamee->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	gamee->clean();
	return 0;
}