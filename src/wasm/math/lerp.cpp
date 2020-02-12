#include "lerp.h"
#include <cmath>

namespace engine
{
	float Math::lerp(float start, float end, float percent) {
		return start * (1 - percent) + end * (percent);
	}
	
	double Math::lerp(double start, double end, float percent) {
		return start * (1 - percent) + end * (percent);
	}
	
	float Math::easeIn(float percent) {
		return percent * percent * percent;
	}

	float Math::easeOut(float percent) {
		return pow(percent, 1.0 / 3.0);
	}

	float Math::ease(float percent) {
		return (1 - cos(M_PI * percent)) * 0.5;
	}
}
