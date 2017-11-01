#include "DiscardedPTPickerState.h"


void DiscardedPTPickerState::draw(const float dt)
{
	// need to draw the state underneath on the stack
	p_gameplayingstate->draw(dt);

	p_game->window.draw(mainArea);
	p_game->window.draw(mMainText);

	for (int i = 0; i < 3; i++)
	{
		p_game->window.draw(mPTSprites[i]);
	}

}

void DiscardedPTPickerState::update(const float dt)
{
}

void DiscardedPTPickerState::handleInput()
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
			// Don't think mousing over will be needed since there are only 3 tokens
		}
		case sf::Event::MouseButtonPressed:
		{
			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			for (int i = 0; i < 3; i++)
			{
				if (p_game->inputManager.isObjectClicked(mPTSprites[i], event.mouseButton.button, p_game->window) == true)
				{
					p_game->world.buildProgressToken(i);
					p_gameplayingstate->setBuiltSprites();
					poppingState = true;
				}

			}
			break;
		}
		}
	}
	if (poppingState == true) p_game->popState();
}

DiscardedPTPickerState::DiscardedPTPickerState(Game * game, GamePlayingState * gameplayingstate)
{
	p_game = game;
	p_gameplayingstate = gameplayingstate;

	// Setting up interface area
	mainArea.setFillColor(sf::Color(132, 132, 18, 200));
	mainArea.setPosition(400.0f, 225.0f);
	mainArea.setSize(MAIN_AREA_SIZE);
	mMainText.setFont(p_game->fontManager.getRef("Menu Font"));
	mMainText.setCharacterSize(30);
	mMainText.setString("Pick a progress token to build");
	mMainText.setFillColor(sf::Color::White);
	mMainText.setPosition(610.0f, 227.0f);

	// Setting up PTs in the interface
	for (int i = 0; i < 3; i++)
	{
		mPTSprites[i].setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDiscardDeck[i]->getName()));
		mPTSprites[i].setScale(0.5f, 0.5f);
		mPTSprites[i].setPosition(450.0f + (200 * i), 300.0f);
		mPTRects[i] = mPTSprites[i].getGlobalBounds();
	}

}