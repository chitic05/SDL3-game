#pragma once
#include "nlohmann/json.hpp"
#include "extras/custom_sdl.h"
class ResourceManager {
    public:
        static std::string GetTexturePath(const std::string& textureName);
    private:
        static const char* Textures_Path;
        static nlohmann::json textures;
};