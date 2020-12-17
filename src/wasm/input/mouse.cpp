#include "mouse.h"

engine::Mouse::Mouse() {
	pos = {0, 0};
}

void engine::Mouse::update(float delta) {
	pos = {js::getMouseX(), js::getMouseY()};
}

std::pair<int, int> engine::Mouse::position() {
	return pos;
}
