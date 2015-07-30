#ifndef __BRICK__
#define __BRICK__

#include "Texture.h"
#define BRICK_BMP_PATH "imgs/brick.png"

class Brick : public Texture
{
public:
	Brick(SDL_Renderer*);
	~Brick();
//	virtual void draw();
	void moveDown();
	void moveUp();
};

#endif
