#ifndef __LAYOUTMANAGER__
#define __LAYOUTMANAGER__
#include "Window.h"
#include <vector>
#include "Drawable.h"
#include "Renderer.h"
/*
Clase encargada de posicionar elementos en la ventana
 */

class LayoutManager
{
public:
	LayoutManager();
	~LayoutManager();
	void addDrawable(Drawable*);
	void setStagePosition(int x, int y);
	void drawObjects(Renderer* renderer);
	std::vector<Drawable*> drawables; // esta publico en principio por el metodo update de Jueguito.cpp

private:
	int stageX, stageY;

};
#endif