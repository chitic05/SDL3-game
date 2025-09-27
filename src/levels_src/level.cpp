#include "levels/level.h"
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

	player = loadPlayer(levelFile);
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

/*std::unique_ptr<TileMap> Level::loadTileMap(const nlohmann::json& levelFile) {

}*/

void Level::Input(){
	if (player) {
		player->Input();
	}
}

void Level::Update() {
	if (player) {
		player->Update();
	}
}

void Level::Render(){
	if (player) {
		player->Render();
	}

		
}
