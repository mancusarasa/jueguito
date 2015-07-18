#include "../headers/Player.h"

Player::Player(SDL_Renderer* pRenderer):Texture(IMAGE_PATH, pRenderer){

}

void Player::Draw(SDL_Renderer* pRenderer){
	SDL_RenderCopy(pRenderer,GetTexture(),&bmpRectangle,&rendererRectangle);
}

Player::~Player(){

}

void Player::MoveDown(){
	rendererRectangle.y--;
}

void Player::MoveUp(){
	rendererRectangle.y++;
}