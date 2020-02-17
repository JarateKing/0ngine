#ifndef MATH_TYPES_COLOR_H
#define MATH_TYPES_COLOR_H

#include "../types.h"

#define ROUNDUP_EPSILON 0.99999

namespace engine
{
	struct colorRGB { float r, g, b; };
	struct colorRGBint { int r, g, b; };
	struct colorRGBA { float r, g, b, a; };
	struct colorRGBAint { int r, g, b, a; };
	struct colorRYB { float r, y, b; };
	struct colorHSV { float h, s, v; };
	struct colorHSL { float h, s, l; };
	struct colorCMYK { float c, m, y, k; };
	struct colorYUV { float y, u, v; };
	struct colorLMS { float l, m, s; };
	struct colorXYZ { float x, y, z; };
	struct colorLAB { float l, a, b; };
	struct colorLUV { float l, u, v; };
	struct colorLCH { float l, c, h; };
	
	struct color {
		float r, g, b, a;
		
		color() : r(0), g(0), b(0), a(1) {}
		color(double v) : r(v), g(v), b(v), a(1) {}
		color(vec2 const& uv) : r(uv.x), g(uv.y), b(0), a(1) {}
		color(vec3 const& rgb) : r(rgb.x), g(rgb.y), b(rgb.z), a(1) {}
		color(vec4 const& rgba) : r(rgba.x), g(rgba.y), b(rgba.z), a(rgba.w) {}
		color(double r, double g, double b, double a) : r(r), g(g), b(b), a(a) {}
		
		colorRGBint toRGBint() {
			return {r * 255 + ROUNDUP_EPSILON, g * 255 + ROUNDUP_EPSILON, b * 255 + ROUNDUP_EPSILON};
		}
		colorRGBAint toRGBAint() {
			return {r * 255 + ROUNDUP_EPSILON, g * 255 + ROUNDUP_EPSILON, b * 255 + ROUNDUP_EPSILON, a * 255 + ROUNDUP_EPSILON};
		}
		unsigned int toARGB(bool includeAlpha = true) {
			unsigned int alpha = (includeAlpha)?((unsigned int)(a * 255 + ROUNDUP_EPSILON) << 24) & 0xFF000000 : 0xFF000000;
			unsigned int red = ((unsigned int)(r * 255 + ROUNDUP_EPSILON) << 16) & 0x00FF0000;
			unsigned int green = ((unsigned int)(g * 255 + ROUNDUP_EPSILON) << 8) & 0x0000FF00;
			unsigned int blue = (unsigned int)(b * 255 + ROUNDUP_EPSILON) & 0x000000FF;
			return alpha | red | green | blue;
		}
		unsigned int toABGR(bool includeAlpha = true) {
			unsigned int alpha = (includeAlpha)?((unsigned int)(a * 255 + ROUNDUP_EPSILON) << 24) & 0xFF000000 : 0xFF000000;
			unsigned int blue = ((unsigned int)(b * 255 + ROUNDUP_EPSILON) << 16) & 0x00FF0000;
			unsigned int green = ((unsigned int)(g * 255 + ROUNDUP_EPSILON) << 8) & 0x0000FF00;
			unsigned int red = (unsigned int)(r * 255 + ROUNDUP_EPSILON) & 0x000000FF;
			return alpha | blue | green | red;
		}
	};
}

#endif