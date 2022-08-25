#include <SDL_ttf.h>

#include "text.h"
#include "input.h"

void init_Text() {
	if (TTF_Init() != 0)
		shutdown();
}

void shutdown_Text() {
	TTF_Quit();
}
