#include "tiles/tile.h"

Tile::Tile(const Vector2<float>& position, float size, int ID)
{
	std::string textureName = Data::Texture::id_to_name[ID];
	texture = LoadTexturePNG(Data::Texture::GetTexturePath(textureName));
	hitbox = {
		position.y , // because y represents the collumn, the OX axis
		position.x , // because x represens the row, the OY axis
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