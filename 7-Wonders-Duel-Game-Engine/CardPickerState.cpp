#include "CardPickerState.h"


void CardPickerState::draw(const float dt)
{
	// need to first draw the game playing state that's on the stack underneath
	p_GamePlayingState->draw(dt);
	p_game->window.draw(p_GamePlayingState->rectPickingCard);

	
	p_game->window.draw(testRectangle);
	p_game->window.draw(testCard);

	p_game->window.draw(textCardName);


}

void CardPickerState::update(const float dt)
{
}

void CardPickerState::handleInput()
{
	sf::Event event;
	bool poppingState = false;

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
				if (p_game->inputManager.isObjectClicked(testRectangle, event.mouseButton.button, p_game->window) == false)
				{
					poppingState = true;
				}
			}
		}
		default: break;
		}
	}
	if (poppingState == true)
	{		
		p_game->popState(); // state is popped here since there is no while loop to return to at this point
	}
}

CardPickerState::CardPickerState(Game * game, GamePlayingState * gameplayingstate, Seven_Wonders::Card * card)
{
	p_game = game;
	p_GamePlayingState = gameplayingstate;
	
	testRectangle.setFillColor(sf::Color(132, 132, 18, 200));
	testRectangle.setSize(CARD_GUI_SIZE);
	testRectangle.setPosition(500, 250);

	testCard.setTexture(game->textureManager.getRef(card->getName()));
	testCard.setPosition(500, 300);

	textCardName.setFont(p_game->fontManager.getRef("Menu Font"));
	textCardName.setString("Test Text");
	textCardName.setCharacterSize(40);
	textCardName.setFillColor(sf::Color::White);
	textCardName.setOrigin(textCardName.getGlobalBounds().width / 2.0f, textCardName.getGlobalBounds().height / 2.0f);
	textCardName.setPosition(800, 265);


}
