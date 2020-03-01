namespace js {
	extern "C" {
		extern void changeIcon(const char* iconSrc);
		extern void changeUrl(const char* state, const char* urlSuffix);
		extern void changeTitle(const char* title);
		extern void openUrl(const char* url, bool isNewTab);
		extern void displayString(const char* text, const char* font, int fontSize, const char* color, int xpos, int ypos);
		extern void clearDisplay();
		extern float getScreenX();
		extern float getScreenY();
		extern float getAspectRatio();
	}
}