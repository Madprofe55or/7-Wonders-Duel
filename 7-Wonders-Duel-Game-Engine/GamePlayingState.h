#ifndef GAMEPLAYINGSTATE_H
#define GAMEPLAYINGSTATE_H

#include "SFML\Graphics.hpp"

#include "GameState.h"


class GamePlayingState : public GameState
{
public:
	// sprites
	sf::Sprite background;
	
	// fonts
	sf::Font font;

	// texts, some are for testing only
	sf::Text exitText;
	sf::Text player1GUIText;
	sf::Text player2GUIText;
	sf::Text gameBoardGUIText;
	sf::Text wondersDisplayText;

	// vectors to store all positions, not implemented yet
	std::vector <sf::Vector2i> mAge1CardLocations;
	std::vector <sf::Vector2i> mAge2CardLocations;
	std::vector <sf::Vector2i> mAge3CardLocations;

	// vectors for each card location, will all be refactored and controlled mathematically based on card size and spacing constants
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

	// test rectangles for card structure, will all be refactored
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

	// placeholder gui stuff
	sf::RectangleShape mPlayer1GUI;
	sf::RectangleShape mPlayer2GUI;
	sf::RectangleShape mWondersDisplay;
	sf::RectangleShape mGameBoard;

	// will be used by update() to determine which location vector to use when positioning cards
	int mCurrentAge;

	// constants here should go into the game logic...I think...
	sf::Vector2f const CARD_SIZE = { 120, 186 };
	sf::Vector2f const PLAYER_GUI_SIZE = { 1600,75 };
	sf::Vector2f const GAME_BOARD_SIZE = { 150, 750 };
	sf::Vector2f const WONDER_GUI_SIZE = { 150, 750 };
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

