#include "GameEngine.h"
#include "AutoMovableCube.h"
#include <cmath>

void AutoMovableCube::Start()
{}

void AutoMovableCube::Update()
{
	float timeSecs = GetGameEngine().m_TimeManager->GetFrameStartTimeSecs();
	float windowCenterX = 400;
	float windowCenterY = 300;
	const int cubeSize = 100;
	const int cubeSizeHalf = cubeSize / 2.0f;
	const int amplitude = 200;
	const float frequency = 4.0f;

	m_X = (std::cos(timeSecs * frequency) * amplitude) + windowCenterX - cubeSizeHalf;
	m_Y = windowCenterY - cubeSizeHalf;
}

void AutoMovableCube::Render()
{
	const int cubeSize = 100;
	SDL_FRect rect = { m_X, m_Y, cubeSize, cubeSize };
	SDL_SetRenderDrawColor(GetGameEngine().m_Renderer, 0, 200, 255, 255);
	SDL_RenderFillRect(GetGameEngine().m_Renderer, &rect);
}