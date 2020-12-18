#include <cmath>

namespace engine
{
	class Math
	{
	public:
		static int wrap(int min, int max, int val);
		static long wrap(long min, long max, long val);
		static float wrap(float min, float max, float val);
		static double wrap(double min, double max, double val);
		
		static int clamp(int min, int max, int val);
		static long clamp(long min, long max, long val);
		static float clamp(float min, float max, float val);
		static double clamp(double min, double max, double val);
		
		static float lerp(float start, float end, float percent);
		static double lerp(double start, double end, float percent);

		static float easeIn(float percent);
		static float easeOut(float percent);
		static float ease(float percent);
		
		static int sign(float val);
		static int sign(double val);
	};
}
