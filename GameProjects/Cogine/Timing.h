#pragma once

namespace Cogine {

	class FPSLimiter {
	public:
		FPSLimiter();
		void init(float maxFPS);

		void setMaxFPS(float maxFPS);

		void begin();

		float end();

	private:
		void calculateFPS();
		unsigned int m_startTicks;
		float m_fps, m_frameTime, m_maxFPS;

	};

}