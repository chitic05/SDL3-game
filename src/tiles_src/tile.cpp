#include "tiles/tile.h"

Tile::Tile(std::string texture_path, SDL_Renderer* renderer) 
	: renderer(renderer)
{
	texture = LoadTexturePNG(texture_path, renderer);
}

Tile::~Tile() {
	if (texture){
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
		
}