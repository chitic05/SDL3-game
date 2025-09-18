#include "levels/level_manager.h"

std::unique_ptr<Level> LevelManager::currentLevel = nullptr;
SDL_Renderer* LevelManager::renderer = nullptr;

void LevelManager::changeLevel(const std::string& newLevelName) {
	
	currentLevel = std::make_unique<Level>(newLevelName, LevelManager::renderer);
	currentLevel->levelName = newLevelName;
	currentLevel->Load();
}

void LevelManager::setRenderer(SDL_Renderer* renderer) {
	LevelManager::renderer = renderer;
}