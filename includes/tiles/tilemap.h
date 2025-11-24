#pragma once

#include "tile.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class TileMap {
	public:
		TileMap(const nlohmann::json& mapData);
		void Render();
		int size, rows, cols;
		std::vector<std::unique_ptr<Tile>> tile;
	private:
		static std::unordered_map<int, std::function<std::unique_ptr<Tile>(const Vector2<float>&, float, int)>> mapFactory;
		
		
};