#ifndef __WINDOW__
#define __WINDOW__

#include <SDL2/SDL.h>
#include <string>
#include <assert.h>

/* Clase wrapper para SDL_Window. La idea es enmascarar
 * todas las llamadas a las funciones de SDL detrás
 * de funciones nuestras con nombres más amigables.
 */

class Window {
public:
	Window();
	~Window();
	bool Create(const char* title,int width, int height);
	/*Este getter sólo tiene sentido porque SDL_Renderer necesita el SDL_Window* */
	SDL_Window* GetWindow()const{return pWindow;};

private:
	SDL_Window* pWindow;
};

#endif	/*__WINDOW__*/