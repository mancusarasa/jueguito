#include "../headers/Ball.h"

#define SPEEDY 0.01
#define SPEEDX 0.01
#define RIGHTX 500
#define LEFTX 100

Ball::Ball(SDL_Renderer* pRenderer):Texture(BALL_IMG_PATH,pRenderer) {
	setSize(20,20);
	speedX = SPEEDX;
	speedY = SPEEDY;
	initialX = 300;
}

Ball::~Ball() {

}

void Ball::update() {

	if ( x > RIGHTX) { //Borde derecho
	
		speedX *= -1;
		x = RIGHTX;
		initialX = x;
	
	} else if ( x < LEFTX) { //Borde izquierdo
	
		speedX *= -1;
		x = LEFTX	;
		initialX = x;
	
	}

	speedX += 0.001;
	speedY *= 1.001;

	
	x += speedX;
	y += speedY;

	updatePosition(x,y);
}

