#include "map.h"
#include "game.h"
#include <fstream>


map::map() {

}
map::~map() {

}

void map::loadMap(std::string path, int sizeX, int sizeY) {
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(tile);
			game::AddTile(atoi(&tile), x * 32, y * 32);
			mapFile.ignore();
		}
	}




	mapFile.close();


}

