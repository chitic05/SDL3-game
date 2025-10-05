#pragma once
#include <SDL3/SDL.h>
#include <iostream> 
#include <stdexcept>    
#include <cstdlib> 

class GlobalVar {
	public:

		struct Physics {
			static int gravity;
		};

		static void InitRenderer(SDL_Window* window);
		static void InitKeyboard();
		static void Destroy();

		static SDL_Renderer* renderer;
		static const bool* keyboardState;
		static double deltaTime;

	private:
		
		
		
};