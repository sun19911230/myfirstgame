#include "charactor.h"
#include "graphics.h"
#include "globals.h"

Charactor::Charactor() {}

Charactor::Charactor(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY) :
				_x(posX), _y(posY) {
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	this->_charSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(),graphics.loadImage(filePath));

}

Charactor::~Charactor() {}


void Charactor::draw(Graphics &graphics, int x, int y) {
	SDL_Rect destinationRectangle = {x,y,this->_sourceRect.w * globals::CHARACTOR_SCALE,this->_sourceRect.h * globals::CHARACTOR_SCALE};
	graphics.blitSurface(this->_charSheet, &this->_sourceRect, &destinationRectangle);
}

void Charactor::update() {}
