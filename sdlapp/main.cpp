#include <iostream>
#include "SDL.h"
#include "game.h"

game* gamee = nullptr;

int main(int argc,char *argv[]) {

	gamee = new game();
	gamee->init("test",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,800, false);
	while (gamee->running()) {
		gamee->handleEvents();
		gamee->update();
		gamee->render();

	}
	gamee->clean();
	return 0;
}