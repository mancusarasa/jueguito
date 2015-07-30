#include "../headers/Brick.h"

Brick::Brick(SDL_Renderer* pRenderer, int offsetX, int offsetY):Texture(BRICK_BMP_PATH, pRenderer, offsetX, offsetY) {
}

Brick::~Brick() {
}

/*
void Brick::draw() {
	//SDL_RenderCopy(pRenderer_, GetTexture(), &bmpRectangle, &rendererRectangle);
}*/

void Brick::moveDown() {
}

void Brick::moveUp() {
}