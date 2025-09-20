#include "extras/renderer_manager.h"

SDL_Renderer* RendererManager::renderer = nullptr;

void RendererManager::Init(SDL_Window* window){

    if(RendererManager::renderer != nullptr) return; //it's already initalized

    RendererManager::renderer = SDL_CreateRenderer(window, nullptr);
    if (!RendererManager::renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        std::exit(1);
    }
}

SDL_Renderer* RendererManager::getRenderer() {
    if (!RendererManager::renderer)
        throw std::runtime_error("Renderer is not initialized");
    else
        return RendererManager::renderer;
}

void RendererManager::Destroy() {
    if (RendererManager::renderer != nullptr) {
        SDL_DestroyRenderer(RendererManager::renderer);
        RendererManager::renderer = nullptr;
    }
    else throw std::runtime_error("Renderer is not initialized");
}