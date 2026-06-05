#pragma once
#include <chrono>

class TimeManager
{
public:
	TimeManager();

	//Get the time elapsed since last frame
	float GetDeltaTimeSecs() const;

	//Current time at the start of this frame since the clock was started
	float GetFrameStartTimeSecs() const;

private:
	friend class GameEngine;

	using clock = std::chrono::steady_clock;

	clock::time_point m_startTime;
	clock::time_point m_previousFrameTime;
	clock::time_point m_currentFrameTime;
	float m_deltaTimeSecs = 0.0f;
	float m_frameStartTimeSecs = 0.0f;

	void Update();
};