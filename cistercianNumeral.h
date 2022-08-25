#pragma once

#include <SDL.h>

class Numeral {
public:
	Numeral(Uint32 n = 0);
	Numeral(Uint32 n, SDL_Point o);
	~Numeral();

	void render();
	void update();

private:

	void drawStick();
	void drawTop();
	void drawBottom();
	void drawDownSlope();
	void drawUpSlope();
	void drawSide();

	// Ones, Tens, Hundreds, Thousands
	int state;

	SDL_Point origin;

	int value;
	Numeral* next;
	static const int space = 15;
};