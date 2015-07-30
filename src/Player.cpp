#include "../headers/Player.h"

Player::Player(SDL_Renderer* pRenderer, int offsetX, int offsetY):Texture(IMAGE_PATH, pRenderer, offsetX, offsetY){

}


Player::~Player(){

}

void Player::moveDown(){
	y++;
}

void Player::moveUp(){
	y--;
}