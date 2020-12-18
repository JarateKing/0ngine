#include "../javascript.h"

#include <algorithm>

namespace engine {
	class Mouse {
	public:
		Mouse();
		void update(float deltaTime);
		std::pair<int, int> position();
		bool isLMB();
		bool isRMB();
		bool isMMB();
		bool isBackButton();
		bool isForwardButton();
		
	private:
		std::pair<int, int> pos;
		int buttons;
	};
}