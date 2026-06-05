#include "Engine.h"

#include <iostream>
#include <vector>
#include <format>
#include <thread>
#include <cmath>

int GameEngine::Run()
{
	const Uint32 windowWidth = 800;
	const Uint32 windowHeight = 600;
	const float screenCenterX = windowWidth / 2.0f;
	const float screenCenterY = windowHeight / 2.0f;

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("SDL_Init failed: %s", SDL_GetError());
		return 1;
	}

	m_Window = SDL_CreateWindow(
		"Vega",
		windowWidth,
		windowHeight,
		0
	);

	if (!m_Window)
	{
		SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, nullptr);

	if (!m_Renderer)
	{
		SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
		return 1;
	}

	bool running = true;
	SDL_Event event;

	while (running)
	{
		Uint64 timeMs = SDL_GetTicks();
		float timeSeconds = timeMs / 1000.0f;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT || (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE))
			{
				running = false;
			}
		}

		SDL_SetRenderDrawColor(m_Renderer, 25, 25, 25, 255);
		SDL_RenderClear(m_Renderer);

		const int cubeSize = 100;
		const int cubeSizeHalf = cubeSize / 2.0f;
		const int circleRadius = 200;
		float x = (std::cos(timeSeconds) * circleRadius) + screenCenterX - cubeSizeHalf;
		float y = (std::sin(timeSeconds) * circleRadius) + screenCenterY - cubeSizeHalf;
		SDL_FRect rect = { x, y, cubeSize, cubeSize };
		SDL_SetRenderDrawColor(m_Renderer, 0, 200, 255, 255);
		SDL_RenderFillRect(m_Renderer, &rect);

		SDL_RenderPresent(m_Renderer);
	}

	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}