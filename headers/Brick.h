#ifndef __BRICK__
#define __BRICK__

#include "Texture.h"

#define BRICK_BMP_PATH "imgs/pallet.bmp"

class Brick : public Texture
{
public:
	Brick(SDL_Renderer*, int offsetX, int offsetY);
	~Brick();
//	virtual void draw();
	void moveDown();
	void moveUp();
};

#endif
