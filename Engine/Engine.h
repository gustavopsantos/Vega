#pragma once
#include "SDL3/SDL.h"

class GameEngine
{
public:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	int Run();
};