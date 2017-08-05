#include "GamePlayingState.h"
#include "CardPickerState.h"

void GamePlayingState::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->background);
	//this->game->window.draw(this->exitText);
	this->game->window.draw(this->mAge1Card1);
	this->game->window.draw(this->mAge1Card2);
	this->game->window.draw(this->mAge1Card3);
	this->game->window.draw(this->mAge1Card4);
	this->game->window.draw(this->mAge1Card5);
	this->game->window.draw(this->mAge1Card6);
	this->game->window.draw(this->mAge1Card7);
	this->game->window.draw(this->mAge1Card8);
	this->game->window.draw(this->mAge1Card9);
	this->game->window.draw(this->mAge1Card10);
	this->game->window.draw(this->mAge1Card11);
	this->game->window.draw(this->mAge1Card12);
	this->game->window.draw(this->mAge1Card13);
	this->game->window.draw(this->mAge1Card14);
	this->game->window.draw(this->mAge1Card15);
	this->game->window.draw(this->mAge1Card16);
	this->game->window.draw(this->mAge1Card17);
	this->game->window.draw(this->mAge1Card18);
	this->game->window.draw(this->mAge1Card19);
	this->game->window.draw(this->mAge1Card20);

	this->game->window.draw(this->mPlayer1GUI);
	this->game->window.draw(this->mPlayer2GUI);
	this->game->window.draw(this->player1GUIText);
	this->game->window.draw(this->player2GUIText);

	this->game->window.draw(this->mGameBoard);
	this->game->window.draw(this->mWondersDisplay);
	this->game->window.draw(this->gameBoardGUIText);
	this->game->window.draw(this->wondersDisplayText);

}


void GamePlayingState::update(const float dt)
{
}

void GamePlayingState::handleInput(Game * game)
{
	sf::Event event;
	this->game = game;
	bool poppingState = false;
	bool cardPickState = false;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				poppingState = true; // can't popstate while in loop, since loop references this and popstate deletes this
				break;
			}
			else if (event.key.code == sf::Keyboard::Space)
			{
				cardPickState = true; // we could actually push state here, but for consistency we'll just do all state changes outside loop
				break;
			}
		}
		default: break;
		}
	}
	if (poppingState == true) game->popState(); // pop state here, outside while loop
	if (cardPickState == true) game->pushState(new CardPickerState(this->game, this)); // push card picker state
}

GamePlayingState::GamePlayingState(Game * game)
{
	this->game = game;

	//exitText.setFont(game->fontManager.getRef("Menu Font"));
	//exitText.setString("Gameplaying state test: Press Escape to exit to Main Menu");
	//exitText.setPosition(0, 400);
	//exitText.setCharacterSize(50);
	//exitText.setFillColor(sf::Color::White);

	// Setting background
	this->background.setTexture(game->textureManager.getRef("GameStatePlaying Background"));



	mCurrentAge = 1;
	mAge1Card1.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card1.setPosition(mAge1Card1Loc);
	mAge1Card1.setSize(CARD_SIZE);
	mAge1Card2.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card2.setPosition(mAge1Card2Loc);
	mAge1Card2.setSize(CARD_SIZE);

	mAge1Card3.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card3.setPosition(mAge1Card3Loc);
	mAge1Card3.setSize(CARD_SIZE);
	mAge1Card4.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card4.setPosition(mAge1Card4Loc);
	mAge1Card4.setSize(CARD_SIZE);
	mAge1Card5.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card5.setPosition(mAge1Card5Loc);
	mAge1Card5.setSize(CARD_SIZE);

	mAge1Card6.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card6.setPosition(mAge1Card6Loc);
	mAge1Card6.setSize(CARD_SIZE);
	mAge1Card7.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card7.setPosition(mAge1Card7Loc);
	mAge1Card7.setSize(CARD_SIZE);
	mAge1Card8.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card8.setPosition(mAge1Card8Loc);
	mAge1Card8.setSize(CARD_SIZE);
	mAge1Card9.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card9.setPosition(mAge1Card9Loc);
	mAge1Card9.setSize(CARD_SIZE);

	mAge1Card10.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card10.setPosition(mAge1Card10Loc);
	mAge1Card10.setSize(CARD_SIZE);
	mAge1Card11.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card11.setPosition(mAge1Card11Loc);
	mAge1Card11.setSize(CARD_SIZE);
	mAge1Card12.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card12.setPosition(mAge1Card12Loc);
	mAge1Card12.setSize(CARD_SIZE);
	mAge1Card13.setFillColor(sf::Color(209, 93, 75, 180));;
	mAge1Card13.setPosition(mAge1Card13Loc);
	mAge1Card13.setSize(CARD_SIZE);
	mAge1Card14.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card14.setPosition(mAge1Card14Loc);
	mAge1Card14.setSize(CARD_SIZE);

	mAge1Card15.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card15.setPosition(mAge1Card15Loc);
	mAge1Card15.setSize(CARD_SIZE);
	mAge1Card16.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card16.setPosition(mAge1Card16Loc);
	mAge1Card16.setSize(CARD_SIZE);
	mAge1Card17.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card17.setPosition(mAge1Card17Loc);
	mAge1Card17.setSize(CARD_SIZE);
	mAge1Card18.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card18.setPosition(mAge1Card18Loc);
	mAge1Card18.setSize(CARD_SIZE);
	mAge1Card19.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card19.setPosition(mAge1Card19Loc);
	mAge1Card19.setSize(CARD_SIZE);
	mAge1Card20.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card20.setPosition(mAge1Card20Loc);
	mAge1Card20.setSize(CARD_SIZE);

	mPlayer1GUI.setPosition(0.0f, 0.0f);
	mPlayer1GUI.setSize(PLAYER_GUI_SIZE);
	mPlayer1GUI.setFillColor(sf::Color(126,126,126,126));
	mPlayer2GUI.setPosition(0.0f, 825.0f);
	mPlayer2GUI.setSize(PLAYER_GUI_SIZE);
	mPlayer2GUI.setFillColor(sf::Color(126,126,126,126));

	player1GUIText.setFont(game->fontManager.getRef("Menu Font"));
	player1GUIText.setString("Player 1 GUI");
	player1GUIText.setCharacterSize(40);
	player1GUIText.setPosition(700.0f, 10.0f);
	player1GUIText.setFillColor(sf::Color::White);

	player2GUIText.setFont(game->fontManager.getRef("Menu Font"));
	player2GUIText.setString("Player 2 GUI");
	player2GUIText.setCharacterSize(40);
	player2GUIText.setPosition(700.0f, 835.0f);
	player2GUIText.setFillColor(sf::Color::White);

	mGameBoard.setPosition(0.0f, 75.0f);
	mGameBoard.setSize(GAME_BOARD_SIZE);
	mGameBoard.setFillColor(sf::Color(41, 119, 43, 126));
	mWondersDisplay.setPosition(1450.0f, 75.0f);
	mWondersDisplay.setSize(WONDER_GUI_SIZE);
	mWondersDisplay.setFillColor(sf::Color(54, 27, 153, 126));

	gameBoardGUIText.setFont(game->fontManager.getRef("Menu Font"));
	gameBoardGUIText.setString("Game Board GUI");
	gameBoardGUIText.setCharacterSize(40);
	gameBoardGUIText.setPosition(60.0f, 500.0f);
	gameBoardGUIText.setFillColor(sf::Color::White);
	gameBoardGUIText.rotate(90);

	wondersDisplayText.setFont(game->fontManager.getRef("Menu Font"));
	wondersDisplayText.setString("Wonders GUI");
	wondersDisplayText.setCharacterSize(40);
	wondersDisplayText.setPosition(1560.0f, 500.0f);
	wondersDisplayText.setFillColor(sf::Color::White);
	wondersDisplayText.rotate(90);

}

GamePlayingState::~GamePlayingState()
{
}
