#include "InputManager.h"
#include "MapUtils.h"

bool InputManager::WasButtonPressed(int button) const
{
	return MapUtils::getValueOrDefault(wasButtonPressed, button, false);
}

bool InputManager::WasButtonReleased(int button) const
{
	return MapUtils::getValueOrDefault(wasButtonReleased, button, false);
}

bool InputManager::ButtonCurrentState(int button) const
{
	return MapUtils::getValueOrDefault(buttonCurrentState, button, false);
}

bool InputManager::WasKeyPressed(SDL_Keycode key) const
{
	return MapUtils::getValueOrDefault(wasKeyPressed, key, false);
}

bool InputManager::WasKeyReleased(SDL_Keycode key) const
{
	return MapUtils::getValueOrDefault(wasKeyReleased, key, false);
}

bool InputManager::KeyCurrentState(SDL_Keycode key) const
{
	return MapUtils::getValueOrDefault(keyCurrentState, key, false);
}

void InputManager::ResetInputStates()
{
	MapUtils::fill(wasButtonPressed, false);
	MapUtils::fill(wasButtonReleased, false);
	MapUtils::fill(wasKeyPressed, false);
	MapUtils::fill(wasKeyReleased, false);
}

void InputManager::HandleEvent(const SDL_Event& sdlEvent)
{
	switch (sdlEvent.type)
	{
	case SDL_EVENT_MOUSE_BUTTON_DOWN:
		wasButtonPressed[sdlEvent.button.button] = true;
		buttonCurrentState[sdlEvent.button.button] = true;
		break;
	case SDL_EVENT_MOUSE_BUTTON_UP:
		wasButtonReleased[sdlEvent.button.button] = true;
		buttonCurrentState[sdlEvent.button.button] = false;
		break;
	case SDL_EVENT_MOUSE_MOTION:
		mousePositionX = sdlEvent.motion.x;
		mousePositionY = sdlEvent.motion.y;
		break;
	case SDL_EVENT_KEY_DOWN:
		if (!sdlEvent.key.repeat)
		{
			wasKeyPressed[sdlEvent.key.key] = true;
			keyCurrentState[sdlEvent.key.key] = true;
		}
		break;
	case SDL_EVENT_KEY_UP:
		wasKeyReleased[sdlEvent.key.key] = true;
		keyCurrentState[sdlEvent.key.key] = false;
		break;
	default:
		break;
	}
}

int InputManager::GetHorizontalAxis() const
{
	if (KeyCurrentState(SDLK_A))
	{
		return -1;
	}

	if (KeyCurrentState(SDLK_D))
	{
		return +1;
	}

	return 0;
}

int InputManager::GetVerticalAxis() const
{
	if (KeyCurrentState(SDLK_S))
	{
		return -1;
	}

	if (KeyCurrentState(SDLK_W))
	{
		return +1;
	}

	return 0;
}