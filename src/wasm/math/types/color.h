#ifndef MATH_TYPES_COLOR_H
#define MATH_TYPES_COLOR_H

#include "../types.h"
#include <iomanip>
#include <sstream>

#define ROUNDUP_EPSILON 0.5

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
		color(float v) : r(v), g(v), b(v), a(1) {}
		color(vec2 const& uv) : r(uv.x), g(uv.y), b(0), a(1) {}
		color(vec3 const& rgb) : r(rgb.x), g(rgb.y), b(rgb.z), a(1) {}
		color(vec4 const& rgba) : r(rgba.x), g(rgba.y), b(rgba.z), a(rgba.w) {}
		color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
		
		colorRGBint toRGBint() {
			return {static_cast<int>(r * 255 + ROUNDUP_EPSILON), static_cast<int>(g * 255 + ROUNDUP_EPSILON), static_cast<int>(b * 255 + ROUNDUP_EPSILON)};
		}
		
		colorRGBAint toRGBAint() {
			return {static_cast<int>(r * 255 + ROUNDUP_EPSILON), static_cast<int>(g * 255 + ROUNDUP_EPSILON), static_cast<int>(b * 255 + ROUNDUP_EPSILON), static_cast<int>(a * 255 + ROUNDUP_EPSILON)};
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
		
		std::string toHex(bool includeAlpha = false) {
			std::stringstream str;
			str << '#' << std::setfill('0') << std::setw(2) << std::hex << (int)(r * 255 + ROUNDUP_EPSILON);
			str << std::setfill('0') << std::setw(2) << std::hex << (int)(g * 255 + ROUNDUP_EPSILON);
			str << std::setfill('0') << std::setw(2) << std::hex << (int)(b * 255 + ROUNDUP_EPSILON);
			if (includeAlpha)
			str << std::setfill('0') << std::setw(2) << std::hex << (int)(a * 255 + ROUNDUP_EPSILON);
			return str.str();
		}
	};
	
	// @TODO:
	// - convert between formats
}

#endif