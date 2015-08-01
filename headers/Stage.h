#ifndef __STAGE__
#define __STAGE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.h"

#define STAGE_IMG_PATH "imgs/stage.jpeg"

/*
	Clase Stage, necesaria en principio para definir bordes del escenario para el rebote de la pelota y a su vez abstraer su funcionalidad de la ventana.
	X e Y definen posicion (en principio 0,0 -arriba izq-)
 */


class Stage : public Texture
{
public:
	Stage( int width, int height, int x, int y, SDL_Renderer*);
	Stage( int width, int height, int x, int y, SDL_Renderer*, std::string imgPath);
	~Stage();
	int getX() const { return x; }
	int getY() const { return y; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	virtual void draw();

private:
	int x;
	int y;
	int width;
	int height;
};

#endif