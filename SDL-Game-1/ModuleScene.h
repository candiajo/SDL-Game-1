#pragma once

#include "Module.h"

struct SDL_Texture;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Init();
	bool Start();
	update_status Update();

private:
	SDL_Texture* texture;
};