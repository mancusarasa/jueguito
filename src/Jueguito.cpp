#include "../headers/Jueguito.h"

Jueguito::Jueguito():isRunning(false){}

Jueguito::~Jueguito() {
	for (int i = 0; i < textures.size(); i++){
		delete textures[i];
	}
}

void Jueguito::init() {
	
	// initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		setIsRunning(true);
		// if succeeded create our window	 
		// if the window creation succeeded create our renderer
		if (window.Create("Much window, wow",640,480)) {
			if (renderer.Create(window)){
				//std::cout << "render init ok" << std::endl;
				// everything succeeded lets draw the window	
				// This function expects Red, Green, Blue and
				// Alpha as color values
				renderer.SetDrawColor(255, 255, 0, 0);
				Texture* doge = renderer.CreateTexture("./imgs/doge.bmp");
				textures.push_back(doge);
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
	// mostrar las texturas
	for (int i = 0; i < textures.size(); i++){
		renderer.ShowTexture(textures[i]);
	}
	// show the window
	renderer.Present();
}

void Jueguito::update() {

}

void Jueguito::clean() {
	SDL_Delay(250);
	SDL_Quit();	
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
