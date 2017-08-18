#include "Game.h"
#include "GameState.h"
#include "WonderPickerState.h"
#include "GamePlayingState.h"

void WonderPickerState::draw(const float dt)
{
	p_game->window.draw(background);

	for (int i = 0; i < 4; ++i)
	{
		p_game->window.draw(mWonderRects[i]);
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
				for (int i = 0; i < 12; i++)
				{
					if (p_game->inputManager.isObjectClicked(mWonderRects[i], event.mouseButton.button, p_game->window) == true)
					{
							clickCount += 1;
							//need to figure out how to move the actual object to the players position
							//player 1 picks 2 wonders and sent to player 1 position
							if (clickCount == 1 )
							{
								mWonderRects[i].setScale(0.50f, 0.50f);
								mWonderRects[i].setPosition(700.0f, 10.0f);
								mWonderPlayer1.push_back[i];
							}

							if (clickCount == 4)
							{
								mWonderRects[i].setScale(0.50f, 0.50f);
								mWonderRects[i].setPosition(950.0f, 10.0f);
								wondersPicked = true;
								mWonderPlayer1.push_back[i];
							}

							//player 2 picks 2 wonders and sent to player 2  position
							if (clickCount == 2)
							{
								mWonderRects[i].setScale(0.500f, 0.50f);
								mWonderRects[i].setPosition(700.0f, 500.0f);
								mWonderPlayer2.push_back[i];
							}

							if (clickCount == 3)
							{
								mWonderRects[i].setScale(0.50f, 0.50f);
								mWonderRects[i].setPosition(950.0f, 500.0f);
								mWonderPlayer2.push_back[i];
							}
						
					};
				
				}
				
			}
		}
		default: break;
		}
	}
	if (poppingState == true) p_game->popState(); // pop state here, outside while loop
	if (wondersPicked == true) p_game->pushState(new GamePlayingState(p_game, this)); // push card picker state
}

WonderPickerState::WonderPickerState(Game * game)
{
	p_game = game;
	

	for (int i = 0; i < 4; ++i)
	{
		mWonderRects[i].setPosition(Seven_Wonders::WONDER_POSITIONS_1[i][0], Seven_Wonders::WONDER_POSITIONS_1[i][1]);
		mWonderRects[i].setTexture(p_game->textureManager.getRef(p_game->world.wonderCardDeck[i].getName()));
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
