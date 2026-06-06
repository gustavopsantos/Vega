#pragma once
#include "GameObject.h"
#include "Vector2.h"

class MovableQuad : public GameObject
{
public:
	MovableQuad(const GameEngine& gameEngine) : GameObject(gameEngine) {}
	void Start() override;
	void Update() override;
	void Render() override;
private:
	Vector2 m_Position;
};