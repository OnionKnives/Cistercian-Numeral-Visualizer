#include <vector>

#include "input.h"
#include "graphics.h"
#include "cistercianNumeral.h"

void Numeral::drawStick() {
	SDL_Rect rect;

	rect.x = origin.x - 1;
	rect.y = origin.y;
	rect.w = 3;
	rect.h = space * 2 + 11;

	SDL_RenderFillRect(getRenderer(), &rect);
}

void Numeral::drawTop() {
	SDL_Rect rect = { 0, 0, space, 2 };

	switch (state) {
	case 0:
		rect.x = origin.x;
		rect.y = origin.y;
		break;
	case 1:
		rect.x = origin.x - space;
		rect.y = origin.y;
		break;
	case 2:
		rect.x = origin.x;
		rect.y = origin.y + space * 2 + 10;
		break;
	case 3:
		rect.x = origin.x - space;
		rect.y = origin.y + space * 2 + 10;
		break;
	}

	SDL_RenderFillRect(getRenderer(), &rect);
}

void Numeral::drawBottom() {
	SDL_Rect rect = { 0, 0, space, 2 };

	switch (state) {
	case 0:
		rect.x = origin.x;
		rect.y = origin.y + space;
		break;
	case 1:
		rect.x = origin.x - space;
		rect.y = origin.y + space;
		break;
	case 2:
		rect.x = origin.x;
		rect.y = origin.y + space + 10;
		break;
	case 3:
		rect.x = origin.x - space;
		rect.y = origin.y + space + 10;
		break;
	}

	SDL_RenderFillRect(getRenderer(), &rect);
}

void Numeral::drawDownSlope() {

	SDL_Point start = {0, 0};
	SDL_Point end = { 0, 0 };

	switch (state) {
	case 0:
		start.x = origin.x;
		start.y = origin.y;
		end.x = origin.x + space;
		end.y = origin.y + space;
		break;
	case 1:
		start.x = origin.x;
		start.y = origin.y;
		end.x = origin.x - space;
		end.y = origin.y + space;
		break;
	case 2:
		start.x = origin.x;
		start.y = origin.y + space * 2 + 10;
		end.x = origin.x + space;
		end.y = origin.y + space + 10;
		break;
	case 3:
		start.x = origin.x;
		start.y = origin.y + space * 2 + 10;
		end.x = origin.x - space;
		end.y = origin.y + space + 10;
		break;
	}

	SDL_RenderDrawLineF(getRenderer(), start.x, start.y, end.x, end.y);
}

void Numeral::drawUpSlope() {

	SDL_Point start = { 0, 0 };
	SDL_Point end = { 0, 0 };

	switch (state) {
	case 0:
		start.x = origin.x;
		start.y = origin.y + space;
		end.x = origin.x + space;
		end.y = origin.y;
		break;
	case 1:
		start.x = origin.x;
		start.y = origin.y + space;
		end.x = origin.x - space;
		end.y = origin.y;
		break;
	case 2:
		start.x = origin.x;
		start.y = origin.y + space + 10;
		end.x = origin.x + space;
		end.y = origin.y + space * 2 + 10;
		break;
	case 3:
		start.x = origin.x;
		start.y = origin.y + space + 10;
		end.x = origin.x - space;
		end.y = origin.y + space * 2 + 10;
		break;
	}

	SDL_RenderDrawLineF(getRenderer(), start.x, start.y, end.x, end.y);
}

void Numeral::drawSide() {
	SDL_Rect rect = { 0, 0, 2, space + 2 };

	switch (state) {
	case 0:
		rect.x = origin.x + space;
		rect.y = origin.y;
		break;
	case 1:
		rect.x = origin.x - space;
		rect.y = origin.y;
		break;
	case 2:
		rect.x = origin.x + space;
		rect.y = origin.y + space + 10;
		break;
	case 3:
		rect.x = origin.x - space;
		rect.y = origin.y + space + 10;
		break;
	}

	SDL_RenderFillRect(getRenderer(), &rect);
}

Numeral::Numeral(Uint32 n) {
	origin = { 20, 20 };

	next = nullptr;
	
	if (n > 1'000'000)
		n = 1'000'000;

	if (n >= 10000) {
		value = 9999;
		next = new Numeral(n - 9999, { origin.x + space * 3, origin.y });
	}
	else {
		value = n;
	}

	state = 3;
}

Numeral::Numeral(Uint32 n, SDL_Point o) {
	origin = o;

	next = nullptr;

	if (n > 1'000'000)
		n = 1'000'000;

	if (n >= 10000) {
		value = 9999;

		SDL_Point nextSpace;
		if (origin.x + space * 3 >= screenWidth())
			nextSpace = { 20, origin.y + 60 };
		else {
			nextSpace = { origin.x + space * 3, origin.y };
		}

		next = new Numeral(n - 9999, nextSpace);
	}
	else {
		value = n;
	}

	state = 3;
}

Numeral::~Numeral() {
	delete next;
}

void Numeral::render() {
	drawStick();

	int readValue = value;
	for (int i = 1000; i > 0; i /= 10) {

		switch (readValue / i) {
		case 1:
			drawTop();
			break;
		case 2:
			drawBottom();
			break;
		case 3:
			drawDownSlope();
			break;
		case 4:
			drawUpSlope();
			break;
		case 5:
			drawTop();
			drawUpSlope();
			break;
		case 6:
			drawSide();
			break;
		case 7:
			drawTop();
			drawSide();
			break;
		case 8:
			drawBottom();
			drawSide();
			break;
		case 9:
			drawTop();
			drawBottom();
			drawSide();
			break;
		}

		readValue -= (readValue / i) * i;
		--state;
	}

	state = 3;
	if (next != nullptr)
		next->render();
}

void Numeral::update() {
	//Get number input

	//Add number to the 
}
