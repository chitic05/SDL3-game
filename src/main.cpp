#include "SDL_App.hpp"
#include <iostream>
int main() {
    SDLApp app("Nicu", 800, 600);
    app.run();
    return 0;
}