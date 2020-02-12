#include <iostream>
#include "log.h"

namespace engine
{
	void ConsoleLog(std::string line) {
		std::cout << line << '\n';
	}
	
	void ConsoleLog(int value) {
		std::cout << value << '\n';
	}
	
	void ConsoleLog(long value) {
		std::cout << value << '\n';
	}
	
	void ConsoleLog(float value) {
		std::cout << value << '\n';
	}
	
	void ConsoleLog(double value) {
		std::cout << value << '\n';
	}
}
