#include "GamePlayingState.h"
#include "CardPickerState.h"

void GamePlayingState::draw(const float dt)
{
	p_game->window.draw(background);

	for (int i = 0; i < 20; ++i)
	{
		p_game->window.draw(mAge1Rects[i]);
	}

	p_game->window.draw(mPlayer1GUI);
	p_game->window.draw(mPlayer2GUI);
	p_game->window.draw(player1GUIText);
	p_game->window.draw(player2GUIText);

	p_game->window.draw(mGameBoard);
	p_game->window.draw(mWondersDisplay);
	p_game->window.draw(gameBoardGUIText);
	p_game->window.draw(wondersDisplayText);

}


void GamePlayingState::update(const float dt)
{
}

void GamePlayingState::handleInput()
{
	sf::Event event;
	bool poppingState = false;
	bool cardPickState = false;

	while (p_game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			p_game->window.close();
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
	if (poppingState == true) p_game->popState(); // pop state here, outside while loop
	if (cardPickState == true) p_game->pushState(new CardPickerState(p_game, this)); // push card picker state
}

GamePlayingState::GamePlayingState(Game * game)
{
	p_game = game;

	// Setting background
	background.setTexture(p_game->textureManager.getRef("GameStatePlaying Background"));

	mCurrentAge = 1;

	for (int i = 0; i < 20; ++i)
	{
		mAge1Rects[i].setPosition(Seven_Wonders::AGE_3_POSITIONS[i][0], Seven_Wonders::AGE_3_POSITIONS[i][1]);
		mAge1Rects[i].setTexture(p_game->textureManager.getRef("Card-Glassworks"));


		/*if (i == 0 || i == 1 || i == 5 || i == 6 || i == 7 || i == 8 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 19)
		{
			mAge1Rects[i].setFillColor(sf::Color(34, 100, 170, 180));
		}
		else
		{
			mAge1Rects[i].setFillColor(sf::Color(209, 93, 75, 180));
		}*/

	}


	/*
	mAge1Card1.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card1.setPosition(Seven_Wonders::AGE_1_POSITIONS[0][0], Seven_Wonders::AGE_1_POSITIONS[0][1]);
	mAge1Card1.setSize(CARD_SIZE);
	mAge1Card2.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card2.setPosition(Seven_Wonders::AGE_1_POSITIONS[1][0], Seven_Wonders::AGE_1_POSITIONS[1][1]);
	mAge1Card2.setSize(CARD_SIZE);

	mAge1Card3.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card3.setPosition(Seven_Wonders::AGE_1_POSITIONS[2][0], Seven_Wonders::AGE_1_POSITIONS[2][1]);
	mAge1Card3.setSize(CARD_SIZE);
	mAge1Card4.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card4.setPosition(Seven_Wonders::AGE_1_POSITIONS[3][0], Seven_Wonders::AGE_1_POSITIONS[3][1]);
	mAge1Card4.setSize(CARD_SIZE);
	mAge1Card5.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card5.setPosition(Seven_Wonders::AGE_1_POSITIONS[4][0], Seven_Wonders::AGE_1_POSITIONS[4][1]);
	mAge1Card5.setSize(CARD_SIZE);

	mAge1Card6.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card6.setPosition(Seven_Wonders::AGE_1_POSITIONS[5][0], Seven_Wonders::AGE_1_POSITIONS[5][1]);
	mAge1Card6.setSize(CARD_SIZE);
	mAge1Card7.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card7.setPosition(Seven_Wonders::AGE_1_POSITIONS[6][0], Seven_Wonders::AGE_1_POSITIONS[6][1]);
	mAge1Card7.setSize(CARD_SIZE);
	mAge1Card8.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card8.setPosition(Seven_Wonders::AGE_1_POSITIONS[7][0], Seven_Wonders::AGE_1_POSITIONS[7][1]);
	mAge1Card8.setSize(CARD_SIZE);
	mAge1Card9.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card9.setPosition(Seven_Wonders::AGE_1_POSITIONS[8][0], Seven_Wonders::AGE_1_POSITIONS[8][1]);
	mAge1Card9.setSize(CARD_SIZE);

	mAge1Card10.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card10.setPosition(Seven_Wonders::AGE_1_POSITIONS[9][0], Seven_Wonders::AGE_1_POSITIONS[9][1]);
	mAge1Card10.setSize(CARD_SIZE);
	mAge1Card11.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card11.setPosition(Seven_Wonders::AGE_1_POSITIONS[10][0], Seven_Wonders::AGE_1_POSITIONS[10][1]);
	mAge1Card11.setSize(CARD_SIZE);
	mAge1Card12.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card12.setPosition(Seven_Wonders::AGE_1_POSITIONS[11][0], Seven_Wonders::AGE_1_POSITIONS[11][1]);
	mAge1Card12.setSize(CARD_SIZE);
	mAge1Card13.setFillColor(sf::Color(209, 93, 75, 180));;
	mAge1Card13.setPosition(Seven_Wonders::AGE_1_POSITIONS[12][0], Seven_Wonders::AGE_1_POSITIONS[12][1]);
	mAge1Card13.setSize(CARD_SIZE);
	mAge1Card14.setFillColor(sf::Color(209, 93, 75, 180));
	mAge1Card14.setPosition(Seven_Wonders::AGE_1_POSITIONS[13][0], Seven_Wonders::AGE_1_POSITIONS[13][1]);
	mAge1Card14.setSize(CARD_SIZE);

	mAge1Card15.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card15.setPosition(Seven_Wonders::AGE_1_POSITIONS[14][0], Seven_Wonders::AGE_1_POSITIONS[14][1]);
	mAge1Card15.setSize(CARD_SIZE);
	mAge1Card16.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card16.setPosition(Seven_Wonders::AGE_1_POSITIONS[15][0], Seven_Wonders::AGE_1_POSITIONS[15][1]);
	mAge1Card16.setSize(CARD_SIZE);
	mAge1Card17.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card17.setPosition(Seven_Wonders::AGE_1_POSITIONS[16][0], Seven_Wonders::AGE_1_POSITIONS[16][1]);
	mAge1Card17.setSize(CARD_SIZE);
	mAge1Card18.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card18.setPosition(Seven_Wonders::AGE_1_POSITIONS[17][0], Seven_Wonders::AGE_1_POSITIONS[17][1]);
	mAge1Card18.setSize(CARD_SIZE);
	mAge1Card19.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card19.setPosition(Seven_Wonders::AGE_1_POSITIONS[18][0], Seven_Wonders::AGE_1_POSITIONS[18][1]);
	mAge1Card19.setSize(CARD_SIZE);
	mAge1Card20.setFillColor(sf::Color(34, 100, 170, 180));
	mAge1Card20.setPosition(Seven_Wonders::AGE_1_POSITIONS[19][0], Seven_Wonders::AGE_1_POSITIONS[19][1]);
	mAge1Card20.setSize(CARD_SIZE);

	*/

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
