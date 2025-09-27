#pragma once

#include "SDL3/SDL.h"
#include "extras/custom_sdl.h"
#include "extras/resource_manager.h"
#include <string>

class Tile {
	public:
		Tile(int x, int y, float size, std::string textureName);
		virtual void Render();
		virtual ~Tile();

	protected:
		SDL_Texture* texture;
		SDL_FRect hitbox;
		bool collidable = false;
		
};