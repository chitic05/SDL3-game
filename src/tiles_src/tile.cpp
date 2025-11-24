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
	id=ID;
	if(ID > 0 && ID !=4)
		isCollidable = true;
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
	SDL_SetRenderDrawColor(GlobalVar::renderer, 0,0,0,255);
	SDL_RenderRect(GlobalVar::renderer, &hitbox);
}