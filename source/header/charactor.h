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
private:
	SDL_Rect _sourceRect;
	SDL_Texture *_charSheet;
	float _x, _y;
};

#endif
