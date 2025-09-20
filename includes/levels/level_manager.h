#pragma once
#include "level.h"

class LevelManager {
	public:
		static std::unique_ptr<Level> currentLevel;
		static void changeLevel(const std::string& newLevel);
};