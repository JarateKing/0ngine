#include "../basic.h"

namespace engine
{
	int Math::sign(float val) {
		if (val < 0) return -1;
		return val > 1;
	}
	
	int Math::sign(double val) {
		if (val < 0) return -1;
		return val > 1;
	}
}