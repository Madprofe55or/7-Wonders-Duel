#ifndef GAMEPLAYINGSTATE_H
#define GAMEPLAYINGSTATE_H

#include "SFML\Graphics.hpp"

#include "GameState.h"


class GamePlayingState : public GameState
{
public:
	// sprites
	sf::Sprite background;
	sf::Sprite gameBoard;

	// shapes (usually just for testing)
	sf::CircleShape circleTestPawn;
	
	// fonts
	sf::Font font;

	// texts, some are for testing only
	sf::Text player1GUIText;
	sf::Text player2GUIText;
	sf::Text gameBoardGUIText;
	sf::Text wondersDisplayText;



	sf::Sprite mAge1Card1;
	sf::Sprite mAge1Card2;
	sf::Sprite mAge1Card3;
	sf::Sprite mAge1Card4;
	sf::Sprite mAge1Card5;
	sf::Sprite mAge1Card6;
	sf::Sprite mAge1Card7;
	sf::Sprite mAge1Card8;
	sf::Sprite mAge1Card9;
	sf::Sprite mAge1Card10;
	sf::Sprite mAge1Card11;
	sf::Sprite mAge1Card12;
	sf::Sprite mAge1Card13;
	sf::Sprite mAge1Card14;
	sf::Sprite mAge1Card15;
	sf::Sprite mAge1Card16;
	sf::Sprite mAge1Card17;
	sf::Sprite mAge1Card18;
	sf::Sprite mAge1Card19;
	sf::Sprite mAge1Card20;

	std::vector <sf::Sprite> mAge1Rects = {
		mAge1Card1, mAge1Card2,
		mAge1Card3, mAge1Card4, mAge1Card5,
		mAge1Card6, mAge1Card7, mAge1Card8, mAge1Card9,
		mAge1Card10, mAge1Card11, mAge1Card12, mAge1Card13, mAge1Card14,
		mAge1Card15, mAge1Card16, mAge1Card17, mAge1Card18, mAge1Card19, mAge1Card20 };

	// placeholder gui stuff
	sf::RectangleShape mPlayer1GUI;
	sf::RectangleShape mPlayer2GUI;
	sf::RectangleShape mWondersDisplay;
	sf::RectangleShape mGameBoard;

	// will be used by update() to determine which location vector to use when positioning cards
	int mCurrentAge;

	// constants here should go into the game logic...I think...
	sf::Vector2f const CARD_SIZE = { Seven_Wonders::CARD_SIZE[0], Seven_Wonders::CARD_SIZE[1] };
	sf::Vector2f const PLAYER_GUI_SIZE = { 1600,75 };
	sf::Vector2f const GAME_BOARD_SIZE = { 150, 750 };
	sf::Vector2f const WONDER_GUI_SIZE = { 150, 750 };


	//int const CARD_STRUCTURE_VERT_CENTER = 770;
	//int const CARD_VERTICAL_SPACING = 30;
	//int const CARD_HORIZONTAL_SPACING = 98;


	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	
	GamePlayingState(Game * game);
	~GamePlayingState();
};


#endif // GAMEPLAYINGSTATE_H

