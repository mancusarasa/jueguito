#ifndef __PLAYER__
#define __PLAYER__

#include "../headers/Texture.h"
#define IMAGE_PATH "imgs/pallet.bmp"


class Player : public Texture {
public:
	Player(SDL_Renderer*);
	~Player();
	void Draw(SDL_Renderer*);
	void MoveDown();
	void MoveUp();
};

#endif /*__PLAYER__*/ 