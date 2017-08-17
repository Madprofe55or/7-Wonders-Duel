#include "CardPickerState.h"



void CardPickerState::draw(const float dt)
{
	// need to first draw the game playing state that's on the stack underneath
	p_GamePlayingState->draw(dt);
	
	p_game->window.draw(testRectangle);
	p_game->window.draw(testCardText);
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
		default: break;
		}
	}
	if (poppingState == true) p_game->popState(); // state is popped here since there is no while loop to return to at this point
}

CardPickerState::CardPickerState(Game * game, GamePlayingState * gameplayingstate)
{
	p_game = game;
	p_GamePlayingState = gameplayingstate;
	
	testRectangle.setFillColor(sf::Color(132, 132, 18, 200));
	testRectangle.setSize(CARD_GUI_SIZE);
	testRectangle.setPosition(500, 250);

	testCardText.setFont(game->fontManager.getRef("Menu Font"));
	testCardText.setString("Card Picker GUI");
	testCardText.setPosition(670, 400);
	testCardText.setFillColor(sf::Color::White);
	testCardText.setCharacterSize(60);


}
