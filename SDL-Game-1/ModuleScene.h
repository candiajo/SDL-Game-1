#pragma once

#include "Module.h"

struct SDL_Texture;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Init();
	update_status Update();

private:
	SDL_Texture* texture;
};