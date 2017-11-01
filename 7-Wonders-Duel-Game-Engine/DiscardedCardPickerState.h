#pragma once
#include "GameState.h"
#include "GamePlayingState.h"


class DiscardedCardPickerState : public GameState
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

	// Mouseover card positions
	const sf::Vector2f OFFSCREEN = { -400.0f, -400.0f };
	const sf::Vector2f DISPLAY[2];

	bool mouseover = false;

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	
	
	DiscardedCardPickerState(Game * game, GamePlayingState * gameplayingstate);
	~DiscardedCardPickerState() {}
};

