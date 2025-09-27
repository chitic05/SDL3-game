#pragma once

#include "extras/global_var.h"

#include "nlohmann/json.hpp"
#include "stb_image.h"
#include <SDL3/SDL.h>
#include <string>
#include <stdexcept>
#include <fstream>

nlohmann::json LoadJSON(const std::string& filePath);

SDL_Texture* LoadTexturePNG(const std::string& filePath);