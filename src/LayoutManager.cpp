#include "../headers/LayoutManager.h"

LayoutManager::LayoutManager() {

}

LayoutManager::~LayoutManager() { 
	for (int i = 0; i < drawables.size(); i++) {
		delete drawables[i];
	}
}

void LayoutManager::addDrawable(Drawable* drawable) {
	drawables.push_back(drawable);
}

void LayoutManager::setStagePosition(int x, int y) {
	stageX = x;
	stageY = y;
}

void LayoutManager::drawObjects(Renderer* renderer) {

	// clear the window to black
	renderer->Clear();
	// mostrar las texturas
	for (int i = 0; i < drawables.size(); i++){
		//std::cout << textures[i] << std::endl;
		renderer->RenderTexture(drawables[i]->getTexture());
	}
	// show the window
	renderer->Present();

}