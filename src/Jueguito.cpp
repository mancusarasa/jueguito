#include "../headers/Jueguito.h"

Jueguito::Jueguito():isRunning(false){}

Jueguito::~Jueguito() {
	/*for (int i = 0; i < drawables.size(); i++){
		delete drawables[i];
	}*/
	delete layoutManager;
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

		// Habría que validar que el tamaño del stage no supere al de la ventana
		int stageHeight = JsonReader::Instance()->getStageValue("height");
		int stageWidth = JsonReader::Instance()->getStageValue("width");

		//Posicion del stage dentro de la ventana
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
				//std::string imgPath("imgs/black.png");
				//Stage* backgroundStage = new Stage(windowWidth, windowHeight, 0, 0, renderer.GetRenderer());
				//drawables.push_back(backgroundStage);	

				//Stage
				Stage* stage = new Stage(stageWidth, stageHeight, stageX, stageY, renderer.GetRenderer());
				//stage->setPosition(0,0);

				this->layoutManager = new LayoutManager();
				layoutManager->setStagePosition( stage->getX(), stage->getY() );
				layoutManager->addDrawable(stage);

				/*Brick* brick = new Brick(renderer.GetRenderer());
				brick->setPosition(100,100);
				layoutManager->addDrawable(brick);
*/
				Player* pallet = new Player(renderer.GetRenderer());
				pallet->setPosition(50,100);
				InputHandler::Instance()->addPlayer(pallet);
				layoutManager->addDrawable(pallet);

				Player* pallet2 = new Player(renderer.GetRenderer());
				pallet2->setPosition(400,100);
				layoutManager->addDrawable(pallet2);


				Ball* ball = new Ball(renderer.GetRenderer());
				float floatX = 120;
				float floatY = 200;
				ball->setPosition(floatX, floatY);
				layoutManager->addDrawable(ball);
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
	layoutManager->drawObjects(&renderer);
/*
	// clear the window to black
	renderer.Clear();
	// mostrar las texturas
	
	for (int i = 0; i < drawables.size(); i++){
		//std::cout << textures[i] << std::endl;
		renderer.RenderTexture(drawables[i]->getTexture());
	}
	// show the window
	renderer.Present();
*/
}

void Jueguito::update() {
	for (int i = 0; i < layoutManager->drawables.size(); i++){
		layoutManager->drawables[i]->update();
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