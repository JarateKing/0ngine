#ifndef MATH_TYPES_VEC3_H
#define MATH_TYPES_VEC3_H

#include "../types.h"

namespace engine
{
	struct vec3 {
		double x, y, z;
		
		vec3() : x(0), y(0), z(0) {}
		vec3(double v) : x(v), y(v), z(v) {}
		vec3(vec2 const& v) : x(v.x), y(v.y), z(0) {}
		vec3(vec4 const& v) : x(v.x), y(v.y), z(v.z) {}
		vec3(double x, double y, double z) : x(x), y(y), z(z) {}
		
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
			return std::sqrt(norm());
		}
		
		vec3 normalize() {
			return *this / this->abs();
		}
		
		double dot(vec3 a) const {
			return x * a.x + y * a.y + z * a.z;
		}
		
		vec3 cross(vec3 a) const {
			return vec3(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);
		}
	};
}

#endif