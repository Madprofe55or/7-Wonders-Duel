#include "Game.h"
#include "GameState.h"
#include "WonderPickerState.h"
#include "GamePlayingState.h"

void WonderPickerState::draw(const float dt)
{
	p_game->window.draw(background);


		if (!pickedFourCards)
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

		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));
				

				if (!pickedFourCards)
				{
					for (int i = 0; i < 4; i++)
					{
						if (vectorWonderFloatRects[i].contains(mouse))
						{
							p_game->world.currentPlayer->playerWonderDeck.push_back(wonderBoard[i]);
							wonderBoard[i] = nullptr;
							mWonderRects[i].setPosition(-400, -400);
							numOfPickedCards++;
							if (numOfPickedCards == 4) pickedFourCards = true;
							break;
						}
					}
				}

				else if (pickedFourCards)
				{
					for (int i = 4; i < 8; i++)
					{
						if (vectorWonderFloatRects[i-4].contains(mouse))
						{
							p_game->world.currentPlayer->playerWonderDeck.push_back(wonderBoard[i]);
							wonderBoard[i] = nullptr;
							mWonderRects[i].setPosition(-400, -400);
							numOfPickedCards++;
							if (numOfPickedCards == 8) wondersPicked = true;
							break;
						}
					}
				}
			}
		}
		default: break;
		}
	}
	if (poppingState == true) p_game->popState(); // pop state here, outside while loop
	if (wondersPicked == true) p_game->changeState(new GamePlayingState(p_game, this)); // push card picker state
}

WonderPickerState::WonderPickerState(Game * game)
{
	p_game = game;
	for (int i = 0 ; i < 8; i++)
	{
		wonderBoard[i] = &p_game->world.wonderCardDeck[i];
	}

	

	for (int i = 0; i < 8; ++i)
	{
		mWonderRects[i].setTexture(p_game->textureManager.getRef(p_game->world.wonderCardDeck[i].getName()));
		if (i>=4)

		{
			mWonderRects[i].setPosition(Seven_Wonders::WONDER_POSITIONS_1[i-4][0], Seven_Wonders::WONDER_POSITIONS_1[i-4][1]);
		}
		else
		{ 
			mWonderRects[i].setPosition(Seven_Wonders::WONDER_POSITIONS_1[i][0], Seven_Wonders::WONDER_POSITIONS_1[i][1]);
			vectorWonderFloatRects[i] = mWonderRects[i].getGlobalBounds();
		}
		
		
		
	}

	// Setting background
	background.setTexture(p_game->textureManager.getRef("GameStatePlaying Background"));

	gameBoard.setTexture(game->textureManager.getRef("Game Board"));
	gameBoard.setScale(0.83f, 0.83f);
	gameBoard.setPosition(10.0f, 75.0f);


}

WonderPickerState::~WonderPickerState()
{

}
