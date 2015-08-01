#include "../headers/Ball.h"

Ball::Ball(SDL_Renderer* pRenderer):Texture(BALL_IMG_PATH,pRenderer) {
	setSize(20,20);
	speedX = 0.01;
	speedY = 0;
}

Ball::~Ball() {

}

void Ball::update() {
	if ( x >= 600 || x <= 0) x *= -1;
	x += speedX;
	y += speedY;
	updatePosition(x,y);
}

