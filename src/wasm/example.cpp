#include "example.h"
#include "javascript.h"
#include "console/log.h"
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
	js::displayCopywrite();
}
