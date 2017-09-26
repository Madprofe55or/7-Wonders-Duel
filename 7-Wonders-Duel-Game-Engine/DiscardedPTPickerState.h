#pragma once
#include "GameState.h"


class DiscardedPTPickerState : public GameState
{
public:
	
	// Need pointer to the game in order to access state changes, render window, and manager functions
	Game * p_game;

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	
	
	DiscardedPTPickerState();
	~DiscardedPTPickerState();
};

