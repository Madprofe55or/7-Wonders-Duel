#include "CardDestroyerState.h"



void CardDestroyerState::draw(const float dt)
{
	// need to draw the state underneath on the stack
	p_gameplayingstate->draw(dt);
}

void CardDestroyerState::update(const float dt)
{
}

void CardDestroyerState::handleInput()
{
}

CardDestroyerState::CardDestroyerState(Game * game, GamePlayingState * gameplayingstate, int cardtype)
{
	p_game = game;
	p_gameplayingstate = gameplayingstate;
}


CardDestroyerState::~CardDestroyerState()
{
}
