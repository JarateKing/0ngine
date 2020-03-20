namespace engine
{
	struct quaternion {
		double x, y, z, w;
		
		quaternion() : x(0), y(0), z(0), w(1) {}
		quaternion(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
		
		quaternion operator+(quaternion a) const {
			return quaternion(x + a.x, y + a.y, z + a.z, w + a.w);
		}
		quaternion operator-() const {
			return quaternion(-x, -y, -z, -w);
		}
		quaternion operator-(quaternion a) const {
			return quaternion(x - a.x, y - a.y, z - a.z, w - a.w);
		}
		quaternion operator*(double scale) const {
			return quaternion(x * scale, y * scale, z * scale, w * scale);
		}
		quaternion operator*(quaternion a) const {
			double A = (y * a.z) - (z * a.y);
			double B = (z * a.x) - (x * a.z);
			double C = (x * a.y) - (y * a.x);
			double D = ((x * a.x) + (y * a.y)) + (z * a.z);
			return quaternion(x * a.x + a.x * w + A, y * a.w + w * a.y + B, z * a.w + w * a.z + C, w * a.w - D);
		}
		bool operator==(quaternion a) const {
			return x == a.x && y == a.y && z == a.z && w == a.w;
		}
		bool operator!=(quaternion a) const {
			return !(x == a.x && y == a.y && z == a.z && w == a.w);
		}
	};
}