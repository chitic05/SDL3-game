#pragma once

#include "extras/custom_math.hpp"
#include "extras/custom_sdl.h"
#include "extras/data_manager.h"
#include "extras/global_var.h"

#include "tiles/tilemap.h"

#include "SDL3/SDL.h"

#include <stdexcept>

class Entity {
	public:
		Entity();
		virtual ~Entity();
		virtual void Input() = 0; // = 0 tells the compiler that this function shouldn't have no implementation
		virtual void Update() = 0;
		virtual void Render();
		virtual void Physics(TileMap& tileMap);

		SDL_FRect hitbox;
	protected:
		virtual void CollisionY(TileMap& tileMap, float velocityY);
		virtual void CollisionX(TileMap& tileMap, float velocityX);

		Vector2<float> pos, dir{ 0.0f, 0.0f };
		
		int speed;
		int jumpForce;
		SDL_Texture* texture{nullptr};

		bool isGrounded = false;
		int fallingVelocity = 0;

};