#ifndef __PLAYER__
#define __PLAYER__

#include "Texture.h"
#include "Drawable.h"
#define IMAGE_PATH "imgs/pallet.bmp"


class Player : public Drawable {
public:
	Player(SDL_Renderer* );
	~Player();
	//void draw();
	void moveDown();
	void moveUp();
};

#endif /*__PLAYER__*/ 