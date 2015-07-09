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
	/* Devuelve una textura. Liberar la memoria es 
	 * responsabilidad del que llama a la función.
	 */
	Texture* CreateTexture(std::string);
	void ShowTexture(Texture* t);

private:
	SDL_Renderer* pRenderer;
};

#endif	/*__RENDERER__*/