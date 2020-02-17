#include "../basic.h"

namespace engine
{
	int Math::wrap(int min, int max, int val) {
		if (min >= max) return min;
		return min + (max - min + val) % (max - min);
	}
	
	long Math::wrap(long min, long max, long val) {
		if (min >= max) return min;
		return min + (max - min + val) % (max - min);
	}
	
	float Math::wrap(float min, float max, float val) {
		if (min >= max) return min;
		return min + std::fmodf(max - min + val, max - min);
	}
	
	double Math::wrap(double min, double max, double val) {
		if (min >= max) return min;
		return min + std::fmodf(max - min + val, max - min);
	}
	
	int Math::clamp(int min, int max, int val) {
		if (val < min) return min;
		if (val > max) return max;
		return val;
	}
	
	long Math::clamp(long min, long max, long val) {
		if (val < min) return min;
		if (val > max) return max;
		return val;
	}
	
	float Math::clamp(float min, float max, float val) {
		if (val < min) return min;
		if (val > max) return max;
		return val;
	}
	
	double Math::clamp(double min, double max, double val) {
		if (val < min) return min;
		if (val > max) return max;
		return val;
	}
}
