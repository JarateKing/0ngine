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
	};
}