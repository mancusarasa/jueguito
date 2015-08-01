#ifndef __BALL__
#define __BALL__

#include "Texture.h"
#define BALL_IMG_PATH "imgs/ball.png"

class Ball : public Texture
{
public:
	Ball(SDL_Renderer*);
	~Ball();
	void setSpeedX();
	virtual void update();
private:
	float initialX;
	float initialY;
	float speedX;
	float speedY;
};
#endif