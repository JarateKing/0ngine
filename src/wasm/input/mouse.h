#include "../javascript.h"

#include <algorithm>

namespace engine {
	class Mouse {
	public:
		Mouse();
		void update(float deltaTime);
		std::pair<int, int> position();
		
	private:
		std::pair<int, int> pos;
	};
}