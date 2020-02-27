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
		
		mat4(double** arr) {
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					v[i][j] = arr[i][j];
		}
		
		mat4(double aa, double ab, double ac, double ad, double ba, double bb, double bc, double bd, double ca, double cb, double cc, double cd, double da, double db, double dc, double dd) {
			v[0][0] = aa;
			v[0][1] = ab;
			v[0][2] = ac;
			v[0][3] = ad;
			v[1][0] = ba;
			v[1][1] = bb;
			v[1][2] = bc;
			v[1][3] = bd;
			v[2][0] = ca;
			v[2][1] = cb;
			v[2][2] = cc;
			v[2][3] = cd;
			v[3][0] = da;
			v[3][1] = db;
			v[3][2] = dc;
			v[3][3] = dd;
		}
	};
}