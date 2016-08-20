#ifndef __BALL__
#define __BALL__

#include "Texture.h"
#include "Drawable.h"
#include <math.h>
#define BALL_IMG_PATH "imgs/ball.png"

class Ball : public Drawable
{
public:
	Ball(SDL_Renderer*);
	~Ball();
	void setSpeedX();
	virtual void update();
	float getX();
private:
	float initialX;
	float initialY;
	float speedX;
	float speedY;
	float distanceX;
};
#endif