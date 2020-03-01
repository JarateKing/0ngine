namespace engine
{
	struct mat2 {
		double v[2][2];
		
		// identity matrix
		mat2() {
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					v[i][j] = i == j;
		}
		
		mat2(double** arr) {
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					v[i][j] = arr[i][j];
		}
		
		mat2(double aa, double ab, double ba, double bb) {
			v[0][0] = aa;
			v[0][1] = ab;
			v[1][0] = ba;
			v[1][1] = bb;
		}
		
		double* operator[](int index) {
			return v[index];
		}
	};
}