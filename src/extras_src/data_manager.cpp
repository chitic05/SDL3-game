#include "extras/data_manager.h"

const char* Data::Textures_Path = "./res/data/texture_data.json";
const char* Data::EntityData_Path = "./res/data/entity_data.json";
const char* Data::ClienData_Path = "./res/data/client_data.json";


const nlohmann::json Data::textureData = LoadJSON(Data::Textures_Path);
const nlohmann::json Data::entityData = LoadJSON(Data::EntityData_Path);
const nlohmann::json Data::clientData = LoadJSON(Data::ClienData_Path);


std::string Data::Texture::GetTexturePath(const std::string& textureName) {
	if (textureData.contains(textureName) && textureData[textureName].is_object()) {
		return textureData[textureName]["path"];
	}
	else throw std::runtime_error("Texture " + textureName + " doesn't exist in texture_paths.json");
}


std::unordered_map<int, std::string> Data::Texture::id_to_name;
const nlohmann::json& Data::Entity::GetEntityData(const std::string& entityName) {
	if (entityData.contains(entityName))
		return entityData[entityName];
	else
		throw std::runtime_error("There is no such entity");
}
void Data::Texture::BuildIDMap()
{
	for (auto& [key, value] : textureData.items())
	{
		if (value.is_object() && value.contains("id") && value["id"].is_number_integer()) {
			Data::Texture::id_to_name[value["id"]] = key;
		}
		else {
			throw std::runtime_error("Invalid or missing ID for texture: " + key);
		}
	}
}

Vector2<int> Data::Client::getResolution(){
	if (clientData.contains("resolution") && clientData["resolution"].is_object())
		return Vector2<int>(clientData["resolution"]["x"], clientData["resolution"]["y"]);
	else
		throw std::runtime_error("There is no resolution set in the clientData");
}
