#pragma once

#include "SDL3/SDL.h"
#include "extras/custom_sdl.h"
#include <string>

class Tile {
	public:
		Tile(std::string texture_path, SDL_Renderer* renderer);
		~Tile();

	private:
		SDL_Texture* texture;
		SDL_Renderer* renderer;
};