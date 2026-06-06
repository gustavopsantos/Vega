#include "GameEngine.h"
#include "MovableQuad.h"
#include "Vector2.h"
#include <cmath>
#include <algorithm>

void MovableQuad::Start()
{}

void MovableQuad::Update()
{
	const float quadSize = 100.0f;
	int horizontal = GetEngine().m_InputManager->GetHorizontalAxis();
	int vertical = GetEngine().m_InputManager->GetVerticalAxis() * -1; // (0, 0) coordinate is on top left, so x increases to the right, and y increases to the bottom	
	Vector2 axis = Vector2(horizontal, vertical).ClampMagnitude(1.0f);
	const int movementSpeed = 400; // Pixels per second
	m_Position += axis * movementSpeed * GetEngine().m_TimeManager->GetDeltaTimeSecs();

	int windowWidth;
	int windowHeight;
	SDL_GetWindowSize(GetEngine().m_Window, &windowWidth, &windowHeight);

	m_Position.x = std::clamp(m_Position.x, 0.0f, windowWidth - quadSize);
	m_Position.y = std::clamp(m_Position.y, 0.0f, windowHeight - quadSize);
	SDL_Log("Horizontal %d Vertical %d", horizontal, vertical);
}

void MovableQuad::Render()
{
	const int cubeSize = 100;
	SDL_FRect rect = { m_Position.x, m_Position.y, cubeSize, cubeSize };
	SDL_SetRenderDrawColor(GetEngine().m_Renderer, 0, 200, 255, 255);
	SDL_RenderFillRect(GetEngine().m_Renderer, &rect);
}