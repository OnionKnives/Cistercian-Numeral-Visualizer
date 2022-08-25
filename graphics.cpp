#include <SDL.h>
#include <SDL_image.h>

#include <vector>

#include "input.h"
#include "graphics.h"
#include "cistercianNumeral.h"

using namespace std;

struct WindowData {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	int width = 640;
	int height = 480;
} window;

void init_Graphics() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 &&
		IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
		shutdown();

	try {
		window.window = SDL_CreateWindow("Cistercian Numeral Visualizer",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			window.width, window.height,
			0);

		if (window.window == nullptr)
			throw "Window failed to initialize";

		window.renderer = SDL_CreateRenderer(window.window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (window.renderer == nullptr)
			throw "Renderer failed to initialize";

		SDL_SetRenderDrawBlendMode(window.renderer, SDL_BLENDMODE_BLEND);
	}
	catch (const char* error) {
		SDL_Log("%s, %s", error, SDL_GetError());
	}
}

SDL_Renderer* getRenderer() {
	return window.renderer;
}

int screenWidth() {
	return window.width;
}

int screenHeight() {
	return window.height;
}

void shutdown_Graphics() {
	SDL_DestroyRenderer(window.renderer);
	SDL_DestroyWindow(window.window);

	IMG_Quit();
	SDL_Quit();
}

void render(vector<Numeral> numerals) {
	SDL_SetRenderDrawColor(window.renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(window.renderer);

	SDL_SetRenderDrawColor(getRenderer(), 0xAA, 0xAA, 0xAA, 0xFF);
	for (auto numeral : numerals) {
		numeral.render();
	}

	SDL_RenderPresent(window.renderer);
}
