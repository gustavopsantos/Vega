#include "GameObject.h"

GameObject::GameObject(const GameEngine& engine) : m_GameEngine(engine) { }

const GameEngine& GameObject::GetEngine() const
{
    return m_GameEngine;
}