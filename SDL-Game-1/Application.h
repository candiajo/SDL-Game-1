#pragma once

#include <array>
#include "Globals.h"

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleScene;
class ModuleAudio;

class Module;

class Application
{
public:
	Application();
	~Application();

	bool Init();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleScene* scene;
	ModuleAudio* audio;

private:
	//std::list<Module*> modules;
	std::array<Module*, NUMBER_OF_MODULES> modules;

};

extern Application* App;