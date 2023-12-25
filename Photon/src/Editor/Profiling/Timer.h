#pragma once

#include <string>
#include <chrono>

namespace Photon
{
	class Timer
	{
	public:
		// TODO: Add documentation comments to Timer members
		Timer();
		~Timer();

		void Reset();

		float Elapsed();
		float ElapsedMillis();

	protected:
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
	};

	class ScopedTimer
	{
	public:
		// TODO: Add documentation comments to ScopedTimer members
		ScopedTimer(const std::string& name);
		~ScopedTimer();

	protected:
	private:
		std::string m_Name;
		Timer m_Timer;
	};
}
