#include "GamePlayingState.h"
#include "CardPickerState.h"
#include "ViewingCityState.h"
#include "CardDestroyerState.h"
#include "ProgressTokenBuildingState.h"

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

	for (int i = 0; i < 4; i++)
	{
		if (p_game->world.player1.playerWonderDeck[i]->builtWonder == true) p_game->window.draw(mWonderBuiltSpritesP1[i]);
		if (p_game->world.player2.playerWonderDeck[i]->builtWonder == true) p_game->window.draw(mWonderBuiltSpritesP2[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		p_game->window.draw(mWonderSpritesP1[i]);
		p_game->window.draw(mWonderSpritesP2[i]);
	}

	// drawing mouseover card
	if (mouseover) mouseoverCard.setPosition(900.0f, 350.0f);
	if (!mouseover) mouseoverCard.setPosition(-400.0f, -400.0f);
	p_game->window.draw(mouseoverCard);

	
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

	mConflictPawn.setPosition(CONFLICT_PAWN_POSITIONS[9 + p_game->world.mConflict][0], CONFLICT_PAWN_POSITIONS[9 + p_game->world.mConflict][1]);
	p_game->window.draw(mConflictPawn);

	for (int i = 0; i < 5; i++)
	{
		if (p_game->world.progressTokenDeck[i] != nullptr) p_game->window.draw(mProgressTokens[i]);
	}

	// drawing mouseover progresstoken
	if (mouseOverToken) mouseOverProgressToken.setPosition(150.0f, 350.0f);
	if (!mouseOverToken) mouseOverProgressToken.setPosition(-400.0f, -400.0f);
	p_game->window.draw(mouseOverProgressToken);


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

	p_game->window.draw(player1City);
	p_game->window.draw(player2City);
	p_game->window.draw(txtPlayer1City);
	p_game->window.draw(txtPlayer2City);
}

void GamePlayingState::update(const float dt)
{
	checkForDestroyingBrownCard();
	checkForDestroyingGrayCard();
	checkForPTBuildState();
}

void GamePlayingState::handleInput()
{
	sf::Event event;
	bool poppingState = false;
	bool cardPickState = false;
	bool viewP1City = false;
	bool viewP2City = false;
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
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (p_game->inputManager.isObjectClicked(player1City, event.mouseButton.button, p_game->window) == true)
				{
					viewP1City = true;
				}
				if (p_game->inputManager.isObjectClicked(player2City, event.mouseButton.button, p_game->window) == true)
				{
					viewP2City = true;
				}
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
		case sf::Event::MouseMoved:
		{
			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			int mouseoverVectorCount = 0;
			mouseover = false;
			mouseOverToken = false;

			for (int i = 0; i < 4; i++)
			{
				if (mRectWondersP1[i].contains(mouse))
				{
					mouseoverCard.setTexture(p_game->textureManager.getRef(p_game->world.player1.playerWonderDeck[i]->getName()));
					mouseover = true;
					break;
				}
				mouseoverVectorCount++;
			}

			mouseoverVectorCount = 0;
			for (int i = 0; i < 4; i++)
			{
				if (mRectWondersP2[i].contains(mouse))
				{
					mouseoverCard.setTexture(p_game->textureManager.getRef(p_game->world.player2.playerWonderDeck[i]->getName()));
					mouseover = true;
					break;
				}
				mouseoverVectorCount++;
			}


			for (int i = 0; i < 5; i++)
			{
				if (mProgressTokenRects[i].contains(mouse) && p_game->world.progressTokenDeck[i] != nullptr)
				{
					mouseOverProgressToken.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[i]->getName()));
					mouseOverProgressToken.setScale(0.5f, 0.5f);
					mouseOverToken = true;
					break;
				}
			}
			if (rectPlayer1City.contains(mouse))
			{
				player1City.setFillColor(sf::Color(51, 53, 255));
			}
			else player1City.setFillColor(sf::Color(54, 204, 51));
			
			if (rectPlayer2City.contains(mouse))
			{
				player2City.setFillColor(sf::Color(51, 53, 255));
			}
			else player2City.setFillColor(sf::Color(54, 204, 51));

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
	if (viewP1City == true)
	{
		rectPickingCard.setFillColor(sf::Color(0, 0, 0, 126));
		rectPickingCard.setPosition(0, 0);
		rectPickingCard.setSize(rectPickingCardSize);
		player1City.setFillColor(sf::Color(54, 204, 51));
		p_game->pushState(new ViewingCityState(p_game, this, &p_game->world.player1));
	}
	else if (viewP2City == true)
	{
		rectPickingCard.setFillColor(sf::Color(0, 0, 0, 126));
		rectPickingCard.setPosition(0, 0);
		rectPickingCard.setSize(rectPickingCardSize);
		player2City.setFillColor(sf::Color(54, 204, 51));
		p_game->pushState(new ViewingCityState(p_game, this, &p_game->world.player2));
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

	for (int i = 0; i < 4; i++)
	{
		mWonderSpritesP1[i].setTexture(p_game->textureManager.getRef(p_game->world.player1.playerWonderDeck[i]->getName()));
		mWonderSpritesP1[i].setOrigin(mWonderSpritesP1[i].getGlobalBounds().width, 0.0f);
		mWonderSpritesP1[i].setScale(0.2769f, 0.2769f);
		mWonderSpritesP1[i].setPosition(1600.0f, 75.0f + (mWonderSpritesP1[i].getGlobalBounds().height * i));
	}

	for (int i = 0; i < 4; i++)
	{
		mWonderSpritesP2[i].setTexture(p_game->textureManager.getRef(p_game->world.player2.playerWonderDeck[i]->getName()));
		mWonderSpritesP2[i].setOrigin(mWonderSpritesP2[i].getGlobalBounds().width, 0.0f);
		mWonderSpritesP2[i].setScale(0.2769f, 0.2769f);
		mWonderSpritesP2[i].setPosition(1600.0f, 465.0f + (mWonderSpritesP2[i].getGlobalBounds().height * i));
	}

	for (int i = 0; i < 5; i++)
	{
		mProgressTokens[i].setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[i]->getName()));
		mProgressTokens[i].setScale(0.20f, 0.20f);
		mProgressTokens[i].setOrigin(mProgressTokens[i].getGlobalBounds().width / 2.0, mProgressTokens[i].getGlobalBounds().height/ 2.0);
		mProgressTokens[i].setPosition(25.0f, 260.0f + (77.0 * i));
	}

	for (int i = 0; i < 5; i++)
	{
		mProgressTokenRects[i] = mProgressTokens[i].getGlobalBounds();
	}

	for (int i = 0; i < 4; i++)
	{
		mRectWondersP1[i] = mWonderSpritesP1[i].getGlobalBounds();
	}

	for (int i = 0; i < 4; i++)
	{
		mRectWondersP2[i] = mWonderSpritesP2[i].getGlobalBounds();
	}

	mouseoverCard.setTexture(p_game->textureManager.getRef("Piraeus"));
	mouseoverCard.setPosition(-400.0f, -400.0f);

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

	mConflictPawn.setTexture(p_game->textureManager.getRef("Conflict Pawn"));
	mConflictPawn.setScale(0.30f, 0.30f);
	mConflictPawn.setOrigin(mConflictPawn.getGlobalBounds().width / 2, mConflictPawn.getGlobalBounds().height / 2);
	mConflictPawn.setPosition(108.0f, 392.0f);

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

	player2City.setFillColor(sf::Color(54, 204, 51));
	player2City.setSize(BUTTON_SIZE);
	player2City.setPosition(950.0f, 850.0f);
	player2City.setOrigin(player2City.getGlobalBounds().width / 2, player2City.getGlobalBounds().height / 2);

	player1City.setFillColor(sf::Color(54, 204, 51));
	player1City.setSize(BUTTON_SIZE);
	player1City.setPosition(950.0f, 35.0f);
	player1City.setOrigin(player1City.getGlobalBounds().width / 2, player1City.getGlobalBounds().height / 2);

	txtPlayer2City.setFont(game->fontManager.getRef("Menu Font"));
	txtPlayer2City.setString("View City");
	txtPlayer2City.setCharacterSize(35);
	txtPlayer2City.setFillColor(sf::Color::White);
	txtPlayer2City.setOrigin(txtPlayer2City.getGlobalBounds().width / 2, txtPlayer2City.getGlobalBounds().height / 2);
	txtPlayer2City.setPosition(player2City.getPosition());
	
	txtPlayer1City.setFont(game->fontManager.getRef("Menu Font"));
	txtPlayer1City.setString("View City");
	txtPlayer1City.setCharacterSize(35);
	txtPlayer1City.setFillColor(sf::Color::White);
	txtPlayer1City.setOrigin(txtPlayer1City.getGlobalBounds().width / 2, txtPlayer1City.getGlobalBounds().height / 2);
	txtPlayer1City.setPosition(player1City.getPosition());


	// built wonder sprites
	for (int i = 0; i < 4; i++)
	{
		mWonderBuiltSpritesP1[i].setTexture(p_game->textureManager.getRef("Age 1 Back"));
		mWonderBuiltSpritesP1[i].setRotation(90);
		mWonderBuiltSpritesP1[i].setScale(0.35f, 0.35f);
		mWonderBuiltSpritesP1[i].setPosition(mWonderSpritesP1[i].getGlobalBounds().left + 90, mWonderSpritesP1[i].getGlobalBounds().top + 5);

		mWonderBuiltSpritesP2[i].setTexture(p_game->textureManager.getRef("Age 1 Back"));
		mWonderBuiltSpritesP2[i].setRotation(90);
		mWonderBuiltSpritesP2[i].setScale(0.35f, 0.35f);
		mWonderBuiltSpritesP2[i].setPosition(mWonderSpritesP2[i].getGlobalBounds().left + 90, mWonderSpritesP2[i].getGlobalBounds().top + 5);
	}

	rectPlayer1City = player1City.getGlobalBounds();
	rectPlayer2City = player2City.getGlobalBounds();
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

