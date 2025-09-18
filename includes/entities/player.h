#pragma once

#include "entities/entity.h"

class Player : public Entity{
	public:
		Player(const Vector2<float>& position, const Vector2<float>& size, float speed, SDL_Renderer* renderer);
		~Player() override = default;
		void Input(const bool* keyboardState) override;
		void Update(const double& deltaTime) override;
		void Render() override;
	private:
};