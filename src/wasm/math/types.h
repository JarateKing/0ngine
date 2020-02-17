#ifndef MATH_TYPES_H
#define MATH_TYPES_H

#include <cmath>

struct vec2;
struct vec3;

struct vec2 {
	double x, y;
};
struct vec3 {
	double x, y, z;
};

#include "types/vec2.h"
#include "types/vec3.h"
#include "types/plane.h"

#endif