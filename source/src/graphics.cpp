#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"
#include "globals.h"
Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH,globals::SCREEN_LENGTH,0,&this->_window,&this->_renderer);
	SDL_SetWindowTitle(this->_window,"Miao");
}

Graphics::~Graphics(){
	SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string& filePath) {
	if (this->_charSHeet.count(filePath) == 0)
		this->_charSHeet[filePath] = IMG_Load(filePath.c_str());
	return this->_charSHeet[filePath];
}

void Graphics::blitSurface(SDL_Texture * texture, SDL_Rect * sourceRectangle, SDL_Rect * destinationRectangle) {
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer * Graphics::getRenderer() const {
	return this->_renderer;
}
