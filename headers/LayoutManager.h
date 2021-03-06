#ifndef __LAYOUTMANAGER__
#define __LAYOUTMANAGER__
#include "Window.h"
#include <vector>
#include "Drawable.h"
#include "Renderer.h"
#include "Ball.h"

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
	std::vector<Ball*> bouncers;
	std::vector<Drawable*> collitionables;

/* Por ahora los únicos rebotadores son las Ball, pero deberían ser una clase aparte */
	void addBouncer(Ball*); //Por lo pronto son los unicos rebotadores, pero debería ser una clase aparte
	void manageBouncerUpdate(Ball*); //Idem, debería recibir un Bouncer
	Drawable* findCollitions(Ball*); //Idem
	void solveCollition(Ball*, Drawable*);
	bool willCollide(Ball*, Drawable*);
	void addCollitionable(Drawable*);


private:
	int stageX, stageY;
	float getXImpactSurfacePosition(Drawable* drawable, int offset);
	float getYImpactSurfacePosition(Drawable* drawable, int offset);

};
#endif