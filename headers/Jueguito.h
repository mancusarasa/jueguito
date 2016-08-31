#ifndef __Jueguito__
#define __Jueguito__

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "Window.h"
#include "Renderer.h"
#include "JsonReader.h"
#include "Player.h"
#include "InputHandler.h"
#include "Brick.h"
#include "Stage.h"
#include "Ball.h"
#include "LayoutManager.h"
/**
 * Clase principal
 * bool isRunning mantiene el loop del juego
 * Doc: The Game Class p21 
 */
class Jueguito {
public:
	Jueguito();
	~Jueguito();
	void init();
	void render();
	void handleEvents();
	void update();
	void clean();
	bool IsRunning();
	void setIsRunning(bool estado);
private:
	bool isRunning;
	Window window;
	Renderer renderer;
	LayoutManager* layoutManager;
	Stage* stage;
//	std::vector<Drawable*> drawables;
};


#endif
