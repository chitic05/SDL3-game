#include "levels/level_manager.h"

std::unique_ptr<Level> LevelManager::currentLevel = nullptr;

void LevelManager::changeLevel(const std::string& newLevelName) {
	
	currentLevel.reset();
	currentLevel = std::make_unique<Level>(newLevelName);
	currentLevel->levelName = newLevelName;
	currentLevel->Load();
}
