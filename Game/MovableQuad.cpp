#include "GameEngine.h"
#include "MovableQuad.h"
#include "Vector2.h"
#include <cmath>
#include <algorithm>

void MovableQuad::Start()
{}

void MovableQuad::Update()
{
	const GameEngine& engine = GetEngine();
	float dt = engine.m_TimeManager.GetDeltaTimeSecs();

	// Get movement input
	int horizontal = engine.m_InputManager.GetHorizontalAxis();
	int vertical = engine.m_InputManager.GetVerticalAxis() * -1; // (0, 0) coordinate is on top left, so x increases to the right, and y increases to the bottom	
	Vector2 axis = Vector2(horizontal, vertical).ClampMagnitude(1.0f);

	// Handle velocity
	Vector2 desiredVelocity = axis * m_MovementSpeed;
	m_Velocity = Vector2::MoveTowards(m_Velocity, desiredVelocity, m_Acceleration * dt);
	
	// Apply movement input
	m_Rect.x += m_Velocity.x * dt;
	m_Rect.y += m_Velocity.y * dt;

	// Clamp quad bounds within window
	int windowWidth;
	int windowHeight;
	SDL_GetWindowSize(engine.m_Window, &windowWidth, &windowHeight);
	m_Rect.x = std::clamp(m_Rect.x, 0.0f, windowWidth - m_Rect.w);
	m_Rect.y = std::clamp(m_Rect.y, 0.0f, windowHeight - m_Rect.h);
}

void MovableQuad::Render()
{
	const GameEngine& engine = GetEngine();
	SDL_SetRenderDrawColor(engine.m_Renderer, 0, 200, 255, 255);
	SDL_RenderFillRect(engine.m_Renderer, &m_Rect);
}