#pragma once

#include "SFML/Graphics.hpp"

#include "GameState.h"
#include "GamePlayingState.h"


class DiscardedPTPickerState : public GameState
{
public:

	// Need pointer to the game in order to access state changes, render window, and manager functions
	Game * p_game;
	GamePlayingState * p_gameplayingstate;
	Player * p_player;

	// Sprites
	sf::Sprite mMouseoverPT; // likely not needed
	sf::Sprite mPT1;
	sf::Sprite mPT2;
	sf::Sprite mPT3;
	vector<sf::Sprite> mPTSprites = { mPT1, mPT2, mPT3 };

	// Shapes
	sf::RectangleShape mainArea;

	// Text
	sf::Text mMainText;

	// Float rects for mousing over
	sf::FloatRect mPTRect1;
	sf::FloatRect mPTRect2;
	sf::FloatRect mPTRect3;
	vector<sf::FloatRect> mPTRects = { mPTRect1, mPTRect2, mPTRect3 };

	const sf::Vector2f MAIN_AREA_SIZE = { 700.0f, 300.0f };


	bool mouseover = false;

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();


	DiscardedPTPickerState(Game * game, GamePlayingState * gameplayingstate);
	~DiscardedPTPickerState() {}
};

