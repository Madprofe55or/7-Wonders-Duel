#ifndef WONDERBUILDINGSTATE_H
#define WONDERBUILDINGSTATE_H

#include "SFML\Graphics.hpp"

#include "GameState.h"
#include "GamePlayingState.h"
#include "CardPickerState.h"

class WonderBuildingState : public GameState
{
public:
	CardPickerState * p_CardPickerState;
	GamePlayingState * p_GamePlayingState;
	Player * p_player;
		
	// SFML STUFF //
	// Shapes
	sf::RectangleShape mainArea;
	sf::RectangleShape buttonWonder1;
	sf::RectangleShape buttonWonder2;
	sf::RectangleShape buttonWonder3;
	sf::RectangleShape buttonWonder4;

	// Sprites
	sf::Sprite wonderCard1;
	sf::Sprite wonderCard2;
	sf::Sprite wonderCard3;
	sf::Sprite wonderCard4;

	// Float rects for click functionality
	sf::FloatRect rectButtonWonder1;
	sf::FloatRect rectButtonWonder2;
	sf::FloatRect rectButtonWonder3;
	sf::FloatRect rectButtonWonder4;

	// Texts
	sf::Text mainText;

	//sounds
	sf::Sound buildWonderSound;

	// Vectors for sizes
	const sf::Vector2f MAIN_AREA_SIZE = { 600.0f, 750.0f };
	const sf::Vector2f BUTTON_SIZE = { 75.0f, 40.0f };

	// Bools for cards that can or can't be built
	bool canBuildWonder1 = false;
	bool canBuildWonder2 = false;
	bool canBuildWonder3 = false;
	bool canBuildWonder4 = false;

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	WonderBuildingState(Game * game, CardPickerState * cardpickerstate, GamePlayingState * gameplayingstate);
	// custom destructor not needed
	~WonderBuildingState() {};

};

#endif // WONDERBUILDINGSTATE_H

