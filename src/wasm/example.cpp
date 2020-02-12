#include "javascript.h"
#include "console/log.h"

int main() {
	std::string title = "0ngine";
	js::changeTitle(title.c_str());
	
	ConsoleLog("Welcome to 0ngine!");
}
