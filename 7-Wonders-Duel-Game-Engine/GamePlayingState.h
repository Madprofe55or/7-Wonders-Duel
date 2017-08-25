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
	
	sf::Vector2f rectPickingCardSize = { 1600,900 };
	sf::RectangleShape rectPickingCard;
	
	// fonts
	sf::Font font;

	// texts, some are for testing only
	sf::Text player1GUIText;
	sf::Text player2GUIText;
	sf::Text gameBoardGUIText;
	sf::Text wondersDisplayText;
	sf::Text player1Turn;
	sf::Text player2Turn;
	sf::Text player1Coins;
	sf::Text player1Wood;
	sf::Text player1Stone;
	sf::Text player1Clay;
	sf::Text player1Papyrus;
	sf::Text player1Glass;
	sf::Text player2Coins;
	sf::Text player2Wood;
	sf::Text player2Stone;
	sf::Text player2Clay;
	sf::Text player2Papyrus;
	sf::Text player2Glass;

	// Shapes
	sf::RectangleShape player1City;
	sf::RectangleShape player2City;

	// Sprite
	sf::Sprite mConflictPawn;
	sf::Sprite mCard1;
	sf::Sprite mCard2;
	sf::Sprite mCard3;
	sf::Sprite mCard4;
	sf::Sprite mCard5;
	sf::Sprite mCard6;
	sf::Sprite mCard7;
	sf::Sprite mCard8;
	sf::Sprite mCard9;
	sf::Sprite mCard10;
	sf::Sprite mCard11;
	sf::Sprite mCard12;
	sf::Sprite mCard13;
	sf::Sprite mCard14;
	sf::Sprite mCard15;
	sf::Sprite mCard16;
	sf::Sprite mCard17;
	sf::Sprite mCard18;
	sf::Sprite mCard19;
	sf::Sprite mCard20;
	sf::Sprite mPlayer1Wonder1;
	sf::Sprite mPlayer1Wonder2;
	sf::Sprite mPlayer1Wonder3;
	sf::Sprite mPlayer1Wonder4;	
	sf::Sprite mPlayer2Wonder1;
	sf::Sprite mPlayer2Wonder2;
	sf::Sprite mPlayer2Wonder3;
	sf::Sprite mPlayer2Wonder4;

	sf::Sprite mCardSprites[20] = {
		mCard1, mCard2,
		mCard3, mCard4, mCard5,
		mCard6, mCard7, mCard8, mCard9,
		mCard10, mCard11, mCard12, mCard13, mCard14,
		mCard15, mCard16, mCard17, mCard18, mCard19, mCard20 };

	sf::Sprite mWonderSpritesP1[4] = { mPlayer1Wonder1, mPlayer1Wonder2, mPlayer1Wonder3, mPlayer1Wonder4 };
	sf::Sprite mWonderSpritesP2[4] = { mPlayer2Wonder1, mPlayer2Wonder2, mPlayer2Wonder3, mPlayer2Wonder4 };

	sf::Sprite mouseoverCard;

	sf::FloatRect rectPlayer1Wonder1;
	sf::FloatRect rectPlayer1Wonder2;
	sf::FloatRect rectPlayer1Wonder3;
	sf::FloatRect rectPlayer1Wonder4;
	sf::FloatRect rectPlayer2Wonder1;
	sf::FloatRect rectPlayer2Wonder2;
	sf::FloatRect rectPlayer2Wonder3;
	sf::FloatRect rectPlayer2Wonder4;

	sf::FloatRect mRectWondersP1[4] = { rectPlayer1Wonder1, rectPlayer1Wonder2, rectPlayer1Wonder3, rectPlayer1Wonder4 };
	sf::FloatRect mRectWondersP2[4] = { rectPlayer2Wonder1, rectPlayer2Wonder2, rectPlayer2Wonder3, rectPlayer2Wonder4 };


	// placeholder gui stuff
	sf::RectangleShape mPlayer1GUI;
	sf::RectangleShape mPlayer2GUI;
	sf::RectangleShape mWondersDisplay;
	sf::RectangleShape mGameBoard;

	// constants here should go into the game logic...I think...
	sf::Vector2f const CARD_SIZE = { Seven_Wonders::CARD_SIZE[0], Seven_Wonders::CARD_SIZE[1] };
	sf::Vector2f const PLAYER_GUI_SIZE = { 1600, 75 };
	sf::Vector2f const GAME_BOARD_SIZE = { 150, 750 };
	sf::Vector2f const WONDER_GUI_SIZE = { 150, 750 };
	sf::Vector2f const WONDER_CARD_SIZE = { 139, 90 };


	//int const CARD_STRUCTURE_VERT_CENTER = 770;
	//int const CARD_VERTICAL_SPACING = 30;
	//int const CARD_HORIZONTAL_SPACING = 98;

	int clickedCardIndex;
	int emptyCount;
	bool mouseover;

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	
	GamePlayingState(Game * game);
	void resetSprites();
	~GamePlayingState();
};


#endif // GAMEPLAYINGSTATE_H

