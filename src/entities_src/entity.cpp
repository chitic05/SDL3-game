#include "entities/entity.h"

Entity::Entity(const Vector2<float>& position, const Vector2<float>& size, float speed)
	: pos(position), dir(0.0f, 0.0f),speed(speed), texture(nullptr)
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