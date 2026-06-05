#include "TimeManager.h"
#include <chrono>

TimeManager::TimeManager()
{
	m_startTime = clock::now();
	m_previousFrameTime = m_startTime;
	m_currentFrameTime = m_startTime;
}

void TimeManager::Update()
{
	m_currentFrameTime = clock::now();
	m_deltaTimeSecs = std::chrono::duration<float>(m_currentFrameTime - m_previousFrameTime).count();
	m_frameStartTimeSecs = std::chrono::duration<float>(m_currentFrameTime - m_startTime).count();
	m_previousFrameTime = m_currentFrameTime;
}

float TimeManager::GetDeltaTimeSecs() const
{
	return m_deltaTimeSecs;
}

float TimeManager::GetFrameStartTimeSecs() const
{
	return m_frameStartTimeSecs;
}