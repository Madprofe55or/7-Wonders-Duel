#pragma once
#include "GameState.h"
#include "GamePlayingState.h"

class CardDestroyerState : public GameState
{
public:
	
	// Need pointer to the game in order to access state changes, render window, and manager functions
	Game * p_game;
	GamePlayingState * p_gameplayingstate;
	Player * p_player;

	// Sprites
	sf::Sprite mMouseoverCard;
	vector<sf::Sprite*> mCardSprites;

	// Shapes
	sf::RectangleShape mainArea;
	vector<sf::FloatRect*> mRectCards;

	// Text
	sf::Text mMainText;

	// Integers to hold card indices
	vector<int*> mCardIndices;

	const sf::Vector2f MAIN_AREA_SIZE = { 800.0f, 450.0f };

	bool mouseover = false;

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	
	CardDestroyerState(Game * game, GamePlayingState * gameplayingstate, int cardtype);
	~CardDestroyerState();
};

