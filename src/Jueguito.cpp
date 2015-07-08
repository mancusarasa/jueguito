#include "../headers/Jueguito.h"

Jueguito::Jueguito():isRunning(false){}

Jueguito::~Jueguito() {

}


void Jueguito::init() {
	
	// initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		setIsRunning(true);
		/**
		 * Crear métodos propios para construir la ventana y el renderer
		 */
		
		// if succeeded create our window	 
		// if the window creation succeeded create our renderer
		if(window.Create("Chapter 1:Doge",640,480)) {
			if (renderer.Create(window)){
				//std::cout << "render init ok" << std::endl;
				// everything succeeded lets draw the window	
				// This function expects Red, Green, Blue and
				// Alpha as color values
				renderer.SetDrawColor(255, 0, 0, 255);
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
	renderer.Clear();
	// show the window
	renderer.Present();
}

void Jueguito::update() {

}

void Jueguito::clean() {

}

void Jueguito::handleEvents() {
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:{
				setIsRunning(false);
				break;
			}
			default:{
				/* Evento sin handler */
				break;
			}
		}
	}
}

bool Jueguito::IsRunning() {
	return this->isRunning;
}

void Jueguito::setIsRunning(bool estado) {
	this->isRunning = estado;
}