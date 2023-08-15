#pragma once

#include "SDL.H"
class ColliderComponent;

class Collision {
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);


};