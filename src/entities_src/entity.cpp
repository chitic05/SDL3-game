#include "entities/entity.h"

Entity::Entity(){
		
}
Entity::~Entity() {
	
	if (texture){
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}