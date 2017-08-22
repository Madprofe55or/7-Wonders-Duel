#include "GamePlayingState.h"
#include "CardPickerState.h"
#include "ViewingCityState.h"

void GamePlayingState::draw(const float dt)
{
	p_game->window.draw(background);

	for (int i = 0; i < 20; ++i)
	{
		if (p_game->world.board[i] != nullptr)
		{
			if (p_game->world.board[i]->getFaceup() == true)
			{
				mCardSprites[i].setTexture(p_game->textureManager.getRef(p_game->world.board[i]->getName()));
			}

			p_game->window.draw(mCardSprites[i]);
		}
	}

	if (p_game->world.currentPlayer == &p_game->world.player1)
	{
		mPlayer1GUI.setFillColor(sf::Color(51, 204, 51, 126));
		mPlayer2GUI.setFillColor(sf::Color(126, 126, 126, 126));
	}
	else if (p_game->world.currentPlayer == &p_game->world.player2)
	{
		mPlayer2GUI.setFillColor(sf::Color(51, 204, 51, 126));
		mPlayer1GUI.setFillColor(sf::Color(126, 126, 126, 126));
	}

	player1Coins.setString("Coins:  " + to_string(p_game->world.player1.getCoins()));
	player1Wood.setString("Wood:  " + to_string(p_game->world.player1.getWood()));
	player1Stone.setString("Stone:  " + to_string(p_game->world.player1.getStone()));
	player1Clay.setString("Clay:  " + to_string(p_game->world.player1.getClay()));
	player1Papyrus.setString("Papyrus:  " + to_string(p_game->world.player1.getPapyrus()));
	player1Glass.setString("Glass:  " + to_string(p_game->world.player1.getGlass()));

	player2Coins.setString("Coins:  " + to_string(p_game->world.player2.getCoins()));
	player2Wood.setString("Wood:  " + to_string(p_game->world.player2.getWood()));
	player2Stone.setString("Stone:  " + to_string(p_game->world.player2.getStone()));
	player2Clay.setString("Clay:  " + to_string(p_game->world.player2.getClay()));
	player2Papyrus.setString("Papyrus:  " + to_string(p_game->world.player2.getPapyrus()));
	player2Glass.setString("Glass:  " + to_string(p_game->world.player2.getGlass()));

	p_game->window.draw(mPlayer1GUI);
	p_game->window.draw(mPlayer2GUI);
	p_game->window.draw(player1GUIText);
	p_game->window.draw(player2GUIText);

	p_game->window.draw(gameBoard);
	p_game->window.draw(mWondersDisplay);
	p_game->window.draw(gameBoardGUIText);
	p_game->window.draw(wondersDisplayText);
	p_game->window.draw(circleTestPawn);

	p_game->window.draw(player1Coins);
	p_game->window.draw(player1Wood);
	p_game->window.draw(player1Stone);
	p_game->window.draw(player1Clay);
	p_game->window.draw(player1Papyrus);
	p_game->window.draw(player1Glass);

	p_game->window.draw(player2Coins);
	p_game->window.draw(player2Wood);
	p_game->window.draw(player2Stone);
	p_game->window.draw(player2Clay);
	p_game->window.draw(player2Papyrus);
	p_game->window.draw(player2Glass);
}

void GamePlayingState::update(const float dt)
{
}

void GamePlayingState::handleInput()
{
	sf::Event event;
	bool poppingState = false;
	bool cardPickState = false;
	bool viewCityState = false;
	Card ** clickedCard;

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
				p_game->world.ExitGame();
				break;
			}
			if (event.key.code == sf::Keyboard::Space)
			{
				viewCityState = true;
			}
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				for (int i = 0; i < 20; i++)
				{
					if (p_game->inputManager.isObjectClicked(mCardSprites[i], event.mouseButton.button, p_game->window) == true &&
						p_game->world.board[i]->getFaceup() == true)
					{						
						clickedCard = &p_game->world.board[i];
						clickedCardIndex = i;
						cardPickState = true;
					}
				}
			}
		}
		default: break;
		}
	}
	if (poppingState == true) p_game->popState(); // pop state here, outside while loop
	if (cardPickState == true)
	{
		rectPickingCard.setFillColor(sf::Color(0,0,0,126));
		rectPickingCard.setPosition(0, 0);
		rectPickingCard.setSize(rectPickingCardSize);
		p_game->pushState(new CardPickerState(p_game, this, *clickedCard)); // push card picker state
	}
	if (viewCityState == true)
	{
		rectPickingCard.setFillColor(sf::Color(0, 0, 0, 126));
		rectPickingCard.setPosition(0, 0);
		rectPickingCard.setSize(rectPickingCardSize);
		p_game->pushState(new ViewingCityState(p_game, this));
	}
}

