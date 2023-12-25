#include "Timer.h"

#include <iostream>

namespace Photon
{
	Timer::Timer()
	{
		Reset();
	}

	Timer::~Timer()
	{
		// NOTE: Currently does nothing
	}

	void Timer::Reset()
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	float Timer::Elapsed()
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;
	}

	float Timer::ElapsedMillis()
	{
		return Elapsed() * 1000.0f;
	}

	ScopedTimer::ScopedTimer(const std::string& name)
	{
		m_Name = name;
	}

	ScopedTimer::~ScopedTimer()
	{
		float time = m_Timer.ElapsedMillis();
		std::printf("[TIMER] %s - %f ms\n", m_Name.c_str(), time);
	}
}