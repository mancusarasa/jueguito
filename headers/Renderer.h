#ifndef __RENDERER__
#define __RENDERER__

#include <SDL2/SDL.h>
#include <assert.h>
#include "../headers/Window.h"
#include "../headers/Texture.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	bool Create(const Window&);
	void SetDrawColor(int,int,int,int);
	void Clear();
	void Present();
	void RenderTexture(Texture* t);

private:
	SDL_Renderer* pRenderer;
	SDL_Renderer* GetRenderer(){return pRenderer;};
	friend class Jueguito;
};

#endif	/*__RENDERER__*/