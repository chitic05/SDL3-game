#include "extras/resource_manager.h"

const char* ResourceManager::Textures_Path = "./res/data/texture_paths.json";
const char* ResourceManager::EntityData_Path = "./res/data/entity_data.json";

nlohmann::json ResourceManager::textures = LoadJSON(ResourceManager::Textures_Path);
nlohmann::json ResourceManager::entityData = LoadJSON(ResourceManager::EntityData_Path);

std::string ResourceManager::GetTexturePath(const std::string& textureName) {
	if (textures.contains(textureName) && textures[textureName].is_string()) {
		return textures[textureName];
	}
	else throw std::runtime_error("Texture " + textureName + " doesn't exist in texture_paths.json");
}

nlohmann::json& ResourceManager::GetEntityData(const std::string& entityName) {
	if (entityData.contains(entityName))
		return entityData[entityName];
	else
		throw std::runtime_error("There is no such entity");
}