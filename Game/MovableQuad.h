#pragma once
#include "GameObject.h"
#include "Vector2.h"

class MovableQuad : public GameObject
{
public:
    MovableQuad(
        const GameEngine& gameEngine,
        float size,
        float movementSpeed,
        float acceleration)
        : GameObject(gameEngine),
        m_Rect{ 0.0f, 0.0f, size, size },
        m_MovementSpeed(movementSpeed),
        m_Acceleration(acceleration)
    {
    }
	void Start() override;
	void Update() override;
	void Render() override;
private:
	SDL_FRect m_Rect;
    Vector2 m_Velocity;
    float m_Acceleration;
	float m_MovementSpeed; // pixels per second
};