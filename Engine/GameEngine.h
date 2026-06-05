#pragma once
#include "SDL3/SDL.h"
#include "AGameObject.h"
#include <memory>
#include <vector>

class GameEngine
{
public:
	GameEngine(int width, int height, const char* const title);
	~GameEngine();
	void RegisterGameObject(std::unique_ptr<AGameObject> gameObject);
	int Run();
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
private:
	std::vector<std::unique_ptr<AGameObject>> m_gameObjects;
};