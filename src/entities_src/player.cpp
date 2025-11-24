#include "entities/player.h"
#include <iostream>

Player::Player(const Vector2<float>& position)
{ 
	const nlohmann::json playerData = Data::Entity::GetEntityData("player");
	speed = playerData["speed"];
	
	hitbox = {
			position.x,
			position.y,
			playerData["size"]["x"],
			playerData["size"]["y"]
	};
	jumpForce = playerData["jumpForce"];
	texture = LoadTexturePNG(Data::Texture::GetTexturePath(playerData["texture_name"]));
	
}

void Player::Input(){
    dir.x = 0.0f;

    if (GlobalVar::keyboardState[SDL_SCANCODE_A]) {
        dir.x = -1.0f;
    }
    if (GlobalVar::keyboardState[SDL_SCANCODE_D]) {
        dir.x = 1.0f;
    }

    if(GlobalVar::keyboardState[SDL_SCANCODE_SPACE] && isGrounded){
        fallingVelocity = jumpForce; 
        isGrounded = false; 
    }
}

void Player::Update(){
}

