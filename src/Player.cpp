#include "../headers/Player.h"

Player::Player(SDL_Renderer* pRenderer):Texture(IMAGE_PATH, pRenderer){

}

void Player::draw(){
	SDL_RenderCopy(pRenderer_, GetTexture(), &bmpRectangle, &rendererRectangle);
}

Player::~Player(){

}

void Player::moveDown(){
	rendererRectangle.y++;
}

void Player::moveUp(){
	rendererRectangle.y--;
}