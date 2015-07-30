#ifndef __TEXTURE__
#define __TEXTURE__

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Texture {
public:
	Texture(std::string, SDL_Renderer*, int offsetX, int offsetY);
	~Texture();
	virtual void draw();
	virtual void setPosition(int x, int y);
	virtual void moveDown()=0;
	virtual void moveUp()=0;

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