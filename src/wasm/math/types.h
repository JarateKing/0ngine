#ifndef MATH_TYPES_H
#define MATH_TYPES_H

#include <cmath>

// struct declarations for other struct constructors
struct vec2 { double x, y; };
struct vec3 { double x, y, z; };
struct vec4 { double x, y, z, w; };

struct mat2 { double v[2][2]; };
struct mat3 { double v[3][3]; };
struct mat4 { double v[4][4]; };

#include "types/color.h"
#include "types/vec2.h"
#include "types/vec3.h"
#include "types/vec4.h"
#include "types/plane.h"
#include "types/mat2.h"
#include "types/mat3.h"
#include "types/mat4.h"
#include "types/quaternion.h"

#endif