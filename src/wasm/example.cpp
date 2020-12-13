#include "example.h"
#include "javascript.h"
#include "console/log.h"
#include "math/basic.h"
#include "math/types.h"
#include "math/rng.h"
#include "fps/fps_counter.h"
#include <emscripten.h>

static engine::FPS* fps = new engine::FPS();
static engine::color fontColor(0.8, 0.85, 1.0, 1.0);

int main() {
	std::string title = "0ngine";
	js::changeTitle(title.c_str());
	
	std::string icon = "resource/icons/0ngine.ico";
	js::changeIcon(icon.c_str());
	
	engine::ConsoleLog("Welcome to 0ngine!");
	
	emscripten_set_main_loop(gameloop, 999, 1);
}

void gameloop() {
	// fps portion
	fps->Update();
	
	// graphical portion
	js::clearDisplay();
	js::displayString(std::to_string(js::getScreenX()).c_str(), "Arial", 12, fontColor.toHex().c_str(), 5, 5);
	js::displayString(std::to_string(js::getScreenY()).c_str(), "Arial", 12, fontColor.toHex().c_str(), 5, 17);
	js::displayString(std::to_string(js::getAspectRatio()).c_str(), "Arial", 12, fontColor.toHex().c_str(), 5, 29);
	
	js::displayString(std::to_string(fps->GetDelta()).c_str(), "Arial", 12, fontColor.toHex().c_str(), 5, 50);
	js::displayString(std::to_string(fps->GetFramerate()).c_str(), "Arial", 12, fontColor.toHex().c_str(), 5, 62);
	
	js::displayString(js::getKeysPressed(), "Arial", 12, fontColor.toHex().c_str(), 5, 80);
}
