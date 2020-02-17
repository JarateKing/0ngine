namespace engine
{
	struct Plane {
		// point-normal form description of a plane
		float a, b, c, d;
	
		Plane() { a = 0; b = 1; c = 0; d = 0; }
		Plane(float pA, float pB, float pC, float pD) : a(pA), b(pB), c(pC), d(pD) {}
	
		// helpful for some operations, like generating frustums
		float &operator [] (int i)
		{
			switch (i)
			{
			case 0:
				return a;
			case 1:
				return b;
			case 2:
				return c;
			case 3:
				return d;
			}
		}
	};
}