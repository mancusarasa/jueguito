#include "../headers/Stage.h"

Stage::Stage( int width, int height, int x , int y, SDL_Renderer* pRenderer) : Drawable(STAGE_IMG_PATH, pRenderer) {
	this->setPosition(x,y);
	this->height = height;
	this->width = width;
	this->setSize(width, height);
	
}

Stage::~Stage() {

}

void Stage::draw() {
/*	
	this->texture::draw();

	//Render green outlined quad 
	SDL_Rect outlineRect = { 50,  50, width, height }; 
	SDL_SetRenderDrawColor( pRenderer_, 0x00, 0xFF, 0x00, 0xFF ); 
	SDL_RenderDrawRect( pRenderer_, &outlineRect );
	//int a = SDL_RenderDrawRect( pRenderer_, &rendererRectangle );
*/	
}

 