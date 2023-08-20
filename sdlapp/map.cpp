#include "map.h"
#include "game.h"
#include <fstream>


map::map() {

}
map::~map() {

}

void map::loadMap(std::string path, int sizeX, int sizeY) {
	char c;
	std::fstream mapFile;
	mapFile.open(path);
	int srcX, srcY;
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(c);
			srcY = atoi(&c) * 64;
			mapFile.get(c);
			srcX = atoi(&c) * 64;
			game::AddTile(srcX,srcY,x*64,y*64);
			mapFile.ignore();
		}
	}




	mapFile.close();


}

