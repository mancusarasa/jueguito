#include "../headers/Jueguito.h"


Jueguito::Jueguito() {
	
}

Jueguito::~Jueguito() {

}


void Jueguito::init() {
	
	// initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		setIsRunning(true);

		/**
		 * Crear métodos propioos para construir la ventana y el renderer
		 */
		
		// if succeeded create our window
		this->window = SDL_CreateWindow("Chapter 1:Setting up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		// if the window creation succeeded create our renderer
		if(this->window) {
			this->renderer = SDL_CreateRenderer(this->window, -1, 0);
			if (this->renderer) {
				//std::cout << "render init ok" << std::endl;
				// everything succeeded lets draw the window	
				// This function expects Red, Green, Blue and
				// Alpha as color values
				SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
			}	
		}
		
		//std::cout << "running true" << std::endl;
		
	
	}
	else {
		std::cout << "sdl could not initialize" << std::cout;
		setIsRunning(false); // sdl could not initialize
	}
}

void Jueguito::render() {
		// clear the window to black
	SDL_RenderClear(this->renderer);
	// show the window
	SDL_RenderPresent(this->renderer);


}

void Jueguito::update() {

}

void Jueguito::clean() {

}

void Jueguito::handleEvents() {
	
}

bool Jueguito::getIsRunning() {
	return this->isRunning;
}

void Jueguito::setIsRunning(bool estado) {
	this->isRunning = estado;
}