#pragma once

#include "SDL3/SDL.h"
#include "extras/custom_sdl.h"
#include <string>

class Tile {
	public:
		Tile(std::string texture_path);
		virtual ~Tile() = default;

	protected:
		SDL_Texture* texture;

		bool collidable = false;
		
};