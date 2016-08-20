#include "../headers/Ball.h"

#define SPEEDY 0.00
#define SPEEDX 0.06
#define RIGHTX 500
#define LEFTX 100
#define PI 3.14159265

Ball::Ball(SDL_Renderer* pRenderer):Drawable(BALL_IMG_PATH,pRenderer) {

	setSize(20,20);
	speedX = SPEEDX;
	speedY = SPEEDY;
	distanceX = 0;

}

Ball::~Ball() {

}

float Ball::getX() {
	return x;
}

void Ball::update() {
	std::cout << this->x << std::endl;
	this->x += speedX;
	this->x += speedY;
	updatePosition(this->x,200);
/*
	if ( x > RIGHTX) { //Borde derecho
	
		speedX *= -1;
		x = RIGHTX;
		initialX = x;
		distanceX = 0;
		
	} else if ( x < LEFTX) { //Borde izquierdo
	
		speedX *= -1;
		x = LEFTX	;
		initialX = x;
		distanceX = 0;
	
	}

	distanceX = abs(x - initialX);
*/
	///std::cout << x << "//" << initialX << distanceX << "-" << y << std::endl;
	
	/* Velocidad en X constante, el efecto tiene forma de parábola del tipo y = x^2
	 * Como la parábola es muy abrupta (aumenta demasiado en Y), se le agrega un multiplicador que va a servir para que el efecto tarde más en escalar. 
	 * Idem para la elección de la potencia, por ahora fueron calculados a ojo	 */
/*	
	float effectDelay = 50000;
	x += speedX;
	float xRoot = pow(distanceX, 1.5);
	float xSqrt = sqrt(distanceX);
	y += xRoot / effectDelay;
*/
	//updatePosition(x,y);
}

