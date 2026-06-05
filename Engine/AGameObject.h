#pragma once
#include "SDL3/SDL.h"

class GameEngine;

class AGameObject
{
public:
    explicit AGameObject(GameEngine& gameEngine);
    virtual ~AGameObject() = default;

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;

protected:
    GameEngine& GetGameEngine() const;

private:
    GameEngine& m_GameEngine;
};