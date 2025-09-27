#include "entities/player.h"
#include <iostream>

Player::Player(const Vector2<float>& position)
{ 
	nlohmann::json playerData = ResourceManager::Entity::GetEntityData("player");
	pos = position;
	speed = playerData["speed"];
	
	hitbox = {
			position.x,
			position.y,
			playerData["size"]["x"],
			playerData["size"]["y"]
	};
	texture = LoadTexturePNG(ResourceManager::Texture::GetTexturePath(playerData["texture_name"]));
	
}

void Player::Input(){
	
	dir = Vector2<float>(0.0f, 0.0f);
	if (GlobalVar::keyboardState[SDL_SCANCODE_W])
		dir.y = dir.y + -1.0f;
	if (GlobalVar::keyboardState[SDL_SCANCODE_S])
		dir.y = dir.y + 1.0f;

	if (GlobalVar::keyboardState[SDL_SCANCODE_A])
		dir.x = dir.x + -1.0f;
	if (GlobalVar::keyboardState[SDL_SCANCODE_D])
		dir.x = dir.x + 1.0f;

	dir.Normalize();
	//std::cout << dir.x << ' ' << dir.y << std::endl;
}

void Player::Update(){
	std::cout << ResourceManager::Texture::id_to_name[1];
	//std::cout << speed << '\n';
	pos = pos + dir * speed * static_cast<float>(GlobalVar::deltaTime);
	hitbox.y = pos.y;
	hitbox.x = pos.x;
}

void Player::Render(){
	SDL_RenderTexture(GlobalVar::renderer, texture, nullptr, &hitbox);// WRONG
	
}