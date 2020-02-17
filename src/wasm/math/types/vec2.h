#import "../types.h"

namespace engine
{
	struct vec2 {
		double x, y;
		vec2(double x, double y) : x(x), y(y) {}
		
		vec2 operator+(vec2 a) const {
			return vec2(x + a.x, y + a.y);
		}
		
		vec2 operator*(double a) const {
			return vec2(x * a, y * a);
		}
		
		vec2 operator*(vec2 a) const {
			return vec2(x * a.x, y * a.y);
		}
		
		vec2 operator-() const {
			return vec2(-x, -y);
		}
		
		vec2 operator-(vec2 a) const {
			return vec2(x - a.x, y - a.y);
		}
		
		vec2 operator/(double a) const {
			return *this * (1.0/a);
		}
		
		double norm() {
			return x*x + y*y;
		}
		
		double abs() {
			return std::sqrt(norm());
		}
		
		vec2 normalize() {
			return *this / this->abs();
		}
		
		double dot(vec2 a) const {
			return x * a.x + y * a.y;
		}
		
		double cross(vec2 a) const {
			return x * a.y - y * a.x;
		}
	};
}