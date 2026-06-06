#pragma once
#include "SDL3/SDL.h"

class GameEngine;

class GameObject
{
public:
    explicit GameObject(const GameEngine& gameEngine);
    virtual ~GameObject() = default;

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;

protected:
    const GameEngine& GetEngine() const;

private:
    const GameEngine& m_GameEngine;
};