#include "tiles/tile.h"

Tile::Tile(int x, int y, float size, std::string textureName)
{
	texture = LoadTexturePNG(ResourceManager::Texture::GetTexturePath(textureName));
	hitbox = {
		static_cast<float>(x),
		static_cast<float>(y),
		40,
		40
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