#include "levels/level.h"
#include <iostream>
Level::Level(const std::string& name, SDL_Renderer* renderer)
	: levelName(name), renderer(renderer)
{

}

void Level::Load(){  

	//Delete any object that we don't want preloaded from another level
	player.reset();
	//Start Loading
	levelFile = LoadJSON("./res/levels/" + levelName + ".json");
	//when i acces this values to use levelFile.contains
	//LOADING ALL THE OBJECTS FROM THE FILE

	player = loadPlayer(levelFile);

}

std::unique_ptr<Player> Level::loadPlayer(const nlohmann::json& levelFile){
	if (levelFile.contains("player")) {
		
		if (levelFile["player"].contains("position") && levelFile["player"]["position"].is_array() ) {
			float x = static_cast<float>(levelFile["player"]["position"][0]);
			float y = static_cast<float > (levelFile["player"]["position"][1]);

			return std::make_unique<Player>( Vector2<float>(x, y), // pos
											 Vector2<float>(100, 100), // size
											 100, // speed
											 this->renderer			//I NEED TO PASS THIS
											);
		}
	} 
	return nullptr;
}

void Level::Input(const bool* keyboardState){
	if (player) {
		player->Input(keyboardState);
	}
}

void Level::Update(const double& deltaTime) {
	if (player) {
		player->Update(deltaTime);
	}
}

void Level::Render(){
	if (player) {
		player->Render();
	}
		
}
