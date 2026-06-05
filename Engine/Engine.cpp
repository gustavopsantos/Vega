#include "Engine.h"

#include <iostream>
#include <vector>
#include <format>
#include <thread>
#include <cmath>

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
}

GameEngine::~GameEngine()
{
	if (m_Renderer)
		SDL_DestroyRenderer(m_Renderer);

	if (m_Window)
		SDL_DestroyWindow(m_Window);

	SDL_Quit();
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
		float x = (std::cos(timeSeconds) * circleRadius) + windowCenterX - cubeSizeHalf;
		float y = (std::sin(timeSeconds) * circleRadius) + windowCenterY - cubeSizeHalf;
		SDL_FRect rect = { x, y, cubeSize, cubeSize };
		SDL_SetRenderDrawColor(m_Renderer, 0, 200, 255, 255);
		SDL_RenderFillRect(m_Renderer, &rect);

		SDL_RenderPresent(m_Renderer);
	}

	return 0;
}