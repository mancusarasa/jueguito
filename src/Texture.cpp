#include "../headers/Texture.h"


Texture::Texture(std::string path,SDL_Renderer* pRenderer):pathToImage(path),pRenderer_(pRenderer){
	//SDL_Surface* pTempSurface = SDL_LoadBMP(path.c_str());
	SDL_Surface* pTempSurface = IMG_Load(path.c_str());
	if ( !pTempSurface ) std::cout << "No se pudo cargar la imagen: " << path << std::endl;
	pTexture = SDL_CreateTextureFromSurface(pRenderer,pTempSurface);
	if ( !pTexture) std::cout << "Error creando la textura" << std::endl;
	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(pTexture,0,0,&rendererRectangle.w,&rendererRectangle.h);
	/* Por defecto, seteo (x,y) = (0,0), o sea, arriba a la izquierda
	 * en la ventana.  
	 */
	//rendererRectangle.x = 30;
	//rendererRectangle.y = 20;
	rendererRectangle.x = 0;
	rendererRectangle.y = 0;
	

	bmpRectangle.x = 0;
	bmpRectangle.y = 0;
	//bmpRectangle.x = rendererRectangle.x;
	//bmpRectangle.y = rendererRectangle.y;
	bmpRectangle.w = rendererRectangle.w;
	bmpRectangle.h = rendererRectangle.h;
	this->rotationAngle = 0;
}

Texture::~Texture(){
	SDL_DestroyTexture(pTexture);
}

//Devuelve la versión int de un flotante, .5 redondea para arriba
int floatToInt(float n) {
	return static_cast<int>( roundf( n ) );
}

//Las posiciones x e y son flotantes por cuestiones matemáticas, pero los pixeles son enteros, por eso es necesario convertir coordenadas a enteros
void Texture::draw() {
	rendererRectangle.x = floatToInt( x );
	rendererRectangle.y = floatToInt( y );
	int res = SDL_RenderCopyEx(pRenderer_, GetTexture(), &bmpRectangle, &rendererRectangle, this->rotationAngle, NULL, SDL_FLIP_NONE);
	if (res != 0) std::cout << "Error cargando la imagen: " << pathToImage << " // error: " << SDL_GetError() << std::endl;
}


void Texture::updatePosition(float posX, float posY) {

	x = posX;
	y = posY;
}

void Texture::setPosition(float posX, float posY) {
	x = posX + JsonReader::Instance()->getStageValue("x");
	y = posY + JsonReader::Instance()->getStageValue("y");
}
/*
void Texture::update() {

}

void Texture::moveUp() {

}

void Texture::moveDown() {

}*/

void Texture::setSize(int width, int height) {
	rendererRectangle.w = width;
	rendererRectangle.h = height;
}