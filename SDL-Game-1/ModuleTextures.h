#pragma once

#include <list>
#include <map>
#include <string>
#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
using namespace std;

class ModuleTextures : public Module
{
public:
	ModuleTextures();
	~ModuleTextures();

	bool Init();
	bool CleanUp();

	//SDL_Texture* const Load(const char* path);
	SDL_Texture* const LoadMap(const char* name, const char* path);

	SDL_Texture* const GetTextureMap(const char*);

private:
	//list<SDL_Texture*> textures;
	map<string, SDL_Texture*> texturesMap;
};