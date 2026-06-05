#pragma once
#include "AGameObject.h"

class AutoMovableCube : public AGameObject
{
public:
	AutoMovableCube(GameEngine& gameEngine) : AGameObject(gameEngine) {}
	void Start() override;
	void Update() override;
	void Render() override;
private:
	float m_X = 0;
	float m_Y = 0;
};