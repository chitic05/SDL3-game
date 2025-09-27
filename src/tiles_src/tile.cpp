#include "tiles/tile.h"

Tile::Tile(Vector2<float> position, float size, int ID)
{
	std::string textureName = ResourceManager::Texture::id_to_name[ID];
	texture = LoadTexturePNG(ResourceManager::Texture::GetTexturePath(textureName));
	hitbox = {
		position.y *size, // because y represents the collumn, the OX axis
		position.x *size, // because x represens the row, the OY axis
		size,
		size
	};
}

Tile::~Tile() {
	if (texture){
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
		
}

void Tile::Render()
{
	SDL_RenderTexture(GlobalVar::renderer, texture, nullptr, &hitbox);
}