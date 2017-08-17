#include "GameState.h"
#include "WonderPickerState.h"

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
						mWonderRects[i].setPosition(-1000, 0);
					};
				
				}
				
			}
		}
		default: break;
		}
	}
	if (poppingState == true) p_game->popState(); // pop state here, outside while loop
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
