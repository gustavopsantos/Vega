#pragma once
#include "SDL3/SDL.h"
#include <array>
#include <unordered_map>

class InputManager
{
public:
	InputManager() = default;

	int mousePositionX = 0;
	int mousePositionY = 0;

	// Mouse
	bool WasButtonPressed(int button) const;
	bool WasButtonReleased(int button) const;
	bool ButtonCurrentState(int button) const;

	// Keyboard
	bool WasKeyPressed(SDL_Keycode key) const;
	bool WasKeyReleased(SDL_Keycode key) const;
	bool KeyCurrentState(SDL_Keycode key) const;

	// Axis
	int GetHorizontalAxis() const;
	int GetVerticalAxis() const;

private:
	friend class GameEngine;

	void ResetInputStates();
	void HandleEvent(const SDL_Event& sdlEvent);

	// Mouse
	std::unordered_map<int, bool> wasButtonPressed;
	std::unordered_map<int, bool> wasButtonReleased;
	std::unordered_map<int, bool> buttonCurrentState;

	// Keyboard
	std::unordered_map<SDL_Keycode, bool> wasKeyPressed;
	std::unordered_map<SDL_Keycode, bool> wasKeyReleased;
	std::unordered_map<SDL_Keycode, bool> keyCurrentState;
};