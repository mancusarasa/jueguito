#include "../headers/Drawable.h"

Drawable::Drawable(std::string image_path, SDL_Renderer* pRenderer) {
	this->texture = new Texture(image_path, pRenderer);

}

Drawable::~Drawable() {
	delete texture;
}

//Las posiciones x e y son flotantes por cuestiones matemáticas, pero los pixeles son enteros, por eso es necesario convertir coordenadas a enteros
void Drawable::draw() {
	texture->draw();
}

void Drawable::update() {

}

void Drawable::updatePosition(float posX, float posY) {
	texture->updatePosition(posX, posY);
}

void Drawable::setPosition(float posX, float posY) {
	x = posX;
	y = posY;
	texture->setPosition(posX, posY);
}

void Drawable::setSize(int width, int height) {
	texture->setSize(width, height);
}