#pragma once

#include <SDL.h>
#include <vector>
#include "cistercianNumeral.h"

void init_Graphics();
void shutdown_Graphics();

SDL_Renderer* getRenderer();
int screenWidth();
int screenHeight();

void render(std::vector<Numeral>);