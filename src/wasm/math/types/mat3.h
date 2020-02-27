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
	};
}