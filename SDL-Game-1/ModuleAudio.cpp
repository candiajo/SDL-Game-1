#include "ModuleAudio.h"

#include "SDL2_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL2_mixer/lib/x86/SDL2_mixer.lib" )

ModuleAudio::ModuleAudio()
{}

ModuleAudio::~ModuleAudio()
{
	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

bool ModuleAudio::Init()
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)									// init audio
	{
		LOG("SDL could not initialize AUDIO! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)		// init SDL_mixer
	{
		LOG("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}
	else
	{
		return true;													// all went fine
	}
}

bool ModuleAudio::CleanUp()
{
	Mix_FreeMusic(music);
	Mix_FreeChunk(soundfx);

	return true;
}

bool ModuleAudio::LoadMusic(const char* path)
{
	if ((music = Mix_LoadMUS(path)) == NULL)
	{
		LOG("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}
	else
	{
		return true;
	}
}

bool ModuleAudio::LoadSoundfx(const char* path)
{
	soundfx = Mix_LoadWAV(path);

	if (soundfx == NULL)
	{
		LOG("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}
	else
	{
		return true;
	}
}

void ModuleAudio::PlayMusic()
{
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(music, -1);
	}
}

void ModuleAudio::PlaySoundfx()
{
 	if (soundfx != NULL)
	{
		Mix_PlayChannel(-1, soundfx, 0);
	}
	else
	{
		LOG("No soundfx loaded.\n");
	}
} 