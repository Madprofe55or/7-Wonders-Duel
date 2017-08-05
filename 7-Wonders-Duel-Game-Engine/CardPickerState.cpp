#include "CardPickerState.h"


void CardPickerState::draw(const float dt)
{
	// need to first draw the game playing state underneath
	p_GamePlayingState->draw(dt);
	
	this->game->window.draw(this->testRectangle);
	this->game->window.draw(this->testCardText);
}

void CardPickerState::update(const float dt)
{
}

void CardPickerState::handleInput(Game * game)
{
	sf::Event event;
	this->game = game;
	bool poppingState = false;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->window.close();
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
	if (poppingState == true) game->popState(); // state is popped here since there is no while loop to return to at this point
}

CardPickerState::CardPickerState(Game * game, GamePlayingState * gameplayingstate)
{
	this->game = game;
	this->p_GamePlayingState = gameplayingstate;
	
	this->testRectangle.setFillColor(sf::Color(132, 132, 18, 200));
	this->testRectangle.setSize(CARD_GUI_SIZE);
	this->testRectangle.setPosition(500, 250);

	this->testCardText.setFont(game->fontManager.getRef("Menu Font"));
	this->testCardText.setString("Card Picker GUI");
	this->testCardText.setPosition(670, 400);
	this->testCardText.setFillColor(sf::Color::White);
	this->testCardText.setCharacterSize(60);


}
