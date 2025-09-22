#pragma once
#include "nlohmann/json.hpp"
#include "extras/custom_sdl.h"
class ResourceManager {
    public:
        static std::string GetTexturePath(const std::string& textureName);
        static nlohmann::json& GetEntityData(const std::string& entityName);
    private:
        static const char* Textures_Path; // path to the json file where i can find all the texture paths
        static const char* EntityData_Path;

        static nlohmann::json textures; // the json file with all the textures
        static nlohmann::json entityData;
};