namespace engine
{
	struct vec3 {
		double x, y, z;
		vec3(x, y, z) : x(x), y(y), z(z);
		
		vec3 operator+(vec3 a) const {
			return vec3(x + a.x, y + a.y, z + a.z);
		}
		
		vec3 operator*(double a) const {
			return vec3(x * a, y * a, z * a);
		}
		
		vec3 operator*(vec3 a) const {
			return vec3(x * a.x, y * a.y, z * a.z);
		}
		
		vec3 operator-() const {
			return vec3(-x, -y, -z);
		}
		
		vec3 operator-(vec3 a) const {
			return vec3(x - a.x, y - a.y, z - a.z);
		}
		
		vec3 operator/(double a) const {
			return *this * (1.0/a);
		}
		
		double norm() {
			return x*x + y*y + z*z;
		}
		
		double abs() {
			return sqrt(norm());
		}
		
		vec3 normalize() {
			return *this / this->abs();
		}
		
		double dot(vec3 a) const {
			return *this * a;
		}
		
		vec3 cross(vec3 a) const {
			return vec3(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);
		}
	};
}