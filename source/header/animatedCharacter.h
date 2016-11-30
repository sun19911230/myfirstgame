#ifndef ANIMATEDCHARACTER_H
#define ANIMATEDCHARACTER_H

#include <map>
#include <string>
#include <vector>
#include "charactor.h"
#include "globals.h"
class Graphics;

/* AnimatedCharacter
 *
 */

class AnimatedCharacter : public Charactor {
public:
	AnimatedCharacter();
	AnimatedCharacter(Graphics &graphics, const std::string &filePath, int SourceX, int courceY,int width, int height,
			float posX, float posY, float timeToUpdate);

	void playAnimation(std::string animation, bool once = false);
	void update(int elapsedTime);
	void draw(Graphics &graphics, int x, int y);

	virtual void setupAnimations();

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Point2 offset);

	void resetAnimations();

	void stopAnimations();

	void setVisible(bool visible);

	virtual void animationDone(std::string currentAnimation);

private:
	std::map<std::string, std::vector<SDL_Rect> > _animations;
	std::map<std::string, Point2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

#endif
