#include <random>

namespace engine
{
	class RNG
	{
	public:
		static bool Bool();
		static bool Bool(float chanceOfTrue);
		static int GetRandom(int min, int max);
		static long GetRandom(long min, long max);
		static float GetRandom(float min, float max);
		static double GetRandom(double min, double max);
	private:
		static std::mt19937* gen();
	};
}