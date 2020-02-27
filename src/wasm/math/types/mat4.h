namespace engine
{
	struct mat4 {
		double v[4][4];
		
		// identity matrix
		mat4() {
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					v[i][j] = i == j;
		}
	};
}