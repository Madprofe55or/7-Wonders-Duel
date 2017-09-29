#include "ProgressTokenBuildingState.h"


void ProgressTokenBuildingState::draw(const float dt)
{
	p_GamePlayingState->draw(dt);

	p_game->window.draw(mainArea);
	p_game->window.draw(progressTokenText);
	p_game->window.draw(progressToken1);
	p_game->window.draw(progressToken2);
	p_game->window.draw(progressToken3);
	p_game->window.draw(progressToken4);
	p_game->window.draw(progressToken5);
	p_game->window.draw(buttonToken1);
	p_game->window.draw(buttonToken2);
	p_game->window.draw(buttonToken3);
	p_game->window.draw(buttonToken4);
	p_game->window.draw(buttonToken5);
	p_game->window.draw(buttonTokenText1);
	p_game->window.draw(buttonTokenText2);
	p_game->window.draw(buttonTokenText3);
	p_game->window.draw(buttonTokenText4);
	p_game->window.draw(buttonTokenText5);

	/*for (int i = 0; i < p_game->world.progressTokenDeck.size(); i++)
	{
		if (p_game->world.progressTokenDeck[i] != nullptr)
		{
			p_game->window.draw(spriteProgressTokens[i]);
		}
	}*/

	/*
	for (int i = 0; i < 5; i++)
	{
		p_game->window.draw(buttonTokens[i]);
		p_game->window.draw(buttonTokenTexts[i]);
	}*/
}


void ProgressTokenBuildingState::update(const float dt)
{
}

void ProgressTokenBuildingState::handleInput()
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
			if (p_game->inputManager.isObjectClicked(mainArea, event.mouseButton.button, p_game->window) == false)
			{
				poppingState = true;
			}

			if (p_game->inputManager.isObjectClicked(buttonToken1, event.mouseButton.button, p_game->window) == true)
			{
				p_game->world.buildProgressToken(0);
				p_GamePlayingState->setBuiltSprites();
				poppingState = true;
			}

			else if (p_game->inputManager.isObjectClicked(buttonToken2, event.mouseButton.button, p_game->window) == true)
			{
				p_game->world.buildProgressToken(1);
				p_GamePlayingState->setBuiltSprites();
				poppingState = true;
			}

			else if (p_game->inputManager.isObjectClicked(buttonToken3, event.mouseButton.button, p_game->window) == true)
			{
				p_game->world.buildProgressToken(2);
				p_GamePlayingState->setBuiltSprites();
				poppingState = true;
			}

			else if (p_game->inputManager.isObjectClicked(buttonToken4, event.mouseButton.button, p_game->window) == true)
			{
				p_game->world.buildProgressToken(3);
				p_GamePlayingState->setBuiltSprites();
				poppingState = true;
			}

			else if (p_game->inputManager.isObjectClicked(buttonToken5, event.mouseButton.button, p_game->window) == true)
			{
				p_game->world.buildProgressToken(4);
				p_GamePlayingState->setBuiltSprites();
				poppingState = true;
			}
		}
		default: break;
		} // end of switch
	} // end of while
	if (poppingState == true)
	{
		p_game->world.progressTokenState = false;
		p_game->popState(); // state is popped here since there is no while loop to return to at this point
	}
}

ProgressTokenBuildingState::ProgressTokenBuildingState(Game * game, GamePlayingState * gameplayingstate)
{
	p_game = game;
	p_GamePlayingState = gameplayingstate;
	p_player = p_game->world.currentPlayer;

	buttonToken1.setSize(BUTTON_SIZE);
	buttonToken2.setSize(BUTTON_SIZE);
	buttonToken3.setSize(BUTTON_SIZE);
	buttonToken4.setSize(BUTTON_SIZE);
	buttonToken5.setSize(BUTTON_SIZE);

	mainArea.setSize(MAIN_AREA_SIZE);
	mainArea.setPosition(500, 75);
	mainArea.setFillColor(sf::Color(51, 153, 255, 200));

	progressTokenText.setFont(p_game->fontManager.getRef("Menu Font"));
	progressTokenText.setString("Which Token would you like to build?");
	progressTokenText.setCharacterSize(40);
	progressTokenText.setPosition(550, 70);

	buttonToken1.setFillColor(sf::Color(133, 142, 155));
	buttonToken1.setSize(BUTTON_SIZE);
	buttonToken1.setPosition(700, 200);

	buttonToken2.setFillColor(sf::Color(133, 142, 155));
	buttonToken2.setSize(BUTTON_SIZE);
	buttonToken2.setPosition(700, 325);

	buttonToken3.setFillColor(sf::Color(133, 142, 155));
	buttonToken3.setSize(BUTTON_SIZE);
	buttonToken3.setPosition(700, 450);

	buttonToken4.setFillColor(sf::Color(133, 142, 155));
	buttonToken4.setSize(BUTTON_SIZE);
	buttonToken4.setPosition(700, 575);

	buttonToken5.setFillColor(sf::Color(133, 142, 155));
	buttonToken5.setSize(BUTTON_SIZE);
	buttonToken5.setPosition(700, 700);

	rectButtonToken1 = buttonToken1.getGlobalBounds();
	rectButtonToken2 = buttonToken2.getGlobalBounds();
	rectButtonToken3 = buttonToken3.getGlobalBounds();
	rectButtonToken4 = buttonToken4.getGlobalBounds();
	rectButtonToken5 = buttonToken5.getGlobalBounds();

	progressToken1.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[0]->getName()));
	progressToken1.setScale(0.35f, 0.35f);
	progressToken1.setOrigin(progressToken1.getGlobalBounds().width, progressToken1.getGlobalBounds().top);
	progressToken1.setPosition(975, 150);

	progressToken2.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[1]->getName()));
	progressToken2.setScale(0.35f, 0.35f);
	progressToken2.setOrigin(progressToken2.getGlobalBounds().width, progressToken2.getGlobalBounds().top);
	progressToken2.setPosition(975, 275);

	progressToken3.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[2]->getName()));
	progressToken3.setScale(0.35f, 0.35f);
	progressToken3.setOrigin(progressToken3.getGlobalBounds().width, progressToken3.getGlobalBounds().top);
	progressToken3.setPosition(975, 400);

	progressToken4.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[3]->getName()));
	progressToken4.setScale(0.35f, 0.35f);
	progressToken4.setOrigin(progressToken4.getGlobalBounds().width, progressToken4.getGlobalBounds().top);
	progressToken4.setPosition(975, 525);

	progressToken5.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[4]->getName()));
	progressToken5.setScale(0.35f, 0.35f);
	progressToken5.setOrigin(progressToken5.getGlobalBounds().width, progressToken5.getGlobalBounds().top);
	progressToken5.setPosition(975, 650);

	if (p_game->world.progressTokenDeck[0] != nullptr)
	{
		buttonTokenText1.setFont(game->fontManager.getRef("Menu Font"));
		buttonTokenText1.setString("Build " + p_game->world.progressTokenDeck[0]->getName());
		buttonTokenText1.setPosition(700, 200);
		buttonTokenText1.setFillColor(sf::Color::White);
		buttonTokenText1.setCharacterSize(25);
	}

	if (p_game->world.progressTokenDeck[1] != nullptr)
	{
		buttonTokenText2.setFont(game->fontManager.getRef("Menu Font"));
		buttonTokenText2.setString("Build " + p_game->world.progressTokenDeck[1]->getName());
		buttonTokenText2.setPosition(700, 325);
		buttonTokenText2.setFillColor(sf::Color::White);
		buttonTokenText2.setCharacterSize(25);
	}

	if (p_game->world.progressTokenDeck[2] != nullptr)
	{
		buttonTokenText3.setFont(game->fontManager.getRef("Menu Font"));
		buttonTokenText3.setString("Build " + p_game->world.progressTokenDeck[2]->getName());
		buttonTokenText3.setPosition(700, 450);
		buttonTokenText3.setFillColor(sf::Color::White);
		buttonTokenText3.setCharacterSize(25);
	}

	if (p_game->world.progressTokenDeck[3] != nullptr)
	{
		buttonTokenText4.setFont(game->fontManager.getRef("Menu Font"));
		buttonTokenText4.setString("Build " + p_game->world.progressTokenDeck[3]->getName());
		buttonTokenText4.setPosition(700, 600);
		buttonTokenText4.setFillColor(sf::Color::White);
		buttonTokenText4.setCharacterSize(25);
	}

	if (p_game->world.progressTokenDeck[4] != nullptr)
	{
		buttonTokenText5.setFont(game->fontManager.getRef("Menu Font"));
		buttonTokenText5.setString("Build " + p_game->world.progressTokenDeck[4]->getName());
		buttonTokenText5.setPosition(700, 725);
		buttonTokenText5.setFillColor(sf::Color::White);
		buttonTokenText5.setCharacterSize(25);
	}
}

ProgressTokenBuildingState::~ProgressTokenBuildingState()
{
}
