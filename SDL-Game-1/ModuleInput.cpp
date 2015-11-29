#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput()
{}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::Update()
{
	//SDL_PumpEvents();
	
	// TODO 1: Make the application properly close when ESC is pressed (do not use exit())

	// Homework: Make the application close up when pressing “X” button of the window
	SDL_Event Events;

	while (SDL_PollEvent(&Events))
	{
		// check of ESC key ------------------------------------------------------------------------
		keyboard = SDL_GetKeyboardState(NULL);
		
		if (keyboard[SDL_SCANCODE_ESCAPE]) 
		{
			return UPDATE_STOP;
		}
		if (keyboard[SDL_SCANCODE_SPACE])
		{
			App->audio->PlaySoundfx();
			return UPDATE_CONTINUE;
		}

		// check for closing window by pressing X with the mouse -----------------------------------

		if (Events.type == SDL_QUIT) return UPDATE_STOP;
	}


	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}