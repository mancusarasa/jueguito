#ifndef __PLAYER__
#define __PLAYER__

#include "../headers/Texture.h"
#define IMAGE_PATH "imgs/pallet.bmp"


class Player : public Texture {
public:
	Player(SDL_Renderer* ,int offsetX, int offsetY);
	~Player();
	//void draw();
	void moveDown();
	void moveUp();
};

#endif /*__PLAYER__*/ 