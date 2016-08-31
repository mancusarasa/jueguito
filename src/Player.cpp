#include "../headers/Player.h"

Player::Player(SDL_Renderer* pRenderer):Drawable(IMAGE_PATH, pRenderer){

}


Player::~Player(){

}

void Player::moveDown(){
	y++;
}

void Player::moveUp(){
	y--;
}