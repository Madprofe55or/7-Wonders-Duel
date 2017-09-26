#pragma once
#include "GameState.h"
#include "GamePlayingState.h"

class CardDestroyerState : public GameState
{
public:
	
	// Need pointer to the game in order to access state changes, render window, and manager functions
	Game * p_game;
	GamePlayingState * p_gameplayingstate;


	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	
	CardDestroyerState(Game * game, GamePlayingState * gameplayingstate, int cardtype);
	~CardDestroyerState();
};

