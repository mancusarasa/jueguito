#include "../headers/Texture.h"


Texture::Texture(std::string path,SDL_Renderer* pRenderer):pathToImage(path){
	SDL_Surface* pTempSurface = SDL_LoadBMP(path.c_str());
	pTexture = SDL_CreateTextureFromSurface(pRenderer,pTempSurface);
	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(pTexture,0,0,&rectangle.w,&rectangle.h);
	/* Por defecto, seteo (x,y) = (0,0), o sea, arriba a la izquierda
	 * en la ventana.  
	 */
	rectangle.x = 0;
	rectangle.y = 0;
}

Texture::~Texture(){

}