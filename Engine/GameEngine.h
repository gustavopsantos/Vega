#pragma once
#include "SDL3/SDL.h"
#include "TimeManager.h"
#include "AGameObject.h"
#include <memory>
#include <vector>

class GameEngine
{
public:
	GameEngine(int width, int height, const char* const title);
	~GameEngine();

	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
	TimeManager* m_TimeManager = nullptr;
	
	int Run();
	void RegisterGameObject(std::unique_ptr<AGameObject> gameObject);
	
private:
	std::vector<std::unique_ptr<AGameObject>> m_gameObjects;
};