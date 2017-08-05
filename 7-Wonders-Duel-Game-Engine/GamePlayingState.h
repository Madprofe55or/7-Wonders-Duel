#ifndef GAMEPLAYINGSTATE_H
#define GAMEPLAYINGSTATE_H

#include "SFML\Graphics.hpp"

#include "GameState.h"


class GamePlayingState : public GameState
{
public:
	sf::Sprite background;
	sf::Font font;

	sf::Text exitText;

	std::vector <sf::Vector2i> mAge1CardLocations;
	std::vector <sf::Vector2i> mAge2CardLocations;
	std::vector <sf::Vector2i> mAge3CardLocations;

	// vectors for each card location
	sf::Vector2f mAge1Card1Loc = { 635, 150 };
	sf::Vector2f mAge1Card2Loc = { 785, 150 };

	sf::Vector2f mAge1Card3Loc = { 560, 263 };
	sf::Vector2f mAge1Card4Loc = { 710, 263 };
	sf::Vector2f mAge1Card5Loc = { 860, 263 };

	sf::Vector2f mAge1Card6Loc = { 485, 376 };
	sf::Vector2f mAge1Card7Loc = { 635, 376 };
	sf::Vector2f mAge1Card8Loc = { 785, 376 };
	sf::Vector2f mAge1Card9Loc = { 935, 376 };

	sf::Vector2f mAge1Card10Loc = { 410, 489 };
	sf::Vector2f mAge1Card11Loc = { 560, 489 };
	sf::Vector2f mAge1Card12Loc = { 710, 489 };
	sf::Vector2f mAge1Card13Loc = { 860, 489 };
	sf::Vector2f mAge1Card14Loc = { 1010, 489 };

	sf::Vector2f mAge1Card15Loc = { 335, 602 };
	sf::Vector2f mAge1Card16Loc = { 485, 602 };
	sf::Vector2f mAge1Card17Loc = { 635, 602 };
	sf::Vector2f mAge1Card18Loc = { 785, 602 };
	sf::Vector2f mAge1Card19Loc = { 935, 602 };
	sf::Vector2f mAge1Card20Loc = { 1085, 602 };



	// test rectangles for card structure
	sf::RectangleShape mAge1Card1;
	sf::RectangleShape mAge1Card2;
	sf::RectangleShape mAge1Card3;
	sf::RectangleShape mAge1Card4;
	sf::RectangleShape mAge1Card5;
	sf::RectangleShape mAge1Card6;
	sf::RectangleShape mAge1Card7;
	sf::RectangleShape mAge1Card8;
	sf::RectangleShape mAge1Card9;
	sf::RectangleShape mAge1Card10;
	sf::RectangleShape mAge1Card11;
	sf::RectangleShape mAge1Card12;
	sf::RectangleShape mAge1Card13;
	sf::RectangleShape mAge1Card14;
	sf::RectangleShape mAge1Card15;
	sf::RectangleShape mAge1Card16;
	sf::RectangleShape mAge1Card17;
	sf::RectangleShape mAge1Card18;
	sf::RectangleShape mAge1Card19;
	sf::RectangleShape mAge1Card20;

	int mCurrentAge;
	sf::Vector2f const CARD_SIZE = { 120, 186 };
	int const CARD_STRUCTURE_VERT_CENTER = 770;
	int const CARD_VERTICAL_SPACING = 30;
	int const CARD_HORIZONTAL_SPACING = 98;


	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput(Game * game);
	
	GamePlayingState(Game * game);
	~GamePlayingState();
};


#endif // GAMEPLAYINGSTATE_H

