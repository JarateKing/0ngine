namespace engine
{
	class Math
	{
	public:
		static float lerp(float start, float end, float percent);
		static double lerp(double start, double end, float percent);

		static float easeIn(float percent);
		static float easeOut(float percent);
		static float ease(float percent);
	};
}
