#include "SDL_App.hpp"
#include <iostream>
int main() {
    SDLApp app("Nicu", Data::Client::getResolution().x, Data::Client::getResolution().y);
    app.run();
    return 0;
}