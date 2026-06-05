#pragma once
#include "SDL3/SDL.h"

class GameEngine;

class AGameObject
{
public:
    explicit AGameObject(const GameEngine& gameEngine);
    virtual ~AGameObject() = default;

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;

protected:
    const GameEngine& GetGameEngine() const;

private:
    const GameEngine& m_GameEngine;
};