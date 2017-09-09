#include "ProgressTokenBuildingState.h"


void ProgressTokenBuildingState::draw(const float dt)
{
	p_GamePlayingState->draw(dt);
	p_CardPickerState->draw(dt);

	p_game->window.draw(mainArea);
	p_game->window.draw(progressTokenText);
	p_game->window.draw(progressToken1);
	p_game->window.draw(progressToken1);
	p_game->window.draw(progressToken1);
	p_game->window.draw(progressToken1);
	p_game->window.draw(buttonToken1);
	p_game->window.draw(buttonToken2);
	p_game->window.draw(buttonToken3);
	p_game->window.draw(buttonToken4);
	p_game->window.draw(buttonToken5);
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

			break;
		}
		case sf::Event::MouseMoved:
		{
			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			if (canBuildToken1 && rectButtonToken1.contains(mouse)) buttonToken1.setFillColor(sf::Color(51, 153, 255));
			else if (canBuildToken1 && !rectButtonToken1.contains(mouse)) buttonToken1.setFillColor(sf::Color(242, 198, 55));
			else buttonToken1.setFillColor(sf::Color(133, 142, 155));

			if (canBuildToken2 && rectButtonToken2.contains(mouse)) buttonToken2.setFillColor(sf::Color(51, 153, 255));
			else if (canBuildToken2 && !rectButtonToken2.contains(mouse)) buttonToken2.setFillColor(sf::Color(242, 198, 55));
			else buttonToken2.setFillColor(sf::Color(133, 142, 155));

			if (canBuildToken3 && rectButtonToken3.contains(mouse)) buttonToken3.setFillColor(sf::Color(51, 153, 255));
			else if (canBuildToken3 && !rectButtonToken3.contains(mouse)) buttonToken3.setFillColor(sf::Color(242, 198, 55));
			else buttonToken3.setFillColor(sf::Color(133, 142, 155));

			if (canBuildToken4 && rectButtonToken4.contains(mouse)) buttonToken4.setFillColor(sf::Color(51, 153, 255));
			else if (canBuildToken4 && !rectButtonToken4.contains(mouse)) buttonToken4.setFillColor(sf::Color(242, 198, 55));
			else buttonToken4.setFillColor(sf::Color(133, 142, 155));

			if (canBuildToken5 && rectButtonToken4.contains(mouse)) buttonToken5.setFillColor(sf::Color(51, 153, 255));
			else if (canBuildToken5 && !rectButtonToken5.contains(mouse)) buttonToken5.setFillColor(sf::Color(242, 198, 55));
			else buttonToken4.setFillColor(sf::Color(133, 142, 155));

			break;
		}

		}
		if (poppingState == true)
		{
			p_game->popState(); // state is popped here since there is no while loop to return to at this point
		}
	}
}

ProgressTokenBuildingState::ProgressTokenBuildingState(Game * game, GamePlayingState * gameplayingstate)
{
	p_game = game;
	p_GamePlayingState = gameplayingstate;
	p_player = p_game->world.currentPlayer;


	progressToken1.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[0]->getName()));
	progressToken2.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[1]->getName()));
	progressToken3.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[2]->getName()));
	progressToken4.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[3]->getName()));
	progressToken5.setTexture(p_game->textureManager.getRef(p_game->world.progressTokenDeck[4]->getName()));

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


	if (canBuildToken1) buttonToken1.setFillColor(sf::Color(242, 198, 55));
	else buttonToken1.setFillColor(sf::Color(133, 142, 155));
	buttonToken1.setSize(BUTTON_SIZE);
	buttonToken1.setPosition(700, 200);

	if (canBuildToken2) buttonToken2.setFillColor(sf::Color(242, 198, 55));
	else buttonToken2.setFillColor(sf::Color(133, 142, 155));
	buttonToken2.setSize(BUTTON_SIZE);
	buttonToken2.setPosition(700, 370);

	if (canBuildToken3) buttonToken3.setFillColor(sf::Color(242, 198, 55));
	else buttonToken3.setFillColor(sf::Color(133, 142, 155));
	buttonToken3.setSize(BUTTON_SIZE);
	buttonToken3.setPosition(700, 545);

	if (canBuildToken4) buttonToken4.setFillColor(sf::Color(242, 198, 55));
	else buttonToken4.setFillColor(sf::Color(133, 142, 155));
	buttonToken4.setSize(BUTTON_SIZE);
	buttonToken4.setPosition(700, 725);

	rectButtonToken1 = buttonToken1.getGlobalBounds();
	rectButtonToken2 = buttonToken2.getGlobalBounds();
	rectButtonToken3 = buttonToken3.getGlobalBounds();
	rectButtonToken4 = buttonToken4.getGlobalBounds();
	rectButtonToken5 = buttonToken4.getGlobalBounds();


	progressToken1.setScale(0.52f, 0.52f);
	progressToken1.setOrigin(progressToken1.getGlobalBounds().width, progressToken1.getGlobalBounds().top);
	progressToken1.setPosition(975, 125);

	progressToken2.setScale(0.52f, 0.52f);
	progressToken2.setOrigin(progressToken2.getGlobalBounds().width, progressToken2.getGlobalBounds().top);
	progressToken2.setPosition(975, 302.5f);

	progressToken3.setScale(0.52f, 0.52f);
	progressToken3.setOrigin(progressToken3.getGlobalBounds().width, progressToken3.getGlobalBounds().top);
	progressToken3.setPosition(975, 475);

	progressToken4.setScale(0.52f, 0.52f);
	progressToken4.setOrigin(progressToken4.getGlobalBounds().width, progressToken4.getGlobalBounds().top);
	progressToken4.setPosition(975, 652.5f);

	progressToken5.setScale(0.52f, 0.52f);
	progressToken5.setOrigin(progressToken4.getGlobalBounds().width, progressToken4.getGlobalBounds().top);
	progressToken5.setPosition(975, 652.5f); 

}
