#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"

// Abstract class that all game states will inherit
class GameState
{
public:
	// Need pointer to the game in order to access state changes, render window, and manager functions
	Game * p_game;

	// All of these need to be defined for each state that inherits
	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;

};

#endif // GAMESTATE_H
