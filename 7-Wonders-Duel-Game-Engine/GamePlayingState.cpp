#include "GamePlayingState.h"
#include "CardPickerState.h"
#include "WonderPickerState.h"

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

	p_game->window.draw(gameBoard);
	p_game->window.draw(mWondersDisplay);
	p_game->window.draw(gameBoardGUIText);
	p_game->window.draw(wondersDisplayText);
	p_game->window.draw(circleTestPawn);
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

GamePlayingState::GamePlayingState(Game * game, WonderPickerState * wonderpickerstate)
{
	p_game = game;
	p_WonderPickerState = wonderpickerstate;

	// Setting background
	background.setTexture(p_game->textureManager.getRef("GameStatePlaying Background"));

	mCurrentAge = 1;

	for (int i = 0; i < 20; ++i)
	{
		mAge1Rects[i].setPosition(Seven_Wonders::AGE_3_POSITIONS[i][0], Seven_Wonders::AGE_3_POSITIONS[i][1]);
		mAge1Rects[i].setTexture(p_game->textureManager.getRef("Card-Glassworks"));
	}

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

	gameBoard.setTexture(game->textureManager.getRef("Game Board"));
	gameBoard.setScale(0.83f, 0.83f);
	gameBoard.setPosition(10.0f, 75.0f);

	//mGameBoard.setPosition(0.0f, 75.0f);
	//mGameBoard.setSize(GAME_BOARD_SIZE);
	//mGameBoard.setFillColor(sf::Color(41, 119, 43, 126));
	mWondersDisplay.setPosition(1450.0f, 75.0f);
	mWondersDisplay.setSize(WONDER_GUI_SIZE);
	mWondersDisplay.setFillColor(sf::Color(54, 27, 153, 126));

	/*gameBoardGUIText.setFont(game->fontManager.getRef("Menu Font"));
	gameBoardGUIText.setString("Game Board GUI");
	gameBoardGUIText.setCharacterSize(40);
	gameBoardGUIText.setPosition(60.0f, 500.0f);
	gameBoardGUIText.setFillColor(sf::Color::White);
	gameBoardGUIText.rotate(90);*/

	circleTestPawn.setFillColor(sf::Color::Red);
	circleTestPawn.setRadius(25.0f);
	circleTestPawn.setScale(1.0f, 0.50f);
	circleTestPawn.setPosition(110.0f, 425.0f);

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
