#pragma once

#include <string>
#include <fstream>
#include <memory>
#include <stdexcept>

#include "entities/player.h"
#include "extras/custom_sdl.h"


class Level {
	public:
		Level(const std::string& name);
		~Level() = default; 
		void Load();
		void Input(const bool* keyboardState);
		void Update(const double& deltaTime);
		void Render();

		std::string levelName;

	private:
		std::unique_ptr<Player> player;
		std::unique_ptr<Player> loadPlayer(const nlohmann::json& levelFile);

		nlohmann::json levelFile;
};