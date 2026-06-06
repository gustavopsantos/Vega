#include "GameEngine.h"
#include <iostream>
#include <vector>
#include <format>
#include <thread>
#include <cmath>

#define WINDOW_CLEAR_COLOR 25, 25, 25, 255

GameEngine::GameEngine(int width, int height, const char* const title)
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		throw std::runtime_error(SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		title,
		width,
		height,
		0);

	if (!m_Window)
	{
		SDL_Quit();
		throw std::runtime_error(SDL_GetError());
	}

	m_Renderer = SDL_CreateRenderer(m_Window, nullptr);

	if (!m_Renderer)
	{
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
		throw std::runtime_error(SDL_GetError());
	}

	const char* rendererName = SDL_GetRendererName(m_Renderer);

	SDL_Log("Renderer: %s", rendererName);

	m_TimeManager = new TimeManager();
	m_InputManager = new InputManager();
}

GameEngine::~GameEngine()
{
	if (m_Renderer)
		SDL_DestroyRenderer(m_Renderer);

	if (m_Window)
		SDL_DestroyWindow(m_Window);

	if (m_TimeManager)
		delete m_TimeManager;

	if (m_InputManager)
		delete m_InputManager;

	SDL_Quit();
}

void GameEngine::RegisterGameObject(std::unique_ptr<GameObject> gameObject)
{
	gameObject->Start();
	m_gameObjects.push_back(std::move(gameObject));
}

int GameEngine::Run()
{
	int windowWidth;
	int windowHeight;
	SDL_GetWindowSize(m_Window, &windowWidth, &windowHeight);
	const float windowCenterX = windowWidth / 2.0f;
	const float windowCenterY = windowHeight / 2.0f;

	bool running = true;
	SDL_Event event;

	while (running)
	{
		m_InputManager->ResetInputStates();

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT || (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE))
			{
				running = false;
			}
			else
			{
				m_InputManager->HandleEvent(event);
			}
		}

		m_TimeManager->Update();
		for (auto& object : m_gameObjects)
		{
			object->Update();
		}

		SDL_SetRenderDrawColor(m_Renderer, WINDOW_CLEAR_COLOR);
		SDL_RenderClear(m_Renderer);

		for (auto& object : m_gameObjects)
		{
			object->Render();
		}

		SDL_RenderPresent(m_Renderer);
	}

	return 0;
}