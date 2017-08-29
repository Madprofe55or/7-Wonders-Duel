#include "WonderPickerState.h"


void WonderPickerState::draw(const float dt)
{
	p_game->window.draw(background);
	p_game->window.draw(chooseWonders);
	
	if (!progressTokensChosen)
	{
		for (int i = 0; i < 5; i++)
		{
			p_game->window.draw(progressTokens[i]);

		}
	}
	
	if (!pickedFourCards && progressTokensChosen==true)
	{
		for (int i = 0; i < 4; i++)
		{
			p_game->window.draw(mWonderRects[i]);
		}
	}
	else if (pickedFourCards)
	{
		for (int i = 4; i < 8; i++)
		{
			p_game->window.draw(mWonderRects[i]);
		}
	}



	p_game->window.draw(player1GUIText);
	p_game->window.draw(player2GUIText);


	p_game->window.draw(gameBoardGUIText);
	p_game->window.draw(wondersDisplayText);
}

void WonderPickerState::update(const float dt)
{

}

void WonderPickerState::handleInput()
{
	sf::Event event;
	bool poppingState = false;
	bool wonderPickState = false;
	bool wondersPicked = false;



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
		}

		case sf::Event::MouseMoved:
		{
			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			if (chooseWonderTextRect.contains(mouse))
			{
				chooseWonders.setFillColor(sf::Color::Green);
			}

			else
			{
				chooseWonders.setFillColor(sf::Color::White);
			}
		}
			

		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

				if (chooseWonderTextRect.contains(mouse))
				{
					chooseWonders.setPosition(-1000, -1000);
					for (int i = 0; i < 5; i++)
					{
						progressTokens[i].setPosition(-1000, -1000);
					}

					progressTokensChosen = true;

				}

				if (!pickedFourCards && progressTokensChosen == true)
					{
						for (int i = 0; i < 4; i++)
						{
							if (vectorWonderFloatRects[i].contains(mouse))
							{
								if (i == 0 || i == 3)
								{
									p_game->world.player1.playerWonderDeck.push_back(wonderBoard[i]);
									wonderBoard[i] = nullptr;
									mWonderRects[i].setPosition(-400, -400);
									vectorWonderFloatRects[i] = mWonderRects[i].getGlobalBounds();
									numOfPickedCards++;
									if (numOfPickedCards == 4) pickedFourCards = true;
									break;
								}
								else if (i == 1 || i == 2)
								{
									p_game->world.player2.playerWonderDeck.push_back(wonderBoard[i]);
									wonderBoard[i] = nullptr;
									mWonderRects[i].setPosition(-400, -400);
									vectorWonderFloatRects[i] = mWonderRects[i].getGlobalBounds();
									numOfPickedCards++;
									if (numOfPickedCards == 4) pickedFourCards = true;
									break;
								}
							}
						}
					}

					else if (pickedFourCards)
					{
						for (int i = 4; i < 8; i++)
						{
							if (vectorWonderFloatRects[i].contains(mouse))
							{
								if (i == 4 || i == 7)
								{
									p_game->world.player2.playerWonderDeck.push_back(wonderBoard[i]);
									wonderBoard[i] = nullptr;
									mWonderRects[i].setPosition(-400, -400);
									vectorWonderFloatRects[i] = mWonderRects[i].getGlobalBounds();
									numOfPickedCards++;
									if (numOfPickedCards == 8) wondersPicked = true;
									break;
								}
								else if (i == 5 || i == 6)
								{
									p_game->world.player1.playerWonderDeck.push_back(wonderBoard[i]);
									wonderBoard[i] = nullptr;
									mWonderRects[i].setPosition(-400, -400);
									vectorWonderFloatRects[i] = mWonderRects[i].getGlobalBounds();
									numOfPickedCards++;
									if (numOfPickedCards == 8) wondersPicked = true;
									break;
								}
							}
						}
					}
				}
		}
		default: break;
		}
	}
	if (poppingState == true) p_game->popState(); // pop state here, outside while loop
	if (wondersPicked == true) p_game->changeState(new GamePlayingState(p_game)); // push card picker state
}

WonderPickerState::WonderPickerState(Game * game)
{
	p_game = game;

	for (int i = 0; i < 5; i++)
	{
		progressTokenBoard[i]= p_game->world.progressTokenDeck[i];
	}
	for (int i = 0; i < 8; i++)
	{
		wonderBoard[i] = p_game->world.wonderCardDeck[i];
	}


	for (int i = 0; i < 5; i++)
	{
		progressTokens[i].setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[i]->getName()));
		progressTokens[i].setPosition(Seven_Wonders::PROGRESS_TOKEN_POSITIONS[i][0], Seven_Wonders::PROGRESS_TOKEN_POSITIONS[i][1]);
	}


	for (int i = 0; i < 8; ++i)
	{
		mWonderRects[i].setTexture(p_game->textureManager.getRef(p_game->world.wonderCardDeck[i]->getName()));
		if (i >= 4)
		{
			mWonderRects[i].setPosition(Seven_Wonders::WONDER_POSITIONS_1[i - 4][0], Seven_Wonders::WONDER_POSITIONS_1[i - 4][1]);
		}
		else
		{
			mWonderRects[i].setPosition(Seven_Wonders::WONDER_POSITIONS_1[i][0], Seven_Wonders::WONDER_POSITIONS_1[i][1]);
		}
		vectorWonderFloatRects[i] = mWonderRects[i].getGlobalBounds();
	}

	//Set Text for the Wonders 
	chooseWonders.setFont(p_game->fontManager.getRef("Menu Font"));
	chooseWonders.setCharacterSize(50);
	chooseWonders.setFillColor(sf::Color::White);
	chooseWonders.setString("Choose Wonders ->");
	chooseWonders.setPosition(900, 700);

	chooseWonderTextRect = chooseWonders.getGlobalBounds();

	// Setting background
	background.setTexture(p_game->textureManager.getRef("GameStatePlaying Background"));

	gameBoard.setTexture(game->textureManager.getRef("Game Board"));
	gameBoard.setScale(0.83f, 0.83f);
	gameBoard.setPosition(10.0f, 75.0f);


}

