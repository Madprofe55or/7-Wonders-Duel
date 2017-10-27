#include "CardDestroyerState.h"



void CardDestroyerState::draw(const float dt)
{
	// need to draw the state underneath on the stack
	p_gameplayingstate->draw(dt);

	p_game->window.draw(mainArea);

	for (vector<sf::Sprite*>::iterator it = mCardSprites.begin(); it != mCardSprites.end(); ++it)
	{
		p_game->window.draw((**it));
	}

	if (mouseover) mMouseoverCard.setPosition(700, 425);
	else if (!mouseover) mMouseoverCard.setPosition(-400, -400);
	p_game->window.draw(mMouseoverCard);

	p_game->window.draw(mMainText);
}

void CardDestroyerState::update(const float dt)
{
}

void CardDestroyerState::handleInput()
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
					for (vector<Card*>::iterator it = p_player->playerCity.begin(); it != p_player->playerCity.end(); ++it)
					{
						// checking the index stored at this position against index of current card iterator is pointing to
						if (*mCardIndices[pos] = (*it)->getIndex())
						{
							p_game->world.destroyCard((*it)->getIndex(), *p_player);
							p_game->world.destroyBrownCard = 0;
							p_game->world.destroyGrayCard = 0;
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
	if (poppingState) p_game->popState();
}

CardDestroyerState::CardDestroyerState(Game * game, GamePlayingState * gameplayingstate, int cardtype)
{
	p_game = game;
	p_gameplayingstate = gameplayingstate;
	int numOfCards = 0;

	if (p_game->world.destroyBrownCard == PLAYER_1 || p_game->world.destroyGrayCard == PLAYER_1) p_player = &p_game->world.player2;
	else if (p_game->world.destroyBrownCard == PLAYER_2 || p_game->world.destroyGrayCard == PLAYER_2) p_player = &p_game->world.player1;
	
	/* 
	Will iterate through player's city cards and push a new sprite to the sprites vector
	and then position the cards properly. Also sets up float rects for mouseover functionality
	These will need to be de-allocated when this object is destructed.
	*/
	for (vector<Card*>::iterator it = p_player->playerCity.begin(); it != p_player->playerCity.end(); ++it)
	{
		if ((*it)->getType() == cardtype)
		{
			mCardSprites.push_back(new sf::Sprite);
			mCardSprites[numOfCards]->setPosition(350.0f + ((numOfCards + 1) * 90), 275.0f);
			mCardSprites[numOfCards]->setScale(0.35f, 0.35f);
			mCardSprites[numOfCards]->setTexture(p_game->textureManager.getRef((*it)->getName()));
			mRectCards.push_back(new sf::FloatRect);
			mRectCards[numOfCards]->left = mCardSprites[numOfCards]->getGlobalBounds().left;
			mRectCards[numOfCards]->top = mCardSprites[numOfCards]->getGlobalBounds().top;
			mRectCards[numOfCards]->width = mCardSprites[numOfCards]->getGlobalBounds().width;
			mRectCards[numOfCards]->height = mCardSprites[numOfCards]->getGlobalBounds().height;
			mCardIndices.push_back(new int);
			*mCardIndices[numOfCards] = (*it)->getIndex();
			numOfCards++;
		}
	}

	mainArea.setFillColor(sf::Color(132, 132, 18, 200));
	mainArea.setPosition(400.0f, 225.0f);
	mainArea.setSize(MAIN_AREA_SIZE);

	mMouseoverCard.setPosition(-400, -400);
	mMouseoverCard.setScale(0.75f, 0.75f);
	mMouseoverCard.setTexture(p_game->textureManager.getRef("Workshop"));

	mMainText.setFont(p_game->fontManager.getRef("Menu Font"));
	mMainText.setCharacterSize(30);
	mMainText.setString("Pick a " + std::string((cardtype == GRAY_CARD) ? "Gray" : "Brown") + " card to destroy");
	mMainText.setFillColor(sf::Color::White);
	mMainText.setPosition(675.0f, 227.0f);
}

CardDestroyerState::~CardDestroyerState()
{
	// de-allocating memory used by the sprites vector
	for (vector<sf::Sprite*>::iterator it = mCardSprites.begin(); it != mCardSprites.end(); ++it)
	{
		delete (*it);
		*it = nullptr;
	}
	for (vector<sf::FloatRect*>::iterator it = mRectCards.begin(); it != mRectCards.end(); ++it)
	{
		delete (*it);
		*it = nullptr;
	}

}
