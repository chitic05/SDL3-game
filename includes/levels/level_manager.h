#pragma once
#include "level.h"
#include <string>

class LevelManager {
	public:
		static std::unique_ptr<Level> currentLevel;
		static std::string pendingLevelChange;
		static void changeLevel(const std::string& newLevel);
		static void requestLevelChange(const std::string& newLevel);
		static void processPendingLevelChange();
};