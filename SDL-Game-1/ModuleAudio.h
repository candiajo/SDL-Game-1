#pragma once

#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL.h"
#include "SDL2_mixer/include/SDL_mixer.h"

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();

	bool CleanUp();

	bool LoadMusic(const char* path);
	bool LoadSoundfx(const char* path);

	void PlayMusic();
	void PlaySoundfx();

private:
	Mix_Music* music = NULL;
	Mix_Chunk* soundfx = NULL;
};