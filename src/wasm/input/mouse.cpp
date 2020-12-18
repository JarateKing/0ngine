#include "mouse.h"
#include "keys.h"

engine::Mouse::Mouse() {
	pos = {0, 0};
	buttons = 0;
}

void engine::Mouse::update(float delta) {
	pos = {js::getMouseX(), js::getMouseY()};
	buttons = js::getMouseKeysPressed();
}

std::pair<int, int> engine::Mouse::position() {
	return pos;
}

bool engine::Mouse::isLMB() {
	return buttons & MOUSE_LMB;
}

bool engine::Mouse::isRMB() {
	return buttons & MOUSE_RMB;
}

bool engine::Mouse::isMMB() {
	return buttons & MOUSE_MMB;
}

bool engine::Mouse::isBackButton() {
	return buttons & MOUSE_BACK;
}

bool engine::Mouse::isForwardButton() {
	return buttons & MOUSE_FORWARD;
}
