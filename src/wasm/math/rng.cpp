#include "rng.h"

namespace engine
{
	bool RNG::Bool() {
		return GetRandom(0, 1) == 1;
	}

	bool RNG::Bool(float trueChance) {
		return GetRandom(0.0f, 1.0f) < trueChance;
	}

	int RNG::GetRandom(int min, int max) {
		std::uniform_int_distribution<int> distribution(min, max);
		return distribution(*gen());
	}
	
	long RNG::GetRandom(long min, long max) {
		std::uniform_int_distribution<long> distribution(min, max);
		return distribution(*gen());
	}

	float RNG::GetRandom(float min, float max) {
		std::uniform_real_distribution<float> distribution(min, max);
		return distribution(*gen());
	}

	double RNG::GetRandom(double min, double max) {
		std::uniform_real_distribution<double> distribution(min, max);
		return distribution(*gen());
	}
	
	std::mt19937* RNG::gen() {
		static std::random_device randomDevice;
		static std::mt19937 gen(randomDevice());
		return &gen;
	}
}