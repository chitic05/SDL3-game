#include "SDL3/SDL.h"
#include <iostream>
#include "levels/level_manager.h"
#include "extras/global_var.h"

class SDLApp {
public:

    // --- INITIZALIZATION ---
    SDLApp(const char* title, int width, int height) {
        std::cout << std::filesystem::current_path();
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL Init failed: " << SDL_GetError() << std::endl;
            std::exit(1);
        }

        window = SDL_CreateWindow(title, width, height, 0);
        if (!window) {
            std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
            SDL_Quit();
            std::exit(1);
        }

        GlobalVar::InitRenderer(window);
        GlobalVar::InitKeyboard();
        Data::Texture::BuildIDMap();
       // SDL_RenderSetIntegerScale(renderer, SDL_TRUE);
    }

    // --- DESTROY ---
    ~SDLApp() {
        GlobalVar::Destroy();
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    
    // --- Game Loop ---
    void run() {
        LevelManager::changeLevel("test");
        
        LevelManager::currentLevel->Load();  //PROBLMEA URIASA LA LOAD

        const double targetFPS = 60.0;
        const double targetFrameTime = 1.0 / targetFPS;

        bool running = true;
        SDL_Event event;

        Uint64 now = SDL_GetPerformanceCounter();
        Uint64 last = SDL_GetPerformanceCounter();
        

        while (running) {
            last = now;
            now = SDL_GetPerformanceCounter();
            GlobalVar::deltaTime = static_cast<double>(now - last) / SDL_GetPerformanceFrequency();
            


            // --- Event Handling ---
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_EVENT_QUIT) {
                    running = false;
                }
            }

            LevelManager::currentLevel->Input();

            LevelManager::currentLevel->Update();
           // --- Rendering ---
            SDL_SetRenderDrawColor(GlobalVar::renderer, 100, 149, 237, 255); // Cornflower blue
            SDL_RenderClear(GlobalVar::renderer);
           
            LevelManager::currentLevel->Render();

            SDL_RenderPresent(GlobalVar::renderer);

            // --- Frame timing ---
            double frameTime = static_cast<double>(SDL_GetPerformanceCounter() - now) / SDL_GetPerformanceFrequency();/*divide the ticks to the tick frequency to obtain how many second it
                                                                                                                      took*/
            double delayTime = targetFrameTime - frameTime;
            if (delayTime > 0) {
                SDL_Delay(static_cast<Uint32>(delayTime * 1000)); // Convert seconds to ms
            }
        }
    }

private:
    SDL_Window* window = nullptr;
};