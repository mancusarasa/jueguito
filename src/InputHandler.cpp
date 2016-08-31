#include "../headers/InputHandler.h"

InputHandler* InputHandler::pInstance = 0;

void InputHandler::update() {

}

void InputHandler::clean() {

}

InputHandler::InputHandler() {

}

void InputHandler::addPlayer(Player* player) {
	players.push_back(player);
}

InputHandler::~InputHandler() {

}

void InputHandler::onKeyDown(SDL_Keycode key) {
	
	switch (key) {

		case SDLK_UP:
			players[0]->moveUp();		
		break;

		case SDLK_DOWN:
			players[0]->moveDown();
		break;
		
		case SDLK_s:
			//players.at(1)->moveDown();
		break;

		case SDLK_w:
			//players.at(1)->moveUp();
		break;

		default:
		
		break;	
			
	}
}

bool InputHandler::isKeyDown(SDL_Keycode key) {
	if (keyboardState != 0) {
		if (keyboardState[key] == 1 ) return true;
	}
	return false;
}

bool InputHandler::handleInput() {

	return true;
}
