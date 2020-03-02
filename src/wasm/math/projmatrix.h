#include "types.h"

namespace engine
{
	class ProjMatrix {
	public:
		// fov helpers
		static float GetAspectRatio(vec2 FOV);
		static vec2 GetFOVCombo(float verticalFOV, float aspectRatio);
		static vec2 GetFOVCombo(float verticalFOV, vec2 screenSize);
		static vec2 GetFOVCombo(float verticalFOV);
		
		// basic projection matrices
		static mat4 GetPerspectiveMatrix(float verticalFOV, float aspectRatio, float near, float far);
		static mat4 GetOrthographicMatrix(float r, float l, float t, float b, float f, float n);
		
		// fov-based matrices
		static mat4 GetMatrix(float verticalFOV);
		static mat4 GetMatrix(float verticalFOV, float near, float far);
		static mat4 GetMatrix(vec2 FOV);
		static mat4 GetMatrix(vec2 FOV, bool isOrthographic, float orthographicDistance);
		static mat4 GetMatrix(vec2 FOV, bool isOrthographic, float orthographicDistance, float near, float far);
		static mat4 GetMatrix(vec2 FOV, float orthographicPercent, float orthographicDistance);
		static mat4 GetMatrix(vec2 FOV, float orthographicPercent, float orthographicDistance, float near, float far);
		
		// plane-based matrices
		static mat4 GetMatrix(float r, float l, float t, float b, float f, float n);
		static mat4 GetMatrix(Plane* planes);
		
		// get view-frustum planes
		static Plane* GetFrustum(mat4 matrix);
	};
}