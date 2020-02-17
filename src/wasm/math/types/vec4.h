#ifndef MATH_TYPES_VEC4_H
#define MATH_TYPES_VEC4_H

#include "../types.h"

namespace engine
{
	struct vec4 {
		double x, y, z, w;
		
		vec4() : x(0), y(0), z(0), w(0) {}
		vec4(double v) : x(v), y(v), z(v), w(0) {}
		vec4(vec2 const& v) : x(v.x), y(v.y), z(0), w(0) {}
		vec4(vec3 const& v) : x(v.x), y(v.y), z(v.z), w(0) {}
		vec4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
		
		vec4 operator+(vec4 a) const {
			return vec4(x + a.x, y + a.y, z + a.z, w + a.w);
		}
		
		vec4 operator*(double a) const {
			return vec4(x * a, y * a, z * a, w * a);
		}
		
		vec4 operator*(vec4 a) const {
			return vec4(x * a.x, y * a.y, z * a.z, w * a.w);
		}
		
		vec4 operator-() const {
			return vec4(-x, -y, -z, -w);
		}
		
		vec4 operator-(vec4 a) const {
			return vec4(x - a.x, y - a.y, z - a.z, w - a.w);
		}
		
		vec4 operator/(double a) const {
			return *this * (1.0/a);
		}
		
		double norm() {
			return x*x + y*y + z*z + w*w;
		}
		
		double abs() {
			return std::sqrt(norm());
		}
		
		vec4 normalize() {
			return *this / this->abs();
		}
		
		double dot(vec4 a) const {
			return x * a.x + y * a.y + z * a.z + w * a.w;
		}
	};
}

#endif