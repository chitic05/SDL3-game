#include "entities/entity.h"

Entity::Entity(const Vector2<float>& position, const Vector2<float>& size, float speed, SDL_Renderer* renderer)
	: pos(position), dir(0.0f, 0.0f),speed(speed), renderer(renderer), texture(nullptr)
	{
		hitbox = {
			position.x,
			position.y,
			size.x,
			size.y
		};
	}
Entity::~Entity() {
	
	if (texture){
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}