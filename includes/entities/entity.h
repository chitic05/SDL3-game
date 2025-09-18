#pragma once

#include "extras/custom_math.hpp"
#include "extras/custom_sdl.h"
#include "extras/resource_manager.h"
#include "SDL3/SDL.h"

#include <stdexcept>

class Entity {
	public:
		Entity(const Vector2<float>& position, const Vector2<float>& size, float speed, SDL_Renderer* renderer);
		virtual ~Entity();
		virtual void Input(const bool* keyboardState) = 0; // = 0 tells the compiler that this function shouldn't have no implementation
		virtual void Update(const double& deltaTime) = 0;
		virtual void Render() = 0;
	protected:
		Vector2<float> pos, dir;
		SDL_FRect hitbox;
		float speed;

		SDL_Texture* texture;

		SDL_Renderer* renderer;
};