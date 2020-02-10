namespace js {
	extern "C" {
		extern void changeIcon(const char* iconSrc);
		extern void changeUrl(const char* state, const char* urlSuffix);
		extern void changeTitle(const char* title);
	}
}