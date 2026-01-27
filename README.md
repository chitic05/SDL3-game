# SDL3-game

A 2D platformer game written in C++ using SDL3. Levels, tiles and game data are driven by JSON files in the `res/` folder, allowing easy customization without recompiling.

## 🎮 Quick Start - How to Run the Game

### Prerequisites
- CMake 3.15 or higher
- C++17 compatible compiler (GCC, Clang, or MSVC)
- SDL3 (included in `externals/` folder)

### Building and Running

**On Linux/macOS:**
```bash
# 1. Clone the repository
git clone <your-repo-url>
cd SDL3-game

# 2. Build the game
mkdir -p build && cd build
cmake ..
cmake --build .

# 3. Run the game (from the build directory)
./SDL3_Game

**Alternative: Using pre-built executable**
If you have a pre-built executable in `out/release/`:
```bash
cd out/release
./SDL3_Game
```

**On Windows:**
```bash
# 1. Clone the repository
git clone <your-repo-url>
cd SDL3-game

# 2. Build the game
mkdir build
cd build
cmake ..
cmake --build . --config Release

# 3. Run the game
.\SDL3_Game.exe
```

### Controls
- **A** / **Left Arrow** - Move left
- **D** / **Right Arrow** - Move right
- **Space** - Jump
- **Goal:** Reach the exit tile (black tile) to advance to the next level

### Troubleshooting
- **Resources not found:** The game expects `res/` folder to be accessible. CMake automatically copies resources to the build directory.
- **Build errors:** Make sure you have CMake 3.15+ and a C++17 compiler installed.

## Overview
- Entry point: `src/main.cpp` constructs `SDLApp` (`includes/SDL_App.hpp`) which initializes SDL, creates the window/renderer and runs the main loop.
- Main subsystems:
  - Global state: `includes/extras/global_var.h` — holds `SDL_Renderer*`, keyboard state and `deltaTime` used across the game.
  - Resource management: `includes/extras/resource_manager.h` + `res/data/*.json` — maps texture names to file paths and provides entity data.
  - Levels: `includes/levels/level.h`, `includes/levels/level_manager.h`, implementations in `src/levels_src/` — levels load from `res/levels/<name>.json` and create `TileMap` and entity instances.
  - Entities & Tiles: headers in `includes/entities/` and `includes/tiles/` with implementations under `src/` (e.g. `player.cpp`, `tile.cpp`).

## Why JSON-driven?
Level layout, textures and entity properties are stored in JSON so designers can change maps, swap textures and tweak stats without touching C++ code.

## Important patterns and conventions
- Ownership: game objects use `std::unique_ptr` for ownership and lifetime (see `Level` fields).
- JSON safety: code uses `nlohmann::json` and checks `contains()` and `is_array()`/`is_object()` before accessing keys.
- Global renderer: `GlobalVar::renderer` must be initialized before calling any rendering or texture-loading functions.

## How resources are wired
- `res/data/texture_data.json` maps texture logical names to file paths and a numeric `id`.
- At startup `Data::Texture::BuildIDMap()` builds an `id -> name` mapping used by tile loading. Tiles in level JSON are numeric IDs stored in `map.intMap` (flattened row-major order).
- Entity definitions (e.g. `player`) live in `res/data/entity_data.json` and reference textures by name through `texture_name`.

## Adding textures (step-by-step)
1. Add the image file to `res/textures/` (example: `res/textures/my_tile.png`).
2. Edit `res/data/texture_data.json` and add an entry with a unique name and an unused integer `id`. Example format:

```json
{
  "MyTile": { "path": "./res/textures/my_tile.png", "id": 5 }
}
```

3. If you're running the binary from `build/` make sure the `res/` folder is available there (CMake usually copies resources at build time). The simplest approach during development is to run the binary from the repository root so `./res/` resolves correctly.
4. On startup `Data::Texture::BuildIDMap()` will populate the mapping used by tiles and other systems.

**Code notes about textures:**
- Tile code resolves a texture name from a numeric ID with `Data::Texture::id_to_name[ID]` and then calls `Data::Texture::GetTexturePath(name)` to get the image path.
- Entities typically read a `texture_name` from `entity_data.json` and load that texture during construction.

## Concrete JSON examples

### Example level (`res/levels/example_level.json`)

```json
{
  "player": { "position": [160, 400] },
  "nextLevel": "level2",
  "map": {
    "tileSize": 80,
    "intMap": [
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
      1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1,
      1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    ]
  }
}
```

### Example `res/data/texture_data.json` (mapping name -> path + id)

```json
{
  "JimCarrey": { "path": "./res/textures/JC.png", "id": 1 },
  "Grass":     { "path": "./res/textures/Grass.jpg", "id": 2 },
  "Cobblestone":{ "path": "./res/textures/Cobblestone.jpg", "id": 3 },
  "Black":     { "path": "./res/textures/Black.jpg", "id": 4 }
}
```

### Example `res/data/entity_data.json` (player)

```json
{
  "player": {
    "speed": 1000,
    "size": { "x": 50, "y": 50 },
    "jumpForce": -40,
    "texture_name": "JimCarrey"
  }
}
```

## Level JSON format notes
- `map.tileSize`: tile size in pixels (the engine uses this to compute collisions and layout).
- `map.intMap`: a flat array of integers representing tiles in row-major order. Use `0` for empty space and texture `id` values for tiles.
- `player.position`: an [x,y] pixel position. To determine tile column/row compute `col = x / tileSize`, `row = y / tileSize`.

## Debugging tips
- If tiles or entities render with the wrong images, check `res/data/texture_data.json` for correct `id` and `path`, ensure the path exists and is relative to the working directory, and check `Data::Texture::BuildIDMap()` errors.
- For JSON parsing issues, add temporary `std::cout` logs in `src/levels_src/level.cpp` or `src/extras_src/resource_manager.cpp` to dump parsed objects.

