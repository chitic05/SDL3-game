#include "tiles/tilemap.h"

std::unordered_map<int, std::function<std::unique_ptr<Tile>(const Vector2<float>&, float, int)>> TileMap::mapFactory = {
    {0, [](const Vector2<float>& position, float size, int ID) { return nullptr;}},
    {1, [](const Vector2<float>& position, float size, int ID) { return std::make_unique<Tile>(position, size, 2); }},
    {3, [](const Vector2<float>& position, float size, int ID) { return std::make_unique<Tile>(position, size, 3); }}
};

//Building the TileMap using constructor 
TileMap::TileMap(const nlohmann::json& mapData){
    if (mapData.contains("tileSize") && mapData["tileSize"].is_number_integer())
        size = mapData["tileSize"];
    else
        throw std::runtime_error("Tile size is not available");

    if (mapData.contains("intMap") && mapData["intMap"].is_array()) {
        auto& intMap = mapData["intMap"];
        int width = Data::Client::getResolution().x;
        int height = Data::Client::getResolution().y;
        
        rows = height / size;
        cols = width / size;

        int i = 0;
        tile.reserve(intMap.size());
        for(auto& val : intMap) {
            int row = i / cols;
            int col = i % cols;
            i++;
            tile.push_back(mapFactory[val](Vector2<float>(row* size, col* size), size, val));
        }

    }
}

void TileMap::Render() {
    for (auto& t : tile) {
        if(t)
            t->Render();
    }
}