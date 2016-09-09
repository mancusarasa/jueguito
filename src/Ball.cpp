#include "../headers/Ball.h"
/* Notar que el eje x crece a la drecha y el eje y hacia abajo */
#define SPEEDY 0.05
#define SPEEDX 0.00
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

void Ball::bounceX() {
	this->speedX * (-1);
}

float Ball::getX() {
	return x;
}


float Ball::getY() {
	return y;
}


float Ball::getNextPositionX() {
	return this->x + speedX;
}

float Ball::getNextPositionY() {
	return this->y + speedY;
}

//Si speedX llega a ser 0 gritamos "PINCHÓ!"  y sacamos del medio
bool Ball::isGoingRight() {
	return getSpeedX() > 0;
}

//sí, me paso un poco por los huevos el caso speedy = 0
bool Ball::isGoingUp() {
	return getSpeedY() < 0; //recordar el eje Y está invertido
}

void Ball::update() {

	this->x += speedX;
	this->y += speedY;
	updatePosition(this->x,this->y);


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

//Devuelve la posición en X de la cara de la bola que haría contacto con una posible colisión
float Ball::getXContactPosition() {
	if (this->isGoingRight()) {
		return this->getX() + this->getWidth();
	} else {
		return this->getX();
	}
}

//Devuelve la posición en Y de la cara de la bola que haría contacto con una posible colisión
float Ball::getYContactPosition() {
	if (this->isGoingUp()) {
		return this->getY();
	} else {
		return this->getY() + this->getHeight();
	}
}