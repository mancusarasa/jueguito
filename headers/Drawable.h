#ifndef __DRAWABLE__
#define __DRAWABLE__

#include "Texture.h"
#include <string>
#include <iostream>

/*
	Clase para los objetos dibujables.
	Características:
		- Tienen una textura
		- Enmascaran el funcionamiento de la misma (método draw propio, update, position). 
			Notar que la posicion de un dibujable se da en float (lógica de movimiento) mientras que una textura maneja ints (lógica de pixel)
		-

 */

class Drawable {

public:
	Drawable(std::string, SDL_Renderer*);
	~Drawable();
	virtual void draw();
	virtual void setPosition(float x, float y); //Posicion inicial, usa el offset
	virtual void updatePosition(float x, float y); //Posicion relativa a la actual, no usa el offset
	//virtual void moveDown();
	//virtual void moveUp();
	virtual void update();
	virtual void setSize(int width, int height);

	
protected:
	SDL_Renderer* pRenderer_;
	Texture* texture;
	SDL_Rect rendererRectangle;
	SDL_Rect bmpRectangle;
	std::string pathToImage;
	float x;
	float y;
	int offsetX;
	int offsetY;
	int width;
	int height;
	
public:	
	Texture* getTexture() {return texture;}
	SDL_Rect& getRectangle()  {return rendererRectangle;}
	int getWidth() { return width;}
	int getHeight() {return height;}
};

#endif