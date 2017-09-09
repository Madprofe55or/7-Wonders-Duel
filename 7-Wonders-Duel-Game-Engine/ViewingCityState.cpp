#include "ViewingCityState.h"

void ViewingCityState::draw(const float dt)
{
	p_GamePlayingState->draw(dt);
	p_game->window.draw(p_GamePlayingState->rectPickingCard);

	p_game->window.draw(rectMainArea);

	if (!mCityCardSprites.empty())
	{
		for (vector<sf::Sprite*>::iterator it = mCityCardSprites.begin();
			it != mCityCardSprites.end(); ++it)
		{
			p_game->window.draw((**it));
		}
	}

	if (p_player == &p_game->world.player1)
	{
		if (mouseover) mouseoverCard.setPosition(800.0f, 100.0f);
		else if (!mouseover) mouseoverCard.setPosition(-400.0f, -400.0f);
	}
	else if (p_player == &p_game->world.player2)
	{
		if (mouseover) mouseoverCard.setPosition(800.0f, 450.0f);
		else if (!mouseover) mouseoverCard.setPosition(-400.0f, -400.0f);
	}


	p_game->window.draw(mouseoverCard);
	p_game->window.draw(cityViewTitle);

}

void ViewingCityState::update(const float dt)
{
}

void ViewingCityState::handleInput()
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
			if (event.key.code == sf::Keyboard::Space)
			{
				poppingState = true; // can't popstate while in loop, since loop references this and popstate deletes this
				break;
			}
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (!p_game->inputManager.isObjectClicked(rectMainArea, event.mouseButton.button, p_game->window))
				{
					poppingState = true;
				}
			}
		}
		case sf::Event::MouseMoved:
		{
			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			int mouseoverVectorCount = 0;
			mouseover = false;
			
			for (vector < sf::FloatRect*>::iterator it = mCardRects.begin(); it != mCardRects.end(); ++it)
			{
				if ((*it)->contains(mouse))
				{
					mouseoverCard.setTexture(p_game->textureManager.getRef(p_player->playerCity[mouseoverVectorCount]->getName()));
					mouseover = true;
					//break;
				}
				mouseoverVectorCount++;
			}
			
		}
		default: break;
		}
	}
	if (poppingState == true)
	{
		deleteSprites();
		p_game->popState(); // state is popped here since there is no while loop to return to at this point
	}
}

