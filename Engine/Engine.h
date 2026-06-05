#pragma once
#include "SDL3/SDL.h"

class GameEngine
{
public:
	GameEngine(int width, int height, const char* const title);
	~GameEngine();
	int Run();

private:
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
};