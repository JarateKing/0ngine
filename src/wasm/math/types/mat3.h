namespace engine
{
	struct mat3 {
		double v[3][3];
		
		// identity matrix
		mat3() {
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					v[i][j] = i == j;
		}
		
		mat3(double** arr) {
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					v[i][j] = arr[i][j];
		}
		
		mat3(double aa, double ab, double ac, double ba, double bb, double bc, double ca, double cb, double cc) {
			v[0][0] = aa;
			v[0][1] = ab;
			v[0][2] = ac;
			v[1][0] = ba;
			v[1][1] = bb;
			v[1][2] = bc;
			v[2][0] = ca;
			v[2][1] = cb;
			v[2][2] = cc;
		}
	};
}