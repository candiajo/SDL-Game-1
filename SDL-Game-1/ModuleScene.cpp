#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"


ModuleScene::ModuleScene()
{}

ModuleScene::~ModuleScene()
{}

bool ModuleScene::Init()
{
	bool loadOk = false;

	if (App->textures->Load(SPRITE_FILE))
	{
		texture = App->textures->getTexture();
		loadOk = true;
	}

	if (!loadOk || texture == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

update_status ModuleScene::Update()
{
	bool blitOk;

	blitOk = App->renderer->Blit(texture, 0, 0, NULL);

	if (blitOk)
	{
		return UPDATE_CONTINUE;
	}
	else
	{
		return UPDATE_ERROR;
	}
}