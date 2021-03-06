#ifndef PROGRESSTOKENBUILDINGSTATE_H
#define PROGRESSTOKENBUILDINGSTATE_H

#include "SFML\Graphics.hpp"

#include "GameState.h"
#include "GamePlayingState.h"
#include "CardPickerState.h"
#include "Player.h"

class ProgressTokenBuildingState : public GameState
{
public:

	GamePlayingState * p_GamePlayingState;
	Player * p_player;

	//ProgressTokenSprites
	sf::Sprite progressToken1;
	sf::Sprite progressToken2;
	sf::Sprite progressToken3;
	sf::Sprite progressToken4;
	sf::Sprite progressToken5;

	std::vector <sf::Sprite> spriteProgressTokens = { progressToken1, progressToken2, progressToken3, progressToken4, progressToken5 };

	//Text
	sf::Text progressTokenText;


	//bool statements if 2 congruent science symbols are owned by a player
	bool canBuildToken1 = false;
	bool canBuildToken2 = false;
	bool canBuildToken3 = false;
	bool canBuildToken4 = false;
	bool canBuildToken5 = false;


	// SFML STUFF //
	// Shapes
	sf::RectangleShape mainArea;
	sf::RectangleShape buttonToken1;
	sf::RectangleShape buttonToken2;
	sf::RectangleShape buttonToken3;
	sf::RectangleShape buttonToken4;
	sf::RectangleShape buttonToken5;

	std::vector <sf::RectangleShape> buttonTokens = {buttonToken1, buttonToken2, buttonToken3, buttonToken4, buttonToken5};

	// Float rects for click functionality
	sf::FloatRect rectButtonToken1;
	sf::FloatRect rectButtonToken2;
	sf::FloatRect rectButtonToken3;
	sf::FloatRect rectButtonToken4;
	sf::FloatRect rectButtonToken5;

	sf::Text buttonTokenText1;
	sf::Text buttonTokenText2;
	sf::Text buttonTokenText3;
	sf::Text buttonTokenText4;
	sf::Text buttonTokenText5;

	//sound
	sf::Sound progressTokenSound;

	std::vector <sf::Text> buttonTokenTexts = { buttonTokenText1, buttonTokenText2, buttonTokenText3, buttonTokenText4, buttonTokenText5 };
	// Vectors for sizes
	const sf::Vector2f MAIN_AREA_SIZE = { 600.0f, 750.0f };
	const sf::Vector2f BUTTON_SIZE = { 175.0f, 60.0f };

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	ProgressTokenBuildingState(Game * game, GamePlayingState * gameplayingstate);
	// custom destructor not needed
	~ProgressTokenBuildingState();
};


#endif