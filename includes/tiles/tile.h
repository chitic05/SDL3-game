#pragma once

#include "SDL3/SDL.h"
#include "extras/custom_sdl.h"
#include "extras/resource_manager.h"
#include "extras/custom_math.hpp"
#include <string>

class Tile {
	public:
		Tile(Vector2<float> position, float size, int ID);
		virtual void Render();
		virtual ~Tile();

	protected:
		SDL_Texture* texture;
		SDL_FRect hitbox;
		bool collidable = false;
		
};