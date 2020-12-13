#include "javascript.h"

void js::displayString(const char* text, const char* font, int fontSize, std::string color, int xpos, int ypos) {
	displayString(text, font, fontSize, color.c_str(), xpos, ypos);
}
void js::displayString(std::string text, const char* font, int fontSize, std::string color, int xpos, int ypos) {
	displayString(text.c_str(), font, fontSize, color.c_str(), xpos, ypos);
}
void js::displayString(std::string text, std::string font, int fontSize, std::string color, int xpos, int ypos) {
	displayString(text.c_str(), font.c_str(), fontSize, color.c_str(), xpos, ypos);
}