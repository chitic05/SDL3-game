#include "tiles/tilemap.h"

TileMap::TileMap(int w, int h, SDL_Renderer* renderer)
	: renderer(renderer)
{
	tile.resize(h);
	for (auto& row : tile)
		row.resize(w);
}