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
	js::displayString("Made with 0ngine", "Arial", 12, "grey", 5, 5);
}
