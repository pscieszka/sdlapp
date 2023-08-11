#include "map.h"
#include "textureManager.h"

int lvl1[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,2,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

map::map() {
	dirt = textureManager::LoadTexture("assets/dirt.png");
	grass = textureManager::LoadTexture("assets/grass.png");
	water = textureManager::LoadTexture("assets/water.png");

	loadMap(lvl1);
	
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;


	dest.x = dest.y = 0;
}
map::~map() {
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(water);
	SDL_DestroyTexture(dirt);
}

void map::loadMap(int arr[20][25]) {
	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 25; col++) {
			mapo[row][col] = arr[row][col];
		}
	}



}

void map::drawMap() {
	int type = 0;
	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 25; col++) {
			type = mapo[row][col];

			dest.x = col * 32;
			dest.y = row * 32;
			switch (type) {
			case 0:
				textureManager::draw(water, src, dest);
				break;
			case 1:
				textureManager::draw(grass, src, dest);
				break;

			case 2:
				textureManager::draw(dirt, src, dest);
				break;
			deafault:
				break;
			}

		}
	}

}