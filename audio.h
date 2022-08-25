#pragma once
#include <string>
#include <SDL_mixer.h>

void init_Audio();
void shutdown_Audio();

Mix_Music* loadMusic(std::string file);
Mix_Chunk* loadSFX(std::string file);
Mix_Chunk* loadSFX(std::string file, unsigned int volume);
void playMusic(Mix_Music*);
void playSFX(Mix_Chunk*);

void setMusicVolume(unsigned int volume);
void setSFXVolume(unsigned int volume);