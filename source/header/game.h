#ifndef GAME_H
#define GAME_H
class Charactor;
class Graphics;
class Game {
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);
	Charactor * _player;
};

#endif
