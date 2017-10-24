#pragma once


#include "SFML/Graphics.hpp"

#include "GameState.h"
#include "GamePlayingState.h"

class EndGameState : public GameState
{
public:

	sf::Text player1MilitaryvictoryBanner;
	sf::Text player2MilitaryvictoryBanner;
	sf::Text player1SciencevictoryBanner;
	sf::Text player2SciencevictoryBanner;
	sf::Text player1CivilianvictoryBanner;
	sf::Text player2CivilianvictoryBanner;
	sf::Text playAgain;
	sf::Text exit;

	sf::Sprite militaryVictoryBackground;
	sf::Sprite scienceVictoryBackground;
	sf::Sprite civilianVictoryBackground;

	//sf::Sprite background;

	GamePlayingState * p_GamePlayingState;

	EndGameState(Game *game, GamePlayingState *gamePlayingState);
	~EndGameState();

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

};