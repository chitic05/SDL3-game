#pragma once
#include <SDL3/SDL.h>
#include <iostream> 
#include <stdexcept>    
#include <cstdlib> 

class RendererManager {
	public:
		static void Init(SDL_Window* window);
		static SDL_Renderer* getRenderer();
		static void Destroy();
	private:
		static SDL_Renderer* renderer;
};