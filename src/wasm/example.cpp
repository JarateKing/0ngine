#include "javascript.h"
#include "console/log.h"

int main() {
	std::string title = "0ngine";
	js::changeTitle(title.c_str());
	
	std::string icon = "resource/icons/0ngine.ico";
	js::changeIcon(icon.c_str());
	
	engine::ConsoleLog("Welcome to 0ngine!");
}
