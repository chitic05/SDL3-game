#include "entities/entity.h"

Entity::Entity()
{
}
Entity::~Entity()
{

    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

void Entity::Render()
{
    SDL_RenderTexture(GlobalVar::renderer, texture, nullptr, &hitbox);
    // SDL_SetRenderDrawColor(GlobalVar::renderer, 255,0,0,255);
    // SDL_RenderRect(GlobalVar::renderer, &hitbox);
}

// Note: Ensure Player.h has: void Physics(TileMap& tileMap) override;
void Entity::Physics(TileMap &tileMap)
{

    float velocityX = dir.x * speed * static_cast<float>(GlobalVar::deltaTime);
    hitbox.x += velocityX;
    CollisionX(tileMap, velocityX);

    if (!isGrounded && fallingVelocity < 25)
    {
        fallingVelocity += GlobalVar::Physics::gravity;
    }
    hitbox.y += fallingVelocity;
    CollisionY(tileMap, fallingVelocity);
    printf("%b\n", isGrounded);
}
void Entity::CollisionX(TileMap &tileMap, float velocityX)
{
    if (velocityX == 0)
        return;

    int leftTile = (int)(hitbox.x / tileMap.size);
    int rightTile = (int)((hitbox.x + hitbox.w) / tileMap.size);

    int topRow = (int)(hitbox.y / tileMap.size);
    int bottomRow = (int)((hitbox.y + hitbox.h - 0.01f) / tileMap.size); // buffer(if y=0 and h=32 the programm will think that the feet are on row 1 but they are on row 0)
    if (velocityX > 0)
    {
        int col = rightTile;

        // map bounds
        if (col >= tileMap.cols)
        {
            hitbox.x = (tileMap.cols * tileMap.size) - hitbox.w;
            return;
        }

        bool hitTop = tileMap.tile[topRow * tileMap.cols + col] && tileMap.tile[topRow * tileMap.cols + col]->isCollidable;
        bool hitBottom = tileMap.tile[bottomRow * tileMap.cols + col] && tileMap.tile[bottomRow * tileMap.cols + col]->isCollidable;

        if (hitTop || hitBottom)
        {
            hitbox.x = (col * tileMap.size) - hitbox.w;
        }
    }
    else if (velocityX < 0)
    {
        int col = leftTile;

        // Check bounds
        if (col < 0)
        {
            hitbox.x = 0;
            return;
        }
        bool hitTop = tileMap.tile[topRow * tileMap.cols + col] && tileMap.tile[topRow * tileMap.cols + col]->isCollidable;
        bool hitBottom = tileMap.tile[bottomRow * tileMap.cols + col] && tileMap.tile[bottomRow * tileMap.cols + col]->isCollidable;

        if (hitTop || hitBottom)
        {
            hitbox.x = (col + 1) * tileMap.size;
                }
    }
}

void Entity::CollisionY(TileMap &tileMap, float velocityY)
{
    int leftCol = (int)(hitbox.x / tileMap.size);
    int rightCol = (int)((hitbox.x + hitbox.w - 0.01f) / tileMap.size); // Small buffer to avoid catching side walls

    if (velocityY >= 0)
    {
        int row = (int)((hitbox.y + hitbox.h) / tileMap.size);

        // Out of bounds chec
        if (row >= tileMap.rows)
            return; 

        bool hitLeft = tileMap.tile[row * tileMap.cols + leftCol] && tileMap.tile[row * tileMap.cols + leftCol]->isCollidable;
        bool hitRight = tileMap.tile[row * tileMap.cols + rightCol] && tileMap.tile[row * tileMap.cols + rightCol]->isCollidable;

        if (hitLeft || hitRight)
        {
            hitbox.y = (row * tileMap.size) - hitbox.h;
            fallingVelocity = 0;
            isGrounded = true;
        }else isGrounded = false;
    }
    else if (velocityY < 0)
    {
        int row = (int)(hitbox.y / tileMap.size);

        if (row < 0)
            return;

        bool hitLeft = tileMap.tile[row * tileMap.cols + leftCol] && tileMap.tile[row * tileMap.cols + leftCol]->isCollidable;
        bool hitRight = tileMap.tile[row * tileMap.cols + rightCol] && tileMap.tile[row * tileMap.cols + rightCol]->isCollidable;

        if (hitLeft || hitRight)
        {
            hitbox.y = (row + 1) * tileMap.size;
            fallingVelocity = 0;
        }
    }
}