#include "entities/player.h"
#include <iostream>

Player::Player(const Vector2<float>& position)
{ 
	nlohmann::json playerData = ResourceManager::GetEntityData("player");
	pos = position;
	speed = playerData["speed"];
	
	hitbox = {
			position.x,
			position.y,
			playerData["size"]["x"],
			playerData["size"]["y"]
	};
	texture = LoadTexturePNG(ResourceManager::GetTexturePath(playerData["texture_name"]));
}

void Player::Input(const bool* keyboardState){
	dir = Vector2<float>(0.0f, 0.0f);
	if (keyboardState[SDL_SCANCODE_W])
		dir.y = dir.y + -1.0f;
	if (keyboardState[SDL_SCANCODE_S])
		dir.y = dir.y + 1.0f;

	if (keyboardState[SDL_SCANCODE_A])
		dir.x = dir.x + -1.0f;
	if (keyboardState[SDL_SCANCODE_D])
		dir.x = dir.x + 1.0f;

	dir.Normalize();
	std::cout << dir.x << ' ' << dir.y << std::endl;
}

void Player::Update(const double& deltaTime){
	std::cout << speed << '\n';
	pos = pos + dir * speed * static_cast<float>(deltaTime);
	hitbox.y = pos.y;
	hitbox.x = pos.x;
}

void Player::Render(){
	SDL_RenderTexture(RendererManager::getRenderer(), texture, nullptr, &hitbox);// WRONG
	
}