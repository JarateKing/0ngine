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
		bool isMwheeldown();
		bool isMwheelup();
		int scroll();
		
	private:
		std::pair<int, int> pos;
		int buttons;
		float verticalScroll;
	};
}