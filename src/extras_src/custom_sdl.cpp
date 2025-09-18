#define STB_IMAGE_IMPLEMENTATION

#include "extras/custom_sdl.h"

nlohmann::json LoadJSON(const std::string& filePath){
    std::ifstream file(filePath);
    if (!file.is_open())
        throw std::runtime_error("Can't find file at: " + filePath);
    nlohmann::json js;
    try {
        file >> js;
    }
    catch (const nlohmann::json::parse_error& e) {
        throw std::runtime_error("JSON parse error in " + filePath + ": " + std::string(e.what()));
    }

    file.close();
    return js;
}

SDL_Texture* LoadTexturePNG(const std::string& filePath, SDL_Renderer* renderer)
{
    int w, h, pitch;
    unsigned char* pixels = stbi_load(filePath.c_str(), &w, &h, &pitch, STBI_rgb_alpha);
    if (!pixels)
        throw std::runtime_error("Failed to load image: " + filePath);

    SDL_Surface* surface = SDL_CreateSurfaceFrom(
        w,                      // width in pixels
        h,                      // height in pixels
        SDL_PIXELFORMAT_ABGR8888, // pixel format
        pixels,                 // raw pixel data from stbi_load
        w*4           // CORRECTED pitch (bytes per row)
    );

    if (!surface) {
        stbi_image_free(pixels);
        throw std::runtime_error("Failed to create SDL_Surface");
    }

    SDL_Texture* rawTexture = SDL_CreateTextureFromSurface(renderer, surface);

    // Cleanup
    SDL_DestroySurface(surface);

    if (!rawTexture) {
        // Print the SDL error message
        std::string errorMessage = SDL_GetError();
        throw std::runtime_error("Failed to create SDL_Texture: " + errorMessage);
    }

    return rawTexture;
}
