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
		int windowHeight = JsonReader::Instance()->getWindowValue("height");
		int windowWidth = JsonReader::Instance()->getWindowValue("width");

		if (window.Create("Much window, wow",windowWidth,windowHeight)) {
			if (renderer.Create(window)){
				//std::cout << "render init ok" << std::endl;
				// everything succeeded lets draw the window	
				// This function expects Red, Green, Blue and
				// Alpha as color values
				renderer.SetDrawColor(255, 255, 0, 0);
				Player* pallet = new Player(renderer.GetRenderer());
				InputHandler::Instance()->addPlayer(pallet);
				textures.push_back(pallet);
			
				Texture* brick = new Brick(renderer.GetRenderer());
				brick->setPosition(100,100);
				textures.push_back(brick);
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
		//std::cout << textures[i] << std::endl;
		renderer.RenderTexture(textures[i]);
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
			case SDL_KEYDOWN:{
				InputHandler::Instance()->onKeyDown(event.key.keysym.sym);
				break;
				/*
				for (int i = 0; i < textures.size(); i++){
					if(event.key.keysym.sym == SDLK_UP)
						textures[i]->MoveDown();
					else
						textures[i]->MoveUp();
				}*/
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