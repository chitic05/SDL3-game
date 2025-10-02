#pragma once

#include "extras/custom_math.hpp"
#include "extras/custom_sdl.h"
#include "extras/data_manager.h"
#include "extras/global_var.h"

#include "SDL3/SDL.h"

#include <stdexcept>

class Entity {
	public:
		Entity();
		virtual ~Entity();
		virtual void Input() = 0; // = 0 tells the compiler that this function shouldn't have no implementation
		virtual void Update() = 0;
		virtual void Render() = 0;
	protected:
		Vector2<float> pos, dir{ 0.0f, 0.0f };
		SDL_FRect hitbox;
		float speed;
		SDL_Texture* texture{ nullptr };

};