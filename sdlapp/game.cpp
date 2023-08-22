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

SDL_Rect game::camera = { 0,0,1200,720 };


auto& player(manager.addEntity());
auto& wall(manager.addEntity());
const char* mapfile = "assets/terrain_ss.png";


enum groupLabels : std::size_t {
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};
bool game::isRunning = false;

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));

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

	map::loadMap("assets/map.txt", 32, 32);
	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/test2.png",true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);
	
	


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

	camera.x = player.getComponent<TransformComponent>().position.x - 600;
	camera.y = player.getComponent<TransformComponent>().position.y - 360;
	//funkcja
	if (camera.x < 0) {
		camera.x = 0;
	}
	if (camera.y < 0) {
		camera.y = 0;
	}
	if (camera.x > camera.w) {
		camera.x = camera.w;
	}
	if (camera.y > camera.h) {
		camera.y = camera.h;
	}
	
	//for (auto cc : colliders) {
	//	Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	//}
	
	
	

	
}



void game::render() {
	SDL_RenderClear(renderer);
	
	for (auto& t : tiles) {
		t->draw();
	}
	for (auto& p : players) {
		p->draw();
	}
	for (auto& e : enemies) {
		e->draw();
	}
	
	SDL_RenderPresent(renderer);
}

void game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << std::endl;

}

void game::AddTile(int srcX, int srcY, int xpos,int ypos) {
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX,srcY,xpos,ypos,mapfile);
	tile.addGroup(groupMap);
}
