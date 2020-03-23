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
	}
}
