#pragma once

#include "tiles/tile.h"
#include <vector>
#include <memory>

using ptr = std::unique_ptr<Tile>;

class TileMap {
	public:
		TileMap(int w, int h);
		void Render();

		std::vector<std::vector<ptr>> tile;
	private:
};