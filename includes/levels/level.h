#pragma once

#include <string>
#include <fstream>
#include <memory>
#include <stdexcept>

#include "entities/player.h"
#include "extras/custom_sdl.h"
#include "tiles/tilemap.h"


class Level {
	public:
		Level(const std::string& name);
		~Level() = default; 
		void Load();
		void Input();
		void Update();
		void Render();

		std::string levelName;

	private:
		std::unique_ptr<Player> player;
		std::unique_ptr<TileMap> tileMap;
		//std::unique_ptr<TileMap> tileMap;
		std::unique_ptr<Player> loadPlayer(const nlohmann::json& levelFile);
		std::unique_ptr<TileMap> loadTileMap(const nlohmann::json& levelFile);

		nlohmann::json levelFile;
};