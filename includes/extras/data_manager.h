#pragma once
#include "nlohmann/json.hpp"
#include "extras/custom_sdl.h"
#include "extras/custom_math.hpp"
#include <unordered_map>

class Data {
public:
    struct Entity {
        static const nlohmann::json& GetEntityData(const std::string& entityName);

    };
    struct Texture {
        static std::string GetTexturePath(const std::string& textureName);
        static std::unordered_map<int, std::string> id_to_name; // maybe make it private, but it takes too long
        static void BuildIDMap();
    };
    
    struct Client {
        static Vector2<int> getResolution();
    };
private:
    static const char* Textures_Path; // path to the json file where i can find all the texture paths
    static const char* EntityData_Path;
    static const char* ClienData_Path;

    static const nlohmann::json textureData; // the json file with all the textures
    static const nlohmann::json entityData;
    static const nlohmann::json clientData;

     
};
       