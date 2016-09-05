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

void LayoutManager::addCollitionable(Drawable* drawable) {
	collitionables.push_back(drawable);
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

void LayoutManager::addBouncer(Ball* ball) {
	bouncers.push_back(ball);
}


// Gestiona la posibilidad de que la bola choque con algún obstáculo
void LayoutManager::manageBouncerUpdate(Ball* ball) {
	Drawable* obstacle = findCollitions(ball);
	if (obstacle != NULL) {
		solveCollition(ball, obstacle);
	}
}

/* Compara el bouncer contra todos los drawables en busca de colisiones */
Drawable* LayoutManager::findCollitions(Ball* ball) {
	for (int i = 0; i < this->collitionables.size(); i++){

		Drawable* potentialObstacle = this->collitionables[i];
		if ( willCollide(ball, potentialObstacle) ) {
			std::cout << "collition" << std::endl; 
			return potentialObstacle;
		}
	}
	return NULL;
}

/* Resuelve la colisión 
 * En principio sería detectar en qué eje es la colisión (pared lateral, inferior o superior)
 * e invertir la velocidad en esa dirección
 */
void LayoutManager::solveCollition(Ball* ball, Drawable* obstacle) {
	//Congelo la bola en la posición actual
	ball->setSpeedX( ball->getSpeedX() * -1);
	ball->setSpeedY(0);
}


/* Evalúa si la bola en la proxima posicion va a chocar el potencial obstáculo */
bool LayoutManager::willCollide(Ball* ball, Drawable* potentialObstacle) {
	//float nextBouncerPositionX = ball->getNextPositionX();
	//float nextBouncerPositionY = ball->getNextPositionY();

	// Agarro todas las posiciones que necesito
	float ballRightX = ball->getNextPositionX() + ball->getWidth();
	float ballLeftX = ball->getNextPositionX();

	float ballTopY = ball->getNextPositionY();
	float ballBottomY = ball->getNextPositionY() + ball->getHeight();

	float obstacleLeftX = potentialObstacle->getX();
	float obstacleRightX = potentialObstacle->getX() + potentialObstacle->getWidth();

	float obstacleTopY = potentialObstacle->getY();
	float obstacleBottomY = potentialObstacle->getY() + potentialObstacle->getHeight();

	if (ball->isGoingRight()) {
	
		//Condicion básica de rebote en X
		if ( ballRightX >= obstacleLeftX 
				&& ballRightX <= obstacleLeftX + ball->getWidth() / 2) {

			//std::cout << "Posible Colisión en eje X" << std::endl;

			//Condición básica de pos Y para colisionar UNICAMENTE sobre el eje X
			if (ballTopY + ball->getHeight() / 2 > obstacleTopY && ballBottomY - ball->getHeight() / 2 < obstacleBottomY) {
				std::cout << "horizontal" << std::endl;
				return true;
			}

			//Condicion para que rebote en X sobre las esquinas
			if(  ballBottomY >= obstacleTopY && ballTopY <= obstacleBottomY) {
				std::cout << "diagonal" << std::endl;
				return true; 
			}
		
		} 

	} else {

		//Condicion básica de rebote en X

		if ( ballLeftX <= obstacleRightX 
				&& ballLeftX >= obstacleRightX - ball->getWidth() / 2) {

			//Esto se mantiene igual

			//Condición básica de pos Y para colisionar UNICAMENTE sobre el eje X
			if (ballTopY + ball->getHeight() / 2 > obstacleTopY && ballBottomY - ball->getHeight() / 2 < obstacleBottomY) {
				std::cout << "horizontal" << std::endl;
				return true;
			}

			//Condicion para que rebote en X sobre las esquinas
			if(  ballBottomY >= obstacleTopY && ballTopY <= obstacleBottomY) {
				std::cout << "diagonal" << std::endl;
				return true; 
			}
		
		} 

	}

	if (ball->isGoingUp()) {

	} else {

	}

	return false;
	
}

//Dado un drawable y un offset (ancho de la imagen) según corresponda, devuelve la posición en x de la
//cara del objeto que puede estar colisionando.
/*
float LayoutManager::getXImpactSurfacePosition(Drawable* drawable, int offset) {
	return drawable->getX() + offset;
}

float LayoutManager::getYImpactSurfacePosition(Drawable* drawable, int offset) {
	return drawable->getY() + offset;  
}*/