#include "entities/player.h"
#include <iostream>

Player::Player(const Vector2<float>& position, const Vector2<float>& size, float speed, SDL_Renderer* renderer)
	: Entity(position, size, speed, renderer)
{ 
	texture = LoadTexturePNG(ResourceManager::GetTexturePath("JimCarrey"), this->renderer);
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
	pos = pos + dir * speed * static_cast<float>(deltaTime);
	hitbox.y = pos.y;
	hitbox.x = pos.x;
}

void Player::Render(){
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderTexture(renderer, texture, nullptr, &hitbox);// WRONG
}