void GamePlayingState::setBuiltSprites()
{
	for (int i = 0; i < 4; i++)
	{
		if (p_game->world.player1.playerWonderDeck[i]->builtWonder == true)
		{
			if (p_game->world.player1.playerWonderDeck[i]->builtInAge == 1) mWonderBuiltSpritesP1[i].setTexture(p_game->textureManager.getRef("Age 1 Back"));
			else if (p_game->world.player1.playerWonderDeck[i]->builtInAge == 2) mWonderBuiltSpritesP1[i].setTexture(p_game->textureManager.getRef("Age 2 Back"));
			else if (p_game->world.player1.playerWonderDeck[i]->builtInAge == 3) mWonderBuiltSpritesP1[i].setTexture(p_game->textureManager.getRef("Age 3 Back"));
		}
		if (p_game->world.player2.playerWonderDeck[i]->builtWonder == true)
		{
			if (p_game->world.player2.playerWonderDeck[i]->builtInAge == 1) mWonderBuiltSpritesP2[i].setTexture(p_game->textureManager.getRef("Age 1 Back"));
			else if (p_game->world.player2.playerWonderDeck[i]->builtInAge == 2) mWonderBuiltSpritesP2[i].setTexture(p_game->textureManager.getRef("Age 2 Back"));
			else if (p_game->world.player2.playerWonderDeck[i]->builtInAge == 3) mWonderBuiltSpritesP2[i].setTexture(p_game->textureManager.getRef("Age 3 Back"));
		}
	}
}

void GamePlayingState::checkForDestroyingBrownCard()
{
	if (destroyBrownCard) p_game->pushState(new CardDestroyerState(p_game, this, BROWN_CARD));
}

void GamePlayingState::checkForDestroyingGrayCard()
{
	if (destroyGrayCard) p_game->pushState(new CardDestroyerState(p_game, this, GRAY_CARD));
}

void GamePlayingState::checkForPTBuildState()
{
	if (p_game->world.progressTokenState) p_game->pushState(new ProgressTokenBuildingState(p_game, this));
}

GamePlayingState::~GamePlayingState()
{
}


