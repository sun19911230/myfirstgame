#include "animatedCharacter.h"
#include "graphics.h"
#include "charactor.h"

AnimatedCharacter::AnimatedCharacter() {}

AnimatedCharacter::AnimatedCharacter(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY,
		int width, int height, float posX, float posY, float timetoUpdate) :
				Charactor(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
				_frameIndex(0),
				_timeToUpdate(timetoUpdate),
				_visible(true),
				_currentAnimationOnce(false),
				_currentAnimation(""),
				_timeElapsed(0)
{}


void AnimatedCharacter::addAnimation(int frames, int x, int y, std::string name, int width, int height, Point2 offset) {
	std::vector<SDL_Rect> rectangles;
	for(int i = 0; i< frames; i++) {
		SDL_Rect newRect = {0, (i + x) * height, width, height };
		rectangles.push_back(newRect);
	}
	this->_animations.insert(std::pair<std::string, std::vector<SDL_Rect> >(name, rectangles));
	this->_offsets.insert(std::pair<std::string, Point2>(name,offset));
}

void AnimatedCharacter::resetAnimations() {
	this->_animations.clear();
	this->_offsets.clear();
}

void AnimatedCharacter::playAnimation(std::string animation, bool once) {
	this->_currentAnimationOnce = once;
	if (this->_currentAnimation != animation) {
		this->_currentAnimation = animation;
		this->_frameIndex = 0;
	}
}

void AnimatedCharacter::setVisible(bool visible) {
	this->_visible = visible;
}

void AnimatedCharacter::stopAnimations() {
	this->_frameIndex = 0;
	this->animationDone(this->_currentAnimation);
}

void AnimatedCharacter::update(int elapsedTime) {
	Charactor::update();
	this->_timeElapsed += elapsedTime;
	if(this->_timeElapsed > this->_timeToUpdate) {
		this->_timeElapsed -= this->_timeToUpdate;
		this->_frameIndex  =  (this->_frameIndex + 1) % this->_animations[this->_currentAnimation].size();
		if (this->_frameIndex == 0) {
			if (this->_currentAnimationOnce) this->setVisible(false);
			this->animationDone(this->_currentAnimation);
		}

	}
}

void AnimatedCharacter::draw(Graphics &graphics, int x, int y) {
	if (this->_visible) {
		SDL_Rect desRec;
		desRec.x = x + this->_offsets[this->_currentAnimation].x;
		desRec.y = y + this->_offsets[this->_currentAnimation].y;
		desRec.w = this->_sourceRect.w * globals::CHARACTOR_SCALE;
		desRec.h = this->_sourceRect.h * globals::CHARACTOR_SCALE;

		SDL_Rect sourceRect = this->_animations[this->_currentAnimation][this->_frameIndex];
		graphics.blitSurface(this->_charSheet, &sourceRect, &desRec);
	}
}

void AnimatedCharacter::animationDone(std::string currentAnimation) {

}

void AnimatedCharacter::setupAnimations(){
	this->addAnimation(12,0,0,"fight",256,256,Point2(0,0));
}
