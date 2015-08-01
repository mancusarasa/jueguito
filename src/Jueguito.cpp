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
		 
		// Obtengo los valores de configuración del Json
		int windowHeight = JsonReader::Instance()->getWindowValue("height");
		int windowWidth = JsonReader::Instance()->getWindowValue("width");

		int stageHeight = JsonReader::Instance()->getStageValue("height");
		int stageWidth = JsonReader::Instance()->getStageValue("width");
 		int stageX = JsonReader::Instance()->getStageValue("x");
		int stageY = JsonReader::Instance()->getStageValue("y");


		if (window.Create("Much window, wow",windowWidth,windowHeight)) {
			if (renderer.Create(window)){
				//std::cout << "render init ok" << std::endl;
				// everything succeeded lets draw the window	
				// This function expects Red, Green, Blue and
				// Alpha as color values
				//renderer.SetDrawColor(255, 255, 0, 0);


				//Fondo de ventana
				//Lo creé como Stage pero va a ser una clase aparte
				std::string imgPath("imgs/black.png");
				Stage* backgroundStage = new Stage(windowWidth, windowHeight, 0, 0, renderer.GetRenderer(), imgPath);
				textures.push_back(backgroundStage);	

				//Stage
				stage = new Stage(stageWidth, stageHeight, stageX, stageY, renderer.GetRenderer());
				textures.push_back(stage);

				Texture* brick = new Brick(renderer.GetRenderer());
				brick->setPosition(100,100);
				textures.push_back(brick);

				Ball* ball = new Ball(renderer.GetRenderer());
				ball->setPosition(stageWidth / 2, stageHeight / 2);
				textures.push_back(ball);


				Player* pallet = new Player(renderer.GetRenderer());
				InputHandler::Instance()->addPlayer(pallet);
				textures.push_back(pallet);
			
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
	for (int i = 0; i < textures.size(); i++){
		textures[i]->update();
	}
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