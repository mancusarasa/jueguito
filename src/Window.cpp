#include "../headers/Window.h"


/* Constructor por defecto. */
Window::Window():pWindow(NULL){

}

/* Este metodo podria borrarse y pasar todo su codigo al constructor de Window. Ver después.
 * @return: true si salió todo bien (que debería ser siempre)
 */
bool Window::Create(const char* title, int width, int height){
	/* Clavo este assert acá para evitar crear la ventana dos veces. */
	assert(!pWindow);
	pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	this->width = width;
	this->height = height;
	return true;
}

/* Destructor */
Window::~Window(){
	if(pWindow)
		SDL_DestroyWindow(pWindow);
}