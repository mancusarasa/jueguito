#ifndef __TEXTURE__
#define __TEXTURE__

#include <SDL2/SDL.h>
#include <string>

class Texture {
public:
	~Texture();
private:
	SDL_Texture* pTexture;
	SDL_Rect rectangle;
	std::string pathToImage;
	SDL_Texture* GetTexture() {return pTexture;}
	SDL_Rect& GetRectangle() {return rectangle;}
	
	/* Decision polemica de diseño: que Renderer se encargue 
	 * de las texturas teniendo toda la visibilidad sobre sus atributos.
	 */
	Texture(std::string, SDL_Renderer*);
	
	
	friend class Renderer;
};

#endif /*__TEXTURE__*/