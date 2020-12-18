#include "example.h"
#include "javascript.h"
#include "console/log.h"
#include "math/basic.h"
#include "math/types.h"
#include "math/rng.h"
#include "fps/fps_counter.h"
#include "input/mouse.h"
#include <emscripten.h>

static engine::FPS* fps = new engine::FPS();
static engine::color fontColor(0.8, 0.85, 1.0, 1.0);
static engine::Mouse* mouse = new engine::Mouse();
static double scrollSum = 0.0;

int main() {
	js::changeTitle("0ngine");
	js::changeIcon("resource/icons/0ngine.ico");
	engine::ConsoleLog("Welcome to 0ngine!");
	
	emscripten_set_main_loop(gameloop, 999, 1);
}

void gameloop() {
	// fps portion
	fps->Update();
	float delta = fps->GetDelta();
	
	mouse->update(delta);
	
	scrollSum += js::getMouseScrollY();
	
	// graphical portion
	js::clearDisplay();
	js::displayString(std::to_string(js::getScreenX()), "Arial", 12, fontColor, 5, 5);
	js::displayString(std::to_string(js::getScreenY()), "Arial", 12, fontColor, 5, 17);
	js::displayString(std::to_string(js::getAspectRatio()), "Arial", 12, fontColor, 5, 29);
	
	js::displayString(std::to_string(fps->GetDelta()), "Arial", 12, fontColor, 5, 50);
	js::displayString(std::to_string(fps->GetFramerate()), "Arial", 12, fontColor, 5, 62);
	
	js::displayString(js::getKeysPressed(), "Arial", 12, fontColor, 5, 80);
	js::displayString(std::to_string(mouse->position().first) + ", " + std::to_string(mouse->position().second), "Arial", 12, fontColor, 5, 92);
	js::displayString(std::to_string(mouse->isLMB()) + ", " + std::to_string(mouse->isRMB()) + ", " + std::to_string(mouse->isMMB()) + ", " + std::to_string(mouse->isBackButton()) + ", " + std::to_string(mouse->isForwardButton()), "Arial", 12, fontColor, 5, 104);
	js::displayString(std::to_string(js::getMouseScrollX()) + ", " + std::to_string(js::getMouseScrollY()) + ", " + std::to_string(js::getMouseScrollZ()) + " = " + std::to_string(scrollSum), "Arial", 12, fontColor, 5, 116);
	
	js::resetMouseScroll();
}
