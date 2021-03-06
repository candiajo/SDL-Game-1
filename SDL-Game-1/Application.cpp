#pragma once
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "ModuleAudio.h"

using namespace std;

Application::Application()
{
	// Order matters: they will Init/start/update in this order
/*	modules.push_back(window = new ModuleWindow());
	modules.push_back(renderer = new ModuleRender());
	modules.push_back(textures = new ModuleTextures());
	modules.push_back(input = new ModuleInput());
	modules.push_back(audio = new ModuleAudio());
	modules.push_back(scene = new ModuleScene());*/	

	modules[0] = (window = new ModuleWindow());
	modules[1] = (renderer = new ModuleRender());
	modules[2] = (textures = new ModuleTextures());
	modules[3] = (input = new ModuleInput());
	modules[4] = (audio = new ModuleAudio());
	modules[5] = (scene = new ModuleScene());

	// TODO 7: Create a new "scene" module that loads a texture and draws it on the screen

	// Homework: Create a new module to handle music and sound effects
}

Application::~Application()
{
	// TODO 6: Free module memory and check the result in Dr. Memory

	for (auto& it : modules)
	{
		delete(it);
	}

	//for (auto it = modules.begin(); it != modules.end(); ++it)
	//	delete(*it);

	//modules.clear();
	SDL_Quit();
}

bool Application::Init()
{
	bool ret = true;

	for(auto it = modules.begin(); it != modules.end() && ret; ++it)
		ret = (*it)->Init();

	return ret;
}

bool Application::Start()
{
	bool ret = true;

	for (auto it = modules.begin(); it != modules.end() && ret; ++it)
		ret = (*it)->Start();

	return ret;
}

// TODO 4: We need to have three updates, add them: PreUpdate Update PostUpdate

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;
	
	for (auto it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->PreUpdate();
		
	for (auto it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->Update();
	
	for (auto it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->PostUpdate();

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(auto it = modules.rbegin(); it != modules.rend() && ret; ++it)
		ret = (*it)->CleanUp();

	return ret;
}
