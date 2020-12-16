#ifndef JAVASCRIPT_LIBRARY_FUNCTIONS
#define JAVASCRIPT_LIBRARY_FUNCTIONS

#include <string>
#include "math/types.h"

namespace js {
	extern "C" {
		extern void changeIcon(const char* iconSrc);
		extern void changeUrl(const char* state, const char* urlSuffix);
		extern void changeTitle(const char* title);
		extern void openUrl(const char* url, bool isNewTab);
		extern void displayString(const char* text, const char* font, int fontSize, const char* color, int xpos, int ypos);
		extern void clearDisplay();
		extern int getScreenX();
		extern int getScreenY();
		extern float getAspectRatio();
		extern void localdataSave(const char* id, const char* text);
		extern void localdataRemove(const char* id);
		extern void localdataClear();
		extern char* localdataGet(const char* id);
		extern char* getKeysPressed();
		extern int getMouseX();
		extern int getMouseY();
		extern int getMouseKeysPressed();
		extern float getMouseScrollX();
		extern float getMouseScrollY();
		extern float getMouseScrollZ();
		extern void resetMouseScroll();
	}
	
	// wrappers
	void changeIcon(std::string iconSrc);
	void changeUrl(std::string state, const char* urlSuffix);
	void changeUrl(const char* state, std::string urlSuffix);
	void changeUrl(std::string state, std::string urlSuffix);
	void changeTitle(std::string title);
	void openUrl(std::string url, bool isNewTab);
	void displayString(std::string text, const char* font, int fontSize, const char* color, int xpos, int ypos);
	void displayString(const char* text, std::string font, int fontSize, const char* color, int xpos, int ypos);
	void displayString(std::string text, std::string font, int fontSize, const char* color, int xpos, int ypos);
	void displayString(const char* text, const char* font, int fontSize, std::string color, int xpos, int ypos);
	void displayString(std::string text, const char* font, int fontSize, std::string color, int xpos, int ypos);
	void displayString(const char* text, std::string font, int fontSize, std::string color, int xpos, int ypos);
	void displayString(std::string text, std::string font, int fontSize, std::string color, int xpos, int ypos);
	void displayString(std::string text, const char* font, int fontSize, engine::color color, int xpos, int ypos);
	void displayString(const char* text, std::string font, int fontSize, engine::color color, int xpos, int ypos);
	void displayString(std::string text, std::string font, int fontSize, engine::color color, int xpos, int ypos);
	void displayString(const char* text, const char* font, int fontSize, engine::color color, int xpos, int ypos);
	void localdataSave(std::string id, const char* text);
	void localdataSave(const char* id, std::string text);
	void localdataSave(std::string id, std::string text);
	void localdataRemove(std::string id);
	char* localdataGet(std::string id);
}

#endif
