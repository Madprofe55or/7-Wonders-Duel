#pragma once

#include "SFML/Graphics.hpp"

#include "GameState.h"
#include "GamePlayingState.h"
#include "CardPickerState.h"

class NewAgeChoosePlayerState : public GameState
{
public:

	GamePlayingState * p_GamePlayingState;
	CardPickerState * p_CardPickerState;

	sf::RectangleShape mainArea;


	sf::Text instructions;
	sf::Text player1Text;
	sf::Text player2Text;
	sf::Text player1ChooseText;
	sf::Text player2ChooseText;

	sf::RectangleShape player1Button;
	sf::RectangleShape player2Button;

	sf::FloatRect player1ButtonRect;
	sf::FloatRect player2ButtonRect;


	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	NewAgeChoosePlayerState(Game * game, CardPickerState* cardpickerstate, GamePlayingState * gameplayingstate);


	
	Player* p_player;

	const sf::Vector2f MAIN_AREA_SIZE = { 400.0f, 400.0f };
	const sf::Vector2f BUTTON_SIZE = { 25.0f, 25.0f };

};