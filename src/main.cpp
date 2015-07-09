#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../headers/Jueguito.h"

int main(int argc, char* args[]){

	Jueguito jueguito;
	jueguito.init();
	//std::cout << jueguito.IsRunning() << std::endl; 
	//Loop principal
	while( jueguito.IsRunning() ) {
		jueguito.handleEvents();
		jueguito.update();
		jueguito.render();
	}

	jueguito.clean();
	return 0;
}