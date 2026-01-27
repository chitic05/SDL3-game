#include "levels/level_manager.h"

std::unique_ptr<Level> LevelManager::currentLevel = nullptr;
std::string LevelManager::pendingLevelChange = "";

void LevelManager::changeLevel(const std::string& newLevelName) {
	
	currentLevel.reset();
	currentLevel = std::make_unique<Level>(newLevelName);
	currentLevel->levelName = newLevelName;
	currentLevel->Load();
}

void LevelManager::requestLevelChange(const std::string& newLevel) {
	pendingLevelChange = newLevel;
}

void LevelManager::processPendingLevelChange() {
	if (!pendingLevelChange.empty()) {
		changeLevel(pendingLevelChange);
		pendingLevelChange = "";
	}
}
