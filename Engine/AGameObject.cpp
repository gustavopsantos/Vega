#include "AGameObject.h"

AGameObject::AGameObject(const GameEngine& engine) : m_GameEngine(engine) { }

const GameEngine& AGameObject::GetGameEngine() const
{
    return m_GameEngine;
}