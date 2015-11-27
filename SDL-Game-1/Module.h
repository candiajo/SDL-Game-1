#pragma once

#include "Application.h"
#include "Globals.h"

class Module
{
public:

	Module()
	{}

	virtual ~Module()
	{}

	virtual bool Init() 
	{
		return true; 
	}

	// TODO 3: Create a new method "Start()" that should be calling all modules just before the first frame
	virtual bool Start()
	{
		return true;
	}

	virtual update_status PreUpdate()
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status Update()
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status PostUpdate()
	{
		return UPDATE_CONTINUE;
	}

	virtual bool CleanUp() 
	{ 
		return true; 
	}
};