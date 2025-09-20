#include "tiles/tilemap.h"

TileMap::TileMap(int w, int h)
{
	tile.resize(h);
	for (auto& row : tile)
		row.resize(w);
}