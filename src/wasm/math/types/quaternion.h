namespace engine
{
	struct quaternion {
		double x, y, z, w;
		
		quaternion() : x(0), y(0), z(0), w(1) {}
	};
}