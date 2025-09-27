#include "SDL_App.hpp"
#include <iostream>
int main() {
    SDLApp app("Nicu", 1280, 720);
    app.run();
    return 0;
}