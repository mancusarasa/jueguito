#ifndef __TEXTURE__
#define __TEXTURE__

#include <SDL2/SDL.h>
#include <string>

class Texture {
public:
	Texture(std::string, SDL_Renderer*);
	~Texture();
	virtual void Draw(SDL_Renderer*)=0;
	virtual void moveDown()=0;
	virtual void moveUp()=0;

protected:
	SDL_Texture* pTexture;
	SDL_Rect rendererRectangle;
	SDL_Rect bmpRectangle;
	std::string pathToImage;
	SDL_Texture* GetTexture() {return pTexture;}
	SDL_Rect& GetRectangle() {return rendererRectangle;}
	
};

#endif /*__TEXTURE__*/