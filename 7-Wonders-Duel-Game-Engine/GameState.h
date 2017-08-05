#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"

class GameState
{
public:
	Game * game;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput(Game * game) = 0;

};


#endif // GAMESTATE_H