ViewingCityState::ViewingCityState(Game * game, GamePlayingState * gameplayingstate, Player * player)
{
	p_game = game;
	p_GamePlayingState = gameplayingstate;
	p_player = player;
	int vectorCount = 0;

	rectMainArea.setFillColor(sf::Color(132, 132, 18, 200));
	rectMainArea.setSize(MAIN_AREA_SIZE);
	if (player->getPlayerNumber() == PLAYER_1) 
	{
		rectMainArea.setPosition(800, 0);
	}
	else if (player->getPlayerNumber() == PLAYER_2)
	{
		rectMainArea.setPosition(800, 450);
	}

	if (!player->playerCity.empty()) // need to first check that there are actually cards in the player's city
	{
		for (vector<Card*>::iterator it = player->playerCity.begin();
			it != player->playerCity.end(); ++it)
		{
			mCityCardSprites.push_back(new sf::Sprite);
			mCityCardSprites[vectorCount]->setTexture(p_game->textureManager.getRef((*it)->getName()));
			mCityCardSprites[vectorCount]->setScale(0.3f, 0.3f); // need smaller scale in order to fit and for simplicity
			// following algorithm is for positioning cards into columns of 5 cards each
			if (vectorCount < 5) // first column
			{
				if (player->getPlayerNumber() == PLAYER_1)
				{
					mCityCardSprites[vectorCount]->setPosition(850.0f, 50.0f + (50 * vectorCount));
				}
				else if (player->getPlayerNumber() == PLAYER_2)
				{
					mCityCardSprites[vectorCount]->setPosition(850.0f, 500.0f + (50 * vectorCount));
				}
			}
			else if (vectorCount >= 5 && vectorCount < 10) // second column
			{
				if (player->getPlayerNumber() == PLAYER_1)
				{
					mCityCardSprites[vectorCount]->setPosition(950.0f, 50.0f + (50 * vectorCount - 5));
				}
				else if (player->getPlayerNumber() == PLAYER_2)
				{
					mCityCardSprites[vectorCount]->setPosition(950.0f, 500.0f + (50 * vectorCount - 5));
				}
			}
			else if (vectorCount >= 10 && vectorCount < 15) // third column
			{
				if (player->getPlayerNumber() == PLAYER_1)
				{
					mCityCardSprites[vectorCount]->setPosition(1050.0f, 50.0f + (50 * vectorCount - 10));
				}
				else if (player->getPlayerNumber() == PLAYER_2)
				{
					mCityCardSprites[vectorCount]->setPosition(1050.0f, 500.0f + (50 * vectorCount - 10));
				}
			}
			else if (vectorCount >= 15 && vectorCount < 20) // fourth column
			{
				if (player->getPlayerNumber() == PLAYER_1)
				{
					mCityCardSprites[vectorCount]->setPosition(1150.0f, 50.0f + (50 * vectorCount - 15));
				}
				else if (player->getPlayerNumber() == PLAYER_2)
				{
					mCityCardSprites[vectorCount]->setPosition(1150.0f, 500.0f + (50 * vectorCount - 15));
				}
			}
			else if (vectorCount >= 20 && vectorCount < 25) // fifth column
			{
				if (player->getPlayerNumber() == PLAYER_1)
				{
					mCityCardSprites[vectorCount]->setPosition(1250.0f, 50.0f + (50 * vectorCount - 20));
				}
				else if (player->getPlayerNumber() == PLAYER_2)
				{
					mCityCardSprites[vectorCount]->setPosition(1250.0f, 500.0f + (50 * vectorCount - 20));
				}
			}
			else if (vectorCount >= 25 && vectorCount < 30) // fifth column
			{
				if (player->getPlayerNumber() == PLAYER_1)
				{
					mCityCardSprites[vectorCount]->setPosition(1350.0f, 50.0f + (50 * vectorCount - 25));
				}
				else if (player->getPlayerNumber() == PLAYER_2)
				{
					mCityCardSprites[vectorCount]->setPosition(1350.0f, 500.0f + (50 * vectorCount - 25));
				}
			}

			vectorCount++;
		}
	}

	vectorCount = 0;
	// setting up sf::floatrects for each sprite in the state
	if (!mCityCardSprites.empty())
	{
		for (vector<sf::Sprite*>::iterator it = mCityCardSprites.begin(); it != mCityCardSprites.end(); ++it)
		{
			mCardRects.push_back(new sf::FloatRect);
			*mCardRects[vectorCount] = (*it)->getGlobalBounds();
			vectorCount++;
		}
	}

	mouseoverCard.setTexture(p_game->textureManager.getRef("Clay Reserve"));
	mouseoverCard.setPosition(-400.0f, -400.0f);
	mouseoverCard.setOrigin(mouseoverCard.getGlobalBounds().width, 0.0f);
	//mouseoverCard.setColor(sf::Color(255, 255, 255, 190)); // for transparency, if desired

	cityViewTitle.setFont(p_game->fontManager.getRef("Menu Font"));
	cityViewTitle.setString("Player " + to_string(player->getPlayerNumber()) + "\'s" + " City");
	cityViewTitle.setFillColor(sf::Color::White);
	cityViewTitle.setCharacterSize(35);
	cityViewTitle.setOrigin(cityViewTitle.getGlobalBounds().width / 2.0f, cityViewTitle.getGlobalBounds().height / 2.0f);
	if (player->getPlayerNumber() == PLAYER_1)
	{
		cityViewTitle.setPosition(1200.0f, 25.0f);
	}
	else if (player->getPlayerNumber() == PLAYER_2)
	{
		cityViewTitle.setPosition(1200.0f, 475.0f);
	}
}

/* Frees memory where sprites and floatrects are stored in the ViewingCityState class */
void ViewingCityState::deleteSprites()
{
	if (!mCityCardSprites.empty())
	{
		for (vector<sf::FloatRect*>::iterator it = mCardRects.begin(); it != mCardRects.end(); ++it)
		{
			delete (*it);
		}
		mCardRects.clear();		
		
		for (vector<sf::Sprite*>::iterator it = mCityCardSprites.begin(); it != mCityCardSprites.end(); ++it)
		{
			delete (*it);
		}
		mCityCardSprites.clear();

	}
	


}
