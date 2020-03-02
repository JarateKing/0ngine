namespace engine
{
	class FPS {
	public:
		FPS();
		~FPS();
		void Update();
		
		double GetDelta();
		double GetFramerate();
		
	private:
		double curTime;
		double oldTime;
		double* record = new double[10];
		int recordCount = 0;
		int recordPos = 0;
	};
}