#include "extras/global_var.h"

int GlobalVar::Physics::gravity = 3;

SDL_Renderer* GlobalVar::renderer = nullptr;
const bool* GlobalVar::keyboardState = nullptr;
double GlobalVar::deltaTime = 0;

void GlobalVar::InitRenderer(SDL_Window* window){

    if(GlobalVar::renderer != nullptr) return; //it's already initalized

    GlobalVar::renderer = SDL_CreateRenderer(window, nullptr);
    if (!GlobalVar::renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        std::exit(1);
    }
}


void GlobalVar::InitKeyboard(){
    keyboardState = SDL_GetKeyboardState(nullptr);

    if (keyboardState == nullptr)
        std::cerr << "Couldn't get the keyboard state\n";
}

void GlobalVar::Destroy() {
    if (GlobalVar::renderer != nullptr) {
        SDL_DestroyRenderer(GlobalVar::renderer);
        GlobalVar::renderer = nullptr;
    }else throw std::runtime_error("Renderer is not initialized");
}