#include "fps_counter.h"
#include <emscripten.h>
#include <cmath>

namespace engine
{
	FPS::FPS() {
		
	}
	
	FPS::~FPS() {
		
	}
	
	void FPS::Update() {
		oldTime = curTime;
		curTime = emscripten_get_now() / 1000.0;
		
		record[recordPos++] = GetDelta();
		recordCount = (recordCount < 10) ? recordCount + 1 : 10;
		recordPos = (recordPos >= 10) ? 0 : recordPos;
	}
	
	double FPS::GetDelta() {
		return curTime - oldTime;
	}
	
	double FPS::GetFramerate() {
		// @TODO: make not recalc average every time
		
		double sum = 0;
		for (int i = 0; i < recordCount; i++)
			sum += record[i];
		if (recordCount > 0)
			sum /= recordCount;
		return 1.0 / sum;
	}
}