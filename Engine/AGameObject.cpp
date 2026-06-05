#include "AGameObject.h"

AGameObject::AGameObject(GameEngine& engine) : m_GameEngine(engine) { }

GameEngine& AGameObject::GetGameEngine() const
{
    return m_GameEngine;
}