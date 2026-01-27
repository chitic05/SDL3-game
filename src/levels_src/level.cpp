#include "levels/level.h"
#include "levels/level_manager.h"
#include <iostream>
Level::Level(const std::string& name)
	: levelName(name)
{
	levelFile = LoadJSON("./res/levels/" + levelName + ".json");
}

void Level::Load(){  

	//Delete any object that we don't want preloaded from another level
	player.reset();

	//Start Loading
	//LOADING ALL THE OBJECTS FROM THE FILE
	tileMap = loadTileMap(levelFile);
	player = loadPlayer(levelFile);
	Level::isLoaded = true;
}

std::unique_ptr<Player> Level::loadPlayer(const nlohmann::json& levelFile){
	if (levelFile.contains("player")) {
		
		if (levelFile["player"].contains("position") && levelFile["player"]["position"].is_array() ) {
			float x = static_cast<float>(levelFile["player"]["position"][0]);
			float y = static_cast<float > (levelFile["player"]["position"][1]);

			return std::make_unique<Player>(Vector2<float>(x, y)); // pos
		}
	} 
	return nullptr;
}

std::unique_ptr<TileMap> Level::loadTileMap(const nlohmann::json& levelFile) {
	if (levelFile.contains("map") && levelFile["map"].is_object())
		return std::make_unique<TileMap>(levelFile["map"]);

	return nullptr;
}

void Level::Run(){
    if(isLoaded){
        Physics();

        // Check again if level is still loaded (in case changeLevel was called)
        if (!isLoaded || !player) return; 
        Input();
        Update();
    }
}

void Level::Input(){
    if (!isLoaded || !player) {
        return;
    }
    player->Input();
}

void Level::Update() {
    if (isLoaded && player) {
        player->Update();
    }
}

void Level::Physics(){
    if(tileMap){
        if(player){
            player->Physics(*tileMap);
            CheckTriggers();
        }
    }
}

void Level::CheckTriggers() {
    if (!player || !tileMap) return;
        
    int leftCol   = (int)(player->hitbox.x / tileMap->size);
    int rightCol  = (int)((player->hitbox.x + player->hitbox.w) / tileMap->size);
    int topRow    = (int)(player->hitbox.y / tileMap->size);
    int bottomRow = (int)((player->hitbox.y + player->hitbox.h) / tileMap->size);

    for (int row = topRow; row <= bottomRow; row++) {
        for (int col = leftCol; col <= rightCol; col++) {

            // Safety check: Bounds
            if (row < 0 || row >= tileMap->rows || col < 0 || col >= tileMap->cols) 
                continue;

            int index = row * tileMap->cols + col;

            if (tileMap->tile[index] && tileMap->tile[index]->id == 4) {
                
                std::cout << "Player reached Exit! Loading: ";
                
                // Safety check: Ensure the JSON actually has a next level defined
                if (levelFile.contains("nextLevel")) {
                     std::cout << levelFile["nextLevel"] << std::endl;
                     LevelManager::requestLevelChange(levelFile["nextLevel"]);
                } else {
                     std::cout << "No next level defined in JSON!" << std::endl;
                }
                
                return; 
            }
        }
    }
}

void Level::Render(){
	
	if (tileMap) {
		tileMap->Render();
	}

	if (player) {
		player->Render();
	}
}

