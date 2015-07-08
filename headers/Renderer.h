#include <SDL2/SDL.h>
#include <assert.h>
#include "../headers/Window.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	bool Create(const Window&);
	void SetDrawColor(int,int,int,int);
	void Clear();
	void Present();

private:
	SDL_Renderer* pRenderer;
};