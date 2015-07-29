#include "../headers/Texture.h"


Texture::Texture(std::string path,SDL_Renderer* pRenderer):pathToImage(path),pRenderer_(pRenderer){
	SDL_Surface* pTempSurface = SDL_LoadBMP(path.c_str());
	pTexture = SDL_CreateTextureFromSurface(pRenderer,pTempSurface);
	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(pTexture,0,0,&rendererRectangle.w,&rendererRectangle.h);
	/* Por defecto, seteo (x,y) = (0,0), o sea, arriba a la izquierda
	 * en la ventana.  
	 */
	rendererRectangle.x = 30;
	rendererRectangle.y = 20;
	bmpRectangle.x = 0;
	bmpRectangle.y = 0;
	//bmpRectangle.x = rendererRectangle.x;
	//bmpRectangle.y = rendererRectangle.y;
	bmpRectangle.w = rendererRectangle.w;
	bmpRectangle.h = rendererRectangle.h;
}

Texture::~Texture(){

}

void Texture::draw() {
	rendererRectangle.x = x;
	rendererRectangle.y = y;
	SDL_RenderCopy(pRenderer_, GetTexture(), &bmpRectangle, &rendererRectangle);
}

void Texture::setPosition(int posX, int posY) {
	x = posX;
	y = posY;

}