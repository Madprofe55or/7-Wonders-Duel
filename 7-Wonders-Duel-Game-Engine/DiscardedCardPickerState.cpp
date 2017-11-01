#include "DiscardedCardPickerState.h"



void DiscardedCardPickerState::draw(const float dt)
{
	// need to draw the state underneath on the stack
	p_gameplayingstate->draw(dt);

	p_game->window.draw(mainArea);
	p_game->window.draw(mMainText);

	for (vector<sf::Sprite*>::iterator it = mCardSprites.begin(); it != mCardSprites.end(); ++it)
	{
		p_game->window.draw((**it));
	}

	if (mouseover) mMouseoverCard.setPosition(235, 225);
	else if (!mouseover) mMouseoverCard.setPosition(-400, -400);
	p_game->window.draw(mMouseoverCard);

}

void DiscardedCardPickerState::update(const float dt)
{
}

void DiscardedCardPickerState::handleInput()
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
		case sf::Event::MouseMoved:
		{
			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			int mouseoverVectorCount = 0;
			mouseover = false;

			for (vector<sf::FloatRect*>::iterator it = mRectCards.begin(); it != mRectCards.end(); ++it)
			{
				if ((*it)->contains(mouse))
				{
					int pos = (it - mRectCards.begin());
					mMouseoverCard.setTexture(*mCardSprites[pos]->getTexture());
					mouseover = true;
				}
			}
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			for (vector<sf::Sprite*>::iterator it = mCardSprites.begin(); it != mCardSprites.end(); ++it)
			{
				if (p_game->inputManager.isObjectClicked(**it, event.mouseButton.button, p_game->window) == true)
				{
					// getting position of the sprites vector
					int pos = (it - mCardSprites.begin());

					// using this position to figure out which in the player city matches up
					for (vector<Card*>::iterator it = p_game->world.discardDeck.begin(); it != p_game->world.discardDeck.end(); ++it)
					{
						// checking the index stored at this position against index of current card iterator is pointing to
						if (*mCardIndices[pos] = (*it)->getIndex())
						{
							p_game->world.buildCard((*it)->getIndex());
							poppingState = true;
							break;
						}
					}
				}
			}
			break;
		}
		}
	}
	if (poppingState == true) p_game->popState();
}

DiscardedCardPickerState::DiscardedCardPickerState(Game * game, GamePlayingState * gameplayingstate)
{
	p_game = game;
	p_gameplayingstate = gameplayingstate;

	p_game->world.buildFromDiscard = true;

	// Setting up interface area
	mainArea.setFillColor(sf::Color(132, 132, 18, 200));
	mainArea.setPosition(400.0f, 225.0f);
	mainArea.setSize(MAIN_AREA_SIZE);
	mMouseoverCard.setPosition(-400, -400);
	mMouseoverCard.setScale(0.75f, 0.75f);
	mMouseoverCard.setTexture(p_game->textureManager.getRef("Workshop"));
	mMainText.setFont(p_game->fontManager.getRef("Menu Font"));
	mMainText.setCharacterSize(30);
	mMainText.setString("Pick a card to build from discard");
	mMainText.setFillColor(sf::Color::White);
	mMainText.setPosition(610.0f, 227.0f);

	// Setting up cards
	int cardCounter = 0;
	int rowCounter = 0;
	for (vector<Card*>::iterator it = p_game->world.discardDeck.begin(); it != p_game->world.discardDeck.end(); ++it)
	{
		mCardSprites.push_back(new sf::Sprite);
		mCardSprites[cardCounter]->setPosition(350.0f + (((cardCounter - (8 * rowCounter) + 1) * 90)), 275.0f + (130 * rowCounter));
		mCardSprites[cardCounter]->setScale(0.35f, 0.35f);
		mCardSprites[cardCounter]->setTexture(p_game->textureManager.getRef((*it)->getName()));
		mRectCards.push_back(new sf::FloatRect);
		mRectCards[cardCounter]->left = mCardSprites[cardCounter]->getGlobalBounds().left;
		mRectCards[cardCounter]->top = mCardSprites[cardCounter]->getGlobalBounds().top;
		mRectCards[cardCounter]->width = mCardSprites[cardCounter]->getGlobalBounds().width;
		mRectCards[cardCounter]->height = mCardSprites[cardCounter]->getGlobalBounds().height;
		mCardIndices.push_back(new int);
		*mCardIndices[cardCounter] = (*it)->getIndex();
		cardCounter++;
		if (cardCounter % 8 == 0 && cardCounter != 0) rowCounter++; // new row every 8 cards
	}
}