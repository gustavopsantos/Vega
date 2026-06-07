#pragma once
#include "SDL3/SDL.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "GameObject.h"
#include <memory>
#include <vector>

class GameEngine
{
public:
	GameEngine(int width, int height, const char* const title);
	GameEngine(const GameEngine&) = delete;
	GameEngine& operator=(const GameEngine&) = delete;
	~GameEngine();

	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
	TimeManager m_TimeManager;
	InputManager m_InputManager;
	
	int Run();
	void RegisterGameObject(std::unique_ptr<GameObject> gameObject);
	
private:
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
};