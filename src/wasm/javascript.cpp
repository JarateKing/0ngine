#include "javascript.h"

void js::changeIcon(std::string iconSrc) {
	changeIcon(iconSrc.c_str());
}
void js::changeUrl(std::string state, const char* urlSuffix) {
	changeUrl(state.c_str(), urlSuffix);
}
void js::changeUrl(const char* state, std::string urlSuffix) {
	changeUrl(state, urlSuffix.c_str());
}
void js::changeUrl(std::string state, std::string urlSuffix) {
	changeUrl(state.c_str(), urlSuffix.c_str());
}
void js::changeTitle(std::string title) {
	changeTitle(title.c_str());
}
void js::openUrl(std::string url, bool isNewTab) {
	openUrl(url.c_str(), isNewTab);
}
void js::displayString(std::string text, const char* font, int fontSize, const char* color, int xpos, int ypos) {
	displayString(text.c_str(), font, fontSize, color, xpos, ypos);
}
void js::displayString(const char* text, std::string font, int fontSize, const char* color, int xpos, int ypos) {
	displayString(text, font.c_str(), fontSize, color, xpos, ypos);
}
void js::displayString(std::string text, std::string font, int fontSize, const char* color, int xpos, int ypos) {
	displayString(text.c_str(), font.c_str(), fontSize, color, xpos, ypos);
}
void js::displayString(const char* text, const char* font, int fontSize, std::string color, int xpos, int ypos) {
	displayString(text, font, fontSize, color.c_str(), xpos, ypos);
}
void js::displayString(std::string text, const char* font, int fontSize, std::string color, int xpos, int ypos) {
	displayString(text.c_str(), font, fontSize, color.c_str(), xpos, ypos);
}
void js::displayString(const char* text, std::string font, int fontSize, std::string color, int xpos, int ypos) {
	displayString(text, font.c_str(), fontSize, color.c_str(), xpos, ypos);
}
void js::displayString(std::string text, std::string font, int fontSize, std::string color, int xpos, int ypos) {
	displayString(text.c_str(), font.c_str(), fontSize, color.c_str(), xpos, ypos);
}
void js::displayString(std::string text, const char* font, int fontSize, engine::color color, int xpos, int ypos) {
	displayString(text.c_str(), font, fontSize, color.toHex().c_str(), xpos, ypos);
}
void js::displayString(const char* text, std::string font, int fontSize, engine::color color, int xpos, int ypos) {
	displayString(text, font.c_str(), fontSize, color.toHex().c_str(), xpos, ypos);
}
void js::displayString(std::string text, std::string font, int fontSize, engine::color color, int xpos, int ypos) {
	displayString(text.c_str(), font.c_str(), fontSize, color.toHex().c_str(), xpos, ypos);
}
void js::displayString(const char* text, const char* font, int fontSize, engine::color color, int xpos, int ypos) {
	displayString(text, font, fontSize, color.toHex().c_str(), xpos, ypos);
}
void js::localdataSave(std::string id, const char* text) {
	localdataSave(id.c_str(), text);
}
void js::localdataSave(const char* id, std::string text) {
	localdataSave(id, text.c_str());
}
void js::localdataSave(std::string id, std::string text) {
	localdataSave(id.c_str(), text.c_str());
}
void js::localdataRemove(std::string id) {
	localdataRemove(id.c_str());
}
char* js::localdataGet(std::string id) {
	return localdataGet(id.c_str());
}
