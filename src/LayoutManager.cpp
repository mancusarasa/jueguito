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

	for (int i = 0; i < this->drawables.size(); i++){

		Drawable* potentialObstacle = this->drawables[i];

		if ( willCollide(ball, potentialObstacle) ) {
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

}


/* Evalúa si la bola en la proxima posicion va a chocar el potencial obstáculo */
bool LayoutManager::willCollide(Ball* ball, Drawable* potentialObstacle) {
	float nextBouncerPositionX = ball->getNextPositionX();
	float nextBouncerPositionY = ball->getNextPositionY();
}