GamePlayingState::GamePlayingState(Game * game)
{
	p_game = game;
	emptyCount = 0;

	// Setting background
	background.setTexture(p_game->textureManager.getRef("GameStatePlaying Background"));

		for (int i = 0; i < 20; ++i)
		{
			if (p_game->world.getAge() == 1)
			{
				mCardSprites[i].setPosition(p_game->world.board[i]->getPosition()[0], p_game->world.board[i]->getPosition()[1]);

				mCardSprites[i].setScale(0.5f, 0.5f);

				if (i == 2 || i == 3 || i == 4 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13)
				{
					mCardSprites[i].setTexture(p_game->textureManager.getRef("Age 1 Back"));
					//mCardSprites[i].setColor(sf::Color(255, 255, 255, 200)); // for transparency, if desired
				}
				else
				{
					mCardSprites[i].setTexture(p_game->textureManager.getRef(p_game->world.board[i]->getName()));
				}
			}

			if (p_game->world.getAge() == 2)
			{
				mCardSprites[i].setPosition(p_game->world.board[i]->getPosition()[0], p_game->world.board[i]->getPosition()[1]);

				mCardSprites[i].setScale(0.5f, 0.5f);

				if (i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 15 || i == 16 || i == 17)
				{
					mCardSprites[i].setTexture(p_game->textureManager.getRef("Age 2 Back"));
				}
				else
				{
					mCardSprites[i].setTexture(p_game->textureManager.getRef(p_game->world.board[i]->getName()));
				}
			}
			if (p_game->world.getAge() == 3)
			{
				mCardSprites[i].setPosition(p_game->world.board[i]->getPosition()[0], p_game->world.board[i]->getPosition()[1]);

				mCardSprites[i].setScale(0.5f, 0.5f);

				if (i == 2 || i == 3 || i == 4 || i == 9 || i == 10 || i == 15 || i == 16 || i == 17)
				{
					if (p_game->world.board[i]->getAge() == AGE_GUILD)
					{
						mCardSprites[i].setTexture(p_game->textureManager.getRef("Guild Back"));
					}
					else
					{
						mCardSprites[i].setTexture(p_game->textureManager.getRef("Age 3 Back"));
					}
				}
				else
				{
					mCardSprites[i].setTexture(p_game->textureManager.getRef(p_game->world.board[i]->getName()));
				}
			}

	}

	mPlayer1GUI.setPosition(0.0f, 0.0f);
	mPlayer1GUI.setSize(PLAYER_GUI_SIZE);
	mPlayer1GUI.setFillColor(sf::Color(126,126,126,126));
	mPlayer2GUI.setPosition(0.0f, 825.0f);
	mPlayer2GUI.setSize(PLAYER_GUI_SIZE);
	mPlayer2GUI.setFillColor(sf::Color(126,126,126,126));

	player1GUIText.setFont(game->fontManager.getRef("Menu Font"));
	player1GUIText.setString("Player 1");
	player1GUIText.setCharacterSize(40);
	player1GUIText.setPosition(720.0f, 10.0f);
	player1GUIText.setFillColor(sf::Color::White);

	player2GUIText.setFont(game->fontManager.getRef("Menu Font"));
	player2GUIText.setString("Player 2");
	player2GUIText.setCharacterSize(40);
	player2GUIText.setPosition(720.0f, 835.0f);
	player2GUIText.setFillColor(sf::Color::White);

	gameBoard.setTexture(game->textureManager.getRef("Game Board"));
	gameBoard.setScale(0.83f, 0.83f);
	gameBoard.setPosition(10.0f, 75.0f);

	mWondersDisplay.setPosition(1450.0f, 75.0f);
	mWondersDisplay.setSize(WONDER_GUI_SIZE);
	mWondersDisplay.setFillColor(sf::Color(54, 27, 153, 126));

	circleTestPawn.setFillColor(sf::Color::Red);
	circleTestPawn.setRadius(25.0f);
	circleTestPawn.setScale(1.0f, 0.50f);
	circleTestPawn.setPosition(108.0f, 427.0f);

	wondersDisplayText.setFont(game->fontManager.getRef("Menu Font"));
	wondersDisplayText.setString("Wonders GUI");
	wondersDisplayText.setCharacterSize(40);
	wondersDisplayText.setPosition(1560.0f, 500.0f);
	wondersDisplayText.setFillColor(sf::Color::White);
	wondersDisplayText.rotate(90);

	player1Turn.setFont(game->fontManager.getRef("Menu Font"));
	player1Turn.setString("Player 1's Turn");
	player1Turn.setCharacterSize(40);
	player1Turn.setPosition(1200.0f, 75.0f);
	player1Turn.setFillColor(sf::Color::White);

	player2Turn.setFont(game->fontManager.getRef("Menu Font"));
	player2Turn.setString("Player 2's Turn");
	player2Turn.setCharacterSize(40);
	player2Turn.setPosition(1200.0f, 75.0f);
	player2Turn.setFillColor(sf::Color::White);

	player1Coins.setFont(game->fontManager.getRef("Menu Font"));
	player1Coins.setString("Coins:  " + to_string(p_game->world.player1.getCoins()));
	player1Coins.setCharacterSize(25);
	player1Coins.setPosition(30.0f, 20.0f);
	player1Coins.setFillColor(sf::Color::White);

	player1Wood.setFont(game->fontManager.getRef("Menu Font"));
	player1Wood.setString("Wood:  " + to_string(p_game->world.player1.getWood()));
	player1Wood.setCharacterSize(25);
	player1Wood.setPosition(130.0f, 20.0f);
	player1Wood.setFillColor(sf::Color::White);

	player1Stone.setFont(game->fontManager.getRef("Menu Font"));
	player1Stone.setString("Stone:  " + to_string(p_game->world.player1.getStone()));
	player1Stone.setCharacterSize(25);
	player1Stone.setPosition(230.0f, 20.0f);
	player1Stone.setFillColor(sf::Color::White);

	player1Clay.setFont(game->fontManager.getRef("Menu Font"));
	player1Clay.setString("Clay:  " + to_string(p_game->world.player1.getClay()));
	player1Clay.setCharacterSize(25);
	player1Clay.setPosition(330.0f, 20.0f);
	player1Clay.setFillColor(sf::Color::White);

	player1Papyrus.setFont(game->fontManager.getRef("Menu Font"));
	player1Papyrus.setString("Papyrus:  " + to_string(p_game->world.player1.getPapyrus()));
	player1Papyrus.setCharacterSize(25);
	player1Papyrus.setPosition(430.0f, 20.0f);
	player1Papyrus.setFillColor(sf::Color::White);

	player1Glass.setFont(game->fontManager.getRef("Menu Font"));
	player1Glass.setString("Glass:  " + to_string(p_game->world.player1.getGlass()));
	player1Glass.setCharacterSize(25);
	player1Glass.setPosition(570.0f, 20.0f);
	player1Glass.setFillColor(sf::Color::White);

	player2Coins.setFont(game->fontManager.getRef("Menu Font"));
	player2Coins.setString("Coins:  " + to_string(p_game->world.player2.getCoins()));
	player2Coins.setCharacterSize(25);
	player2Coins.setPosition(30.0f, 845.0f);
	player2Coins.setFillColor(sf::Color::White);

	player2Wood.setFont(game->fontManager.getRef("Menu Font"));
	player2Wood.setString("Wood:  " + to_string(p_game->world.player2.getWood()));
	player2Wood.setCharacterSize(25);
	player2Wood.setPosition(130.0f, 845.0f);
	player2Wood.setFillColor(sf::Color::White);

	player2Stone.setFont(game->fontManager.getRef("Menu Font"));
	player2Stone.setString("Stone:  " + to_string(p_game->world.player2.getStone()));
	player2Stone.setCharacterSize(25);
	player2Stone.setPosition(230.0f, 845.0f);
	player2Stone.setFillColor(sf::Color::White);

	player2Clay.setFont(game->fontManager.getRef("Menu Font"));
	player2Clay.setString("Clay:  " + to_string(p_game->world.player2.getClay()));
	player2Clay.setCharacterSize(25);
	player2Clay.setPosition(330.0f, 845.0f);
	player2Clay.setFillColor(sf::Color::White);

	player2Papyrus.setFont(game->fontManager.getRef("Menu Font"));
	player2Papyrus.setString("Papyrus:  " + to_string(p_game->world.player2.getPapyrus()));
	player2Papyrus.setCharacterSize(25);
	player2Papyrus.setPosition(430.0f, 845.0f);
	player2Papyrus.setFillColor(sf::Color::White);

	player2Glass.setFont(game->fontManager.getRef("Menu Font"));
	player2Glass.setString("Glass:  " + to_string(p_game->world.player2.getGlass()));
	player2Glass.setCharacterSize(25);
	player2Glass.setPosition(570.0f, 845.0f);
	player2Glass.setFillColor(sf::Color::White);


}

void GamePlayingState::resetSprites()
{
	for (int i = 0; i < 20; i++)
	{
		if (p_game->world.getAge() == 2)
		{
			mCardSprites[i].setPosition(p_game->world.board[i]->getPosition()[0], p_game->world.board[i]->getPosition()[1]);

			mCardSprites[i].setScale(0.5f, 0.5f);

			if (i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 15 || i == 16 || i == 17)
			{
				mCardSprites[i].setTexture(p_game->textureManager.getRef("Age 2 Back"));
			}
			else
			{
				mCardSprites[i].setTexture(p_game->textureManager.getRef(p_game->world.board[i]->getName()));
			}
		}
		else if (p_game->world.getAge() == 3)
		{
			mCardSprites[i].setPosition(p_game->world.board[i]->getPosition()[0], p_game->world.board[i]->getPosition()[1]);

			mCardSprites[i].setScale(0.5f, 0.5f);

			if (i == 2 || i == 3 || i == 4 || i == 9 || i == 10 || i == 15 || i == 16 || i == 17)
			{
				if (p_game->world.board[i]->getAge() == AGE_GUILD)
				{
					mCardSprites[i].setTexture(p_game->textureManager.getRef("Guild Back"));
				}
				else
				{
					mCardSprites[i].setTexture(p_game->textureManager.getRef("Age 3 Back"));
				}
			}
			else
			{
				mCardSprites[i].setTexture(p_game->textureManager.getRef(p_game->world.board[i]->getName()));
			}
		}
		
	}
}

GamePlayingState::~GamePlayingState()
{
}
