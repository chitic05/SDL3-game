#include "extras/resource_manager.h"

const char* ResourceManager::Textures_Path = "./res/data/texture_data.json";
const char* ResourceManager::EntityData_Path = "./res/data/entity_data.json";

nlohmann::json ResourceManager::textureData = LoadJSON(ResourceManager::Textures_Path);
nlohmann::json ResourceManager::entityData = LoadJSON(ResourceManager::EntityData_Path);

std::unordered_map<int, std::string> ResourceManager::Texture::id_to_name;

std::string ResourceManager::Texture::GetTexturePath(const std::string& textureName) {
	if (textureData.contains(textureName) && textureData[textureName].is_object()) {
		return textureData[textureName]["path"];
	}
	else throw std::runtime_error("Texture " + textureName + " doesn't exist in texture_paths.json");
}

nlohmann::json& ResourceManager::Entity::GetEntityData(const std::string& entityName) {
	if (entityData.contains(entityName))
		return entityData[entityName];
	else
		throw std::runtime_error("There is no such entity");
}

void ResourceManager::Texture::BuildIDMap()
{
	for (auto& [key, value] : textureData.items())
	{
		if (value.is_object() && value.contains("id") && value["id"].is_number_integer()) {
			ResourceManager::Texture::id_to_name[value["id"]] = key;
		}
		else {
			throw std::runtime_error("Invalid or missing ID for texture: " + key);
		}
	}
}
