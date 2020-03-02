#include "projmatrix.h"
#include "../javascript.h"
#include <cmath>

namespace engine
{
	float ProjMatrix::GetAspectRatio(vec2 FOV) {
		return std::tan(DEG2RAD * FOV.y / 2) * std::tan(DEG2RAD * FOV.x / 2);
	}
	
	vec2 ProjMatrix::GetFOVCombo(float verticalFOV, float aspectRatio) {
		float horizontalFOV = RAD2DEG * 2 * std::atan(std::tan(verticalFOV * DEG2RAD / 2) * aspectRatio);
		return vec2(verticalFOV, horizontalFOV);
	}
	
	vec2 ProjMatrix::GetFOVCombo(float verticalFOV, vec2 screenSize) {
		float aspectRatio = screenSize.x / screenSize.y;
		return GetFOVCombo(verticalFOV, aspectRatio);
	}
	
	vec2 ProjMatrix::GetFOVCombo(float verticalFOV) {
		return GetFOVCombo(verticalFOV, js::getAspectRatio());
	}
	
	mat4 ProjMatrix::GetPerspectiveMatrix(float verticalFOV, float aspectRatio, float near, float far) {
		// @TODO: implement this
		return mat4();
	}
	
	mat4 ProjMatrix::GetOrthographicMatrix(float r, float l, float t, float b, float f, float n) {
		// @TODO: implement this
		return mat4();
	}
	
	mat4 ProjMatrix::GetMatrix(float verticalFOV) {
		// @TODO: implement this
		return mat4();
	}
	
	mat4 ProjMatrix::GetMatrix(float verticalFOV, float near, float far) {
		// @TODO: implement this
		return mat4();
	}
	
	mat4 ProjMatrix::GetMatrix(vec2 FOV) {
		// @TODO: implement this
		return mat4();
	}
	
	mat4 ProjMatrix::GetMatrix(vec2 FOV, bool isOrthographic, float orthographicDistance) {
		// @TODO: implement this
		return mat4();
	}
	
	mat4 ProjMatrix::GetMatrix(vec2 FOV, bool isOrthographic, float orthographicDistance, float near, float far) {
		// @TODO: implement this
		return mat4();
	}
	
	mat4 ProjMatrix::GetMatrix(vec2 FOV, float orthographicPercent, float orthographicDistance) {
		// @TODO: implement this
		return mat4();
	}
	
	mat4 ProjMatrix::GetMatrix(vec2 FOV, float orthographicPercent, float orthographicDistance, float near, float far) {
		// @TODO: implement this
		return mat4();
	}
	
	mat4 ProjMatrix::GetMatrix(float r, float l, float t, float b, float f, float n) {
		mat4 proj;
		
		proj[0][0] = 2 * n / (r - l);
		proj[1][1] = 2 * n / (t - b);
		proj[2][0] = (r + l) / (r - l);
		proj[2][1] = (t + b) / (t - b);
		proj[2][2] = -(f + n) / (f - n);
		proj[2][3] = -1;
		proj[3][2] = -2 * f * n / (f - n);
		proj[3][3] = 0;
		
		return proj;
	}
	
	mat4 ProjMatrix::GetMatrix(Plane* planes) {
		// @TODO:
		// - support near and far values from planes
		// - support orthographic and partially-orthographic frustums
		
		float f = planes[4].d;
		float n = planes[5].d;
		float r = (planes[0].c * n) / planes[0].a;
		float l = (planes[1].c * n) / planes[1].a;
		float t = (planes[2].c * n) / planes[2].b;
		float b = (planes[3].c * n) / planes[3].b;
		
		return GetMatrix(r, l, t, b, f, n);
	}
	
	Plane* ProjMatrix::GetFrustum(mat4 matrix) {
		Plane* toret = new Plane[6];
		
		// condensed hartmann-gribbs
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 4; j++)
				toret[i][j] = matrix[j][3] + (i % 2 * 2 - 1) * matrix[j][i / 2];
		
		return toret;
	}
}