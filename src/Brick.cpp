#include "../headers/Brick.h"

Brick::Brick(SDL_Renderer* pRenderer):Drawable(BRICK_BMP_PATH, pRenderer) {
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