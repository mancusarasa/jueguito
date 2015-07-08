#include "../headers/Renderer.h"

Renderer::Renderer():pRenderer(NULL){

}

Renderer::~Renderer(){
	if(pRenderer)
		SDL_DestroyRenderer(pRenderer);
}

/* 
 * @return: true si salió todo bien (que debería ser siempre)
 */

bool Renderer::Create(const Window& w){
	assert(!pRenderer);
	SDL_Window* pWindow = w.GetWindow();
	/* Deshardcodear esos -1 y 0 en algún momento de la vida */
	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
	return true;
}


void Renderer::SetDrawColor(int r, int g, int b, int alpha){
	SDL_SetRenderDrawColor(pRenderer, r, g, b, alpha);
}

void Renderer::Clear(){
	SDL_RenderClear(pRenderer);
}
	
void Renderer::Present(){
	SDL_RenderPresent(pRenderer);
}
