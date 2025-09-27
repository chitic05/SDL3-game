#pragma once
#include "nlohmann/json.hpp"
#include "extras/custom_sdl.h"
#include <unordered_map>

class ResourceManager {
public:
    struct Entity {
        static nlohmann::json& GetEntityData(const std::string& entityName);

    };
    struct Texture {
        static std::string GetTexturePath(const std::string& textureName);
        static std::unordered_map<int, std::string> id_to_name;
        static void BuildIDMap();
    };
private:
    static const char* Textures_Path; // path to the json file where i can find all the texture paths
    static const char* EntityData_Path;

    static nlohmann::json textureData; // the json file with all the textures
    static nlohmann::json entityData;

     
};
       