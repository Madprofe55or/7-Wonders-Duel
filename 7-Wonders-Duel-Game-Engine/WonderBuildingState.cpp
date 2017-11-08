#include "WonderBuildingState.h"


void WonderBuildingState::draw(const float dt)
{
	p_GamePlayingState->draw(dt);
	p_CardPickerState->draw(dt);

	p_game->window.draw(mainArea);
	p_game->window.draw(mainText);
	p_game->window.draw(wonderCard1);
	p_game->window.draw(wonderCard2);
	p_game->window.draw(wonderCard3);
	p_game->window.draw(wonderCard4);
	p_game->window.draw(buttonWonder1);
	p_game->window.draw(buttonWonder2);
	p_game->window.draw(buttonWonder3);
	p_game->window.draw(buttonWonder4);
}

void WonderBuildingState::update(const float dt)
{
}

void WonderBuildingState::handleInput()
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

				else if (p_game->inputManager.isObjectClicked(buttonWonder1, event.mouseButton.button, p_game->window) == true)
				{ 
					if (canBuildWonder1)
					{
						buildWonderSound.play();
						p_game->world.buildWonder(1, p_GamePlayingState->clickedCardIndex);
						poppingState = true;
						p_GamePlayingState->setBuiltSprites();
						p_CardPickerState->builtWonder = true;
						// move the sprite for the card off the screen so that it can't be clicked again
						p_GamePlayingState->mCardSprites[p_GamePlayingState->clickedCardIndex].setPosition(-400.0f, -400.0f);
						// checking if last card was built, thus triggering a new age
						if (p_game->world.checkForNewAge() == true) p_GamePlayingState->resetSprites();
					}
				}

				else if (p_game->inputManager.isObjectClicked(buttonWonder2, event.mouseButton.button, p_game->window) == true)
				{
					if (canBuildWonder2)
					{
						buildWonderSound.play();
						p_game->world.buildWonder(2, p_GamePlayingState->clickedCardIndex);
						poppingState = true;
						p_GamePlayingState->setBuiltSprites();
						p_CardPickerState->builtWonder = true;
						// move the sprite for the card off the screen so that it can't be clicked again
						p_GamePlayingState->mCardSprites[p_GamePlayingState->clickedCardIndex].setPosition(-400.0f, -400.0f);
						// checking if last card was built, thus triggering a new age
						if (p_game->world.checkForNewAge() == true) p_GamePlayingState->resetSprites();
					}
				}

				else if (p_game->inputManager.isObjectClicked(buttonWonder3, event.mouseButton.button, p_game->window) == true)
				{
					if (canBuildWonder3)
					{
						buildWonderSound.play();
						p_game->world.buildWonder(3, p_GamePlayingState->clickedCardIndex);
						poppingState = true;
						p_GamePlayingState->setBuiltSprites();
						p_CardPickerState->builtWonder = true;
						// move the sprite for the card off the screen so that it can't be clicked again
						p_GamePlayingState->mCardSprites[p_GamePlayingState->clickedCardIndex].setPosition(-400.0f, -400.0f);
						// checking if last card was built, thus triggering a new age
						if (p_game->world.checkForNewAge() == true) p_GamePlayingState->resetSprites();
					}
				}

				else if (p_game->inputManager.isObjectClicked(buttonWonder4, event.mouseButton.button, p_game->window) == true)
				{
					if (canBuildWonder4)
					{
						buildWonderSound.play();
						p_game->world.buildWonder(4, p_GamePlayingState->clickedCardIndex);
						poppingState = true;
						p_GamePlayingState->setBuiltSprites();
						p_CardPickerState->builtWonder = true;
						// move the sprite for the card off the screen so that it can't be clicked again
						p_GamePlayingState->mCardSprites[p_GamePlayingState->clickedCardIndex].setPosition(-400.0f, -400.0f);
						// checking if last card was built, thus triggering a new age
						if (p_game->world.checkForNewAge() == true) p_GamePlayingState->resetSprites();
					}
				}
				break;
			}
			case sf::Event::MouseMoved:
			{
				sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));
				
				if (canBuildWonder1 && rectButtonWonder1.contains(mouse)) buttonWonder1.setFillColor(sf::Color(51, 153, 255));
				else if (canBuildWonder1 && !rectButtonWonder1.contains(mouse)) buttonWonder1.setFillColor(sf::Color(242, 198, 55));
				else buttonWonder1.setFillColor(sf::Color(133, 142, 155));

				if (canBuildWonder2 && rectButtonWonder2.contains(mouse)) buttonWonder2.setFillColor(sf::Color(51, 153, 255));
				else if (canBuildWonder2 && !rectButtonWonder2.contains(mouse)) buttonWonder2.setFillColor(sf::Color(242, 198, 55));
				else buttonWonder2.setFillColor(sf::Color(133, 142, 155));

				if (canBuildWonder3 && rectButtonWonder3.contains(mouse)) buttonWonder3.setFillColor(sf::Color(51, 153, 255));
				else if (canBuildWonder3 && !rectButtonWonder3.contains(mouse)) buttonWonder3.setFillColor(sf::Color(242, 198, 55));
				else buttonWonder3.setFillColor(sf::Color(133, 142, 155));

				if (canBuildWonder4 && rectButtonWonder4.contains(mouse)) buttonWonder4.setFillColor(sf::Color(51, 153, 255));
				else if (canBuildWonder4 && !rectButtonWonder4.contains(mouse)) buttonWonder4.setFillColor(sf::Color(242, 198, 55));
				else buttonWonder4.setFillColor(sf::Color(133, 142, 155));
				
				break;
			}
		}

	}
	if (poppingState == true)
	{
		p_game->popState(); // state is popped here since there is no while loop to return to at this point
	}
}

