#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals {
const int SCREEN_LENGTH = 512;
const int SCREEN_WIDTH = 512;
const float CHARACTOR_SCALE = 2.0f;
}

struct Point2 {
	int x,y;
	Point2(int x = 0, int y = 0) :
		x(x), y(y)
	{}

	Point2 zero() {return Point2();}
};

#endif
