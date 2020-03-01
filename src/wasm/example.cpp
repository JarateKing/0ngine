#include "example.h"
#include "javascript.h"
#include "console/log.h"
#include "math/basic.h"
#include "math/types.h"
#include "math/rng.h"
#include <emscripten.h>

int main() {
	std::string title = "0ngine";
	js::changeTitle(title.c_str());
	
	std::string icon = "resource/icons/0ngine.ico";
	js::changeIcon(icon.c_str());
	
	engine::ConsoleLog("Welcome to 0ngine!");
	
	emscripten_set_main_loop(gameloop, 999, 1);
}

void gameloop() {
	js::clearDisplay();
	js::displayString(std::to_string(js::getScreenX()).c_str(), "Arial", 12, "grey", 5, 5);
	js::displayString(std::to_string(js::getScreenY()).c_str(), "Arial", 12, "grey", 5, 17);
	js::displayString(std::to_string(js::getAspectRatio()).c_str(), "Arial", 12, "grey", 5, 29);
}
