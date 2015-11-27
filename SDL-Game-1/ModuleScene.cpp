#include "ModuleScene.h"
#include "ModuleTextures.h"


ModuleScene::ModuleScene()
{}

ModuleScene::~ModuleScene()
{}

bool ModuleScene::Init()
{
	bool ret = true;

	ret = App->textures->Load(SPRITE_FILE);

	return ret;
}