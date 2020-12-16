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
	js::changeTitle("0ngine");
	js::changeIcon("resource/icons/0ngine.ico");
	engine::ConsoleLog("Welcome to 0ngine!");
	
	emscripten_set_main_loop(gameloop, 999, 1);
}

void gameloop() {
	// fps portion
	fps->Update();
	
	// graphical portion
	js::clearDisplay();
	js::displayString(std::to_string(js::getScreenX()), "Arial", 12, fontColor, 5, 5);
	js::displayString(std::to_string(js::getScreenY()), "Arial", 12, fontColor, 5, 17);
	js::displayString(std::to_string(js::getAspectRatio()), "Arial", 12, fontColor, 5, 29);
	
	js::displayString(std::to_string(fps->GetDelta()), "Arial", 12, fontColor, 5, 50);
	js::displayString(std::to_string(fps->GetFramerate()), "Arial", 12, fontColor, 5, 62);
	
	js::displayString(js::getKeysPressed(), "Arial", 12, fontColor, 5, 80);
	js::displayString(std::to_string(js::getMouseX()) + ", " + std::to_string(js::getMouseY()), "Arial", 12, fontColor, 5, 92);
}
