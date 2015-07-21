#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__
#include <SDL2/SDL.h>
#include "Player.h"
#include <iostream>
#include <vector>

class InputHandler
{
public:
	static InputHandler* Instance() {
		if (!pInstance) {
			pInstance = new InputHandler();
		}
		return pInstance;
	}
	void update();
	void clean();
	bool isKeyDown(SDL_Keycode key);
	bool handleInput();
	void onKeyDown(SDL_Keycode key);
	void onKeyUp(SDL_Keycode key);
	void addPlayer(Player* player);

	//Hacer privado
	std::vector<Player*> players;
private:
	InputHandler();
	~InputHandler();
	static InputHandler* pInstance;
	Uint8* keyboardState;
//	std::vector<Player*> players;
};

#endif