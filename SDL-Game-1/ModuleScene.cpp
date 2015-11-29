#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"


ModuleScene::ModuleScene()
{}

ModuleScene::~ModuleScene()
{}

bool ModuleScene::Init()
{
	texture = App->textures->LoadMap(SPRITE_NAME, SPRITE_FILE);

	if (texture == NULL)
	{
		return false;
	}
	else if (App->audio->LoadMusic(MUSIC_FILE) == false)
	{
		return false;
	}
	else if (App->audio->LoadSoundfx(SOUNDFX_FILE) == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ModuleScene::Start()
{
	App->audio->PlayMusic();

	texture = App->textures->GetTextureMap(SPRITE_NAME);
	
	if (texture == NULL)
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