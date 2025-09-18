#include "extras/resource_manager.h"

const char* ResourceManager::Textures_Path = "./res/textures/texture_paths.json";

nlohmann::json ResourceManager::textures = LoadJSON(ResourceManager::Textures_Path);


std::string ResourceManager::GetTexturePath(const std::string& textureName) {
	if (textures.contains(textureName) && textures[textureName].is_string()) {
		return textures[textureName];
	}
	else throw std::runtime_error("Texture " + textureName + " doesn't exist in texture_paths.json");
}