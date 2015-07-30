#ifndef __TEXTURE__
#define __TEXTURE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "JsonReader.h"
#include <string>
#include <iostream>

class Texture {
public:
	Texture(std::string, SDL_Renderer*);
	~Texture();
	virtual void draw();
	virtual void setPosition(float x, float y); //Posicion inicial, usa el offset
	virtual void updatePosition(float x, float y); //Posicion relativa a la actual, no usa el offset
	virtual void moveDown();
	virtual void moveUp();
	virtual void update();
	virtual void setSize(int width, int height);


protected:
	SDL_Renderer* pRenderer_;
	SDL_Texture* pTexture;
	SDL_Rect rendererRectangle;
	SDL_Rect bmpRectangle;
	std::string pathToImage;
	float x;
	float y;
	int offsetX;
	int offsetY;
	SDL_Texture* GetTexture() {return pTexture;}
	SDL_Rect& GetRectangle() {return rendererRectangle;}
	
};

#endif /*__TEXTURE__*/