WonderBuildingState::WonderBuildingState(Game * game, CardPickerState * cardpickerstate, GamePlayingState * gameplayingstate)
{
	p_game = game;
	p_CardPickerState = cardpickerstate;
	p_GamePlayingState = gameplayingstate;
	p_player = p_game->world.currentPlayer;

	//bufffer sound
	buildWonderSound.setBuffer(p_game->soundManager.soundMap.at("Build Wonder"));

	// Game logic to check for buildable wonders
	if (p_game->world.canBuild(*p_player, *p_player->playerWonderDeck[0]) && p_player->playerWonderDeck[0]->builtWonder == false && p_game->world.wonderCount<=7) canBuildWonder1 = true;
	else canBuildWonder1 = false;
	if (p_game->world.canBuild(*p_player, *p_player->playerWonderDeck[1]) && p_player->playerWonderDeck[1]->builtWonder == false && p_game->world.wonderCount<=7) canBuildWonder2 = true;
	else canBuildWonder2 = false;
	if (p_game->world.canBuild(*p_player, *p_player->playerWonderDeck[2]) && p_player->playerWonderDeck[2]->builtWonder == false && p_game->world.wonderCount<=7) canBuildWonder3 = true;
	else canBuildWonder3 = false;
	if (p_game->world.canBuild(*p_player, *p_player->playerWonderDeck[3]) && p_player->playerWonderDeck[3]->builtWonder == false && p_game->world.wonderCount<=7) canBuildWonder4 = true;
	else canBuildWonder4 = false;
	
	mainArea.setSize(MAIN_AREA_SIZE);
	mainArea.setPosition(500, 75);
	mainArea.setFillColor(sf::Color(51, 153, 255, 200));

	mainText.setFont(p_game->fontManager.getRef("Menu Font"));
	mainText.setString("Which wonder would you like to build?");
	mainText.setCharacterSize(40);
	mainText.setPosition(550, 70);

	wonderCard1.setTexture(p_game->textureManager.getRef(p_player->playerWonderDeck[0]->getName()));
	wonderCard1.setScale(0.52f, 0.52f);
	wonderCard1.setOrigin(wonderCard1.getGlobalBounds().width, wonderCard1.getGlobalBounds().top);
	wonderCard1.setPosition(975, 125);
	
	wonderCard2.setTexture(p_game->textureManager.getRef(p_player->playerWonderDeck[1]->getName()));
	wonderCard2.setScale(0.52f, 0.52f);
	wonderCard2.setOrigin(wonderCard2.getGlobalBounds().width, wonderCard2.getGlobalBounds().top);
	wonderCard2.setPosition(975, 302.5f);
	
	wonderCard3.setTexture(p_game->textureManager.getRef(p_player->playerWonderDeck[2]->getName()));
	wonderCard3.setScale(0.52f, 0.52f);
	wonderCard3.setOrigin(wonderCard3.getGlobalBounds().width, wonderCard3.getGlobalBounds().top);
	wonderCard3.setPosition(975, 475);
	
	wonderCard4.setTexture(p_game->textureManager.getRef(p_player->playerWonderDeck[3]->getName()));
	wonderCard4.setScale(0.52f, 0.52f);
	wonderCard4.setOrigin(wonderCard4.getGlobalBounds().width, wonderCard4.getGlobalBounds().top);
	wonderCard4.setPosition(975, 652.5f);

	if (canBuildWonder1) buttonWonder1.setFillColor(sf::Color(242, 198, 55));
	else buttonWonder1.setFillColor(sf::Color(133, 142, 155));
	buttonWonder1.setSize(BUTTON_SIZE);
	buttonWonder1.setPosition(700, 200);

	if (canBuildWonder2) buttonWonder2.setFillColor(sf::Color(242, 198, 55));
	else buttonWonder2.setFillColor(sf::Color(133, 142, 155));
	buttonWonder2.setSize(BUTTON_SIZE);
	buttonWonder2.setPosition(700, 370);

	if (canBuildWonder3) buttonWonder3.setFillColor(sf::Color(242, 198, 55));
	else buttonWonder3.setFillColor(sf::Color(133, 142, 155));
	buttonWonder3.setSize(BUTTON_SIZE);
	buttonWonder3.setPosition(700, 545);

	if (canBuildWonder4) buttonWonder4.setFillColor(sf::Color(242, 198, 55));
	else buttonWonder4.setFillColor(sf::Color(133, 142, 155));
	buttonWonder4.setSize(BUTTON_SIZE);
	buttonWonder4.setPosition(700, 725);

	rectButtonWonder1 = buttonWonder1.getGlobalBounds();
	rectButtonWonder2 = buttonWonder2.getGlobalBounds();
	rectButtonWonder3 = buttonWonder3.getGlobalBounds();
	rectButtonWonder4 = buttonWonder4.getGlobalBounds();
}

