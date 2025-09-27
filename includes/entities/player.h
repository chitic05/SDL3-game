#pragma once

#include "entities/entity.h"

class Player : public Entity{
	public:
		Player(const Vector2<float>& position); //MAKE A JSON FILE WITH THE DATA FOR ALL THE ENTITIES(DAMAGE, SPEED, ETC, and make it take the data from there so it is easier to modify
		~Player() override = default;
		void Input() override;
		void Update() override;
		void Render() override;
	private:
};