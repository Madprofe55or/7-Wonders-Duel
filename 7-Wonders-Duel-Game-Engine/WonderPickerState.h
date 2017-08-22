#ifndef WONDERPICKERSTATE_H
#define WONDERPICKERSTATE_H

#include "SFML/Graphics.hpp"

#include "GameState.h"
#include "GameStateStart.h"
#include "Card.h"

class WonderPickerState : public GameState
{
public:
	// sprites
	sf::Sprite background;
	sf::Sprite gameBoard;

	//array pointing to 8 wonder cards from setup
	Card* wonderBoard[8];

	//floatrects
	sf::FloatRect wonderFloatRect1;
	sf::FloatRect wonderFloatRect2;
	sf::FloatRect wonderFloatRect3;
	sf::FloatRect wonderFloatRect4;



	std::vector < sf::FloatRect> vectorWonderFloatRects = { wonderFloatRect1, wonderFloatRect2, wonderFloatRect3, wonderFloatRect4};

	// fonts
	sf::Font font;

	// texts, some are for testing only
	sf::Text player1GUIText;
	sf::Text player2GUIText;
	sf::Text gameBoardGUIText;
	sf::Text wondersDisplayText;


	//create the sprite objects for the tavern 
	sf::Sprite mWonderCard1;
	sf::Sprite mWonderCard2;
	sf::Sprite mWonderCard3;
	sf::Sprite mWonderCard4;
	sf::Sprite mWonderCard5;
	sf::Sprite mWonderCard6;
	sf::Sprite mWonderCard7;
	sf::Sprite mWonderCard8;
	sf::Sprite mWonderCard9;
	sf::Sprite mWonderCard10;
	sf::Sprite mWonderCard11;
	sf::Sprite mWonderCard12;

	//count picks made total 
	int numOfPickedCards = 0;
	bool pickedFourCards = false;
	

	std::vector <sf::Sprite> mWonderRects = {
		mWonderCard1, mWonderCard2,
		mWonderCard3, mWonderCard4, mWonderCard5,
		mWonderCard6, mWonderCard7, mWonderCard8, mWonderCard9,
		mWonderCard10, mWonderCard11, mWonderCard12 };



	// will be used by update() to determine which location vector to use when positioning cards
	int mCurrentAge;

	//used to count clicks to see if player 1 or player 2 chose the card...
	int clickCount = 0;

	// constants here should go into the game logic...I think...
	sf::Vector2f const WONDER_SIZE = { Seven_Wonders::WONDER_SIZE[0], Seven_Wonders::WONDER_SIZE[1] };
	sf::Vector2f const PLAYER_GUI_SIZE = { 1600,75 };
	sf::Vector2f const GAME_BOARD_SIZE = { 150, 750 };
	sf::Vector2f const WONDER_GUI_SIZE = { 150, 750 };


	//int const CARD_STRUCTURE_VERT_CENTER = 770;
	//int const CARD_VERTICAL_SPACING = 30;
	//int const CARD_HORIZONTAL_SPACING = 98;


	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	WonderPickerState(Game * game);
	~WonderPickerState();
};


#endif WONDERPICKERSTATE_H
