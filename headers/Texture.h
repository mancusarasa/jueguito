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
	void draw();
	void setPosition(float x, float y); //Posicion inicial, usa el offset
	void updatePosition(float x, float y); //Posicion relativa a la actual, no usa el offset
	//virtual void moveDown();
	//virtual void moveUp();
	//virtual void update();
	void setSize(int width, int height);
	int getWidth() { return bmpRectangle.w;}
	SDL_Rect bmpRectangle;
	SDL_Rect rendererRectangle;

protected:
	SDL_Renderer* pRenderer_;
	SDL_Texture* pTexture;
	std::string pathToImage;
	//float x;
	//float y;
	int offsetX;
	int offsetY;
	SDL_Texture* GetTexture() {return pTexture;}
	SDL_Rect& GetRectangle()  {return rendererRectangle;}

private:
	int x;
	int y;
};

#endif /*__TEXTURE__*/