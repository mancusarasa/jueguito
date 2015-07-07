#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../headers/Jueguito.h"

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[]){
	
	Jueguito* jueguito = new Jueguito();
	jueguito->init();
	std::cout << jueguito->getIsRunning() << std::endl; 
	//Loop principal
	while( jueguito->getIsRunning() ) {
		jueguito->handleEvents();
		jueguito->update();
		jueguito->render();
		SDL_Delay(2000);
		jueguito->setIsRunning(false);
	}

	jueguito->clean();

	// set a delay before quitting
	// clean up SDL
	SDL_Quit();
	return 0;
}