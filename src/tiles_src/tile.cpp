#include "tiles/tile.h"

Tile::Tile(std::string texture_path) 
{
	texture = LoadTexturePNG(texture_path);
}

Tile::~Tile() {
	if (texture){
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
		
}