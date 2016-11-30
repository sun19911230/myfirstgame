#ifndef CHARACTOR_H
#define CHARACTOR_H

#include <SDL2/SDL.h>
#include <string>
class Graphics;

class Charactor {
public:
	Charactor();
	Charactor(Graphics &graphics, const std::string &filePaht, int sourceX, int sourceY, int width, int height,
			float posX, float posY);
	virtual ~Charactor();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);
protected:
	SDL_Rect _sourceRect;
	SDL_Texture *_charSheet;
private:
	float _x, _y;
};

#endif
