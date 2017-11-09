#include "CardPickerState.h"
#include "WonderBuildingState.h"
#include "NewAgeChoosePlayerState.h"
#include <string>


void CardPickerState::draw(const float dt)
{
	// need to first draw the game playing state that's on the stack underneath
	p_GamePlayingState->draw(dt);
	// the following rectangle is for darkening the gameplaying state underneath
	p_game->window.draw(p_GamePlayingState->rectPickingCard);

	p_game->window.draw(testRectangle);
	p_game->window.draw(testRectangle2);
	p_game->window.draw(cardToDisplay);
	p_game->window.draw(linkerCard);

	p_game->window.draw(textCardName);
	p_game->window.draw(textCostHeader);
	p_game->window.draw(textCoinCost);
	p_game->window.draw(textWoodCost);
	p_game->window.draw(textStoneCost);
	p_game->window.draw(textClayCost);
	p_game->window.draw(textPapyrusCost);
	p_game->window.draw(textGlassCost);

	p_game->window.draw(textCoinCostNum);
	p_game->window.draw(textWoodCostNum);
	p_game->window.draw(textStoneCostNum);
	p_game->window.draw(textClayCostNum);
	p_game->window.draw(textPapyrusCostNum);
	p_game->window.draw(textGlassCostNum);
	p_game->window.draw(buildRectangle);
	p_game->window.draw(discardRectangle);
	p_game->window.draw(buildWonderRectangle);
	p_game->window.draw(textBuild);
	p_game->window.draw(textDiscard);
	p_game->window.draw(textDiscardValue);
	p_game->window.draw(textBuildWonder);
	p_game->window.draw(linkerText);




}

void CardPickerState::update(const float dt)
{
	removeStateAfterWonderBuild();
	removeStateAfterAgePlayerPick();
	
}

void CardPickerState::handleInput()
{
	sf::Event event;
	bool poppingState = false;
	bool wonderBuildState = false;

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
				p_game->world.buildByLink = false;
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
					p_game->world.buildByLink = false;
				}
				else if (p_game->inputManager.isObjectClicked(buildRectangle, event.mouseButton.button, p_game->window) == true && canBuildCard == true)
				{
					// build the card
					p_game->world.buildCard(p_GamePlayingState->clickedCardIndex);
					// move the sprite for the card off the screen so that it can't be clicked again
					p_GamePlayingState->mCardSprites[p_GamePlayingState->clickedCardIndex].setPosition(-400.0f, -400.0f);
					// checking if last card was built, thus triggering a new age
					if (p_game->world.checkForNewAge() == true) p_GamePlayingState->resetSprites();

					buildCardSound.play();

					poppingState = true;
				}
				else if (p_game->inputManager.isObjectClicked(discardRectangle, event.mouseButton.button, p_game->window) == true)
				{
					// discard the card
					p_game->world.discardCard(p_GamePlayingState->clickedCardIndex);
					// move the sprite for the card off the screen so that it can't be clicked again
					p_GamePlayingState->mCardSprites[p_GamePlayingState->clickedCardIndex].setPosition(-400.0f, -400.0f);
					// checking if last card was built, thus triggering a new age
					if (p_game->world.checkForNewAge() == true) p_GamePlayingState->resetSprites();

					discardCardSound.play();

					poppingState = true;
				}
				else if (p_game->inputManager.isObjectClicked(buildWonderRectangle, event.mouseButton.button, p_game->window) == true)
				{
					wonderBuildState = true;
				}
			}
		}
		case sf::Event::MouseMoved:
		{
			// These sf::IntRect objects are needed to be able to use .contains() below
			// REFACTORING: These rectangles can be defined as members in this class, instead of instatiating them here with each mouse movement
			sf::FloatRect buildRect = buildRectangle.getGlobalBounds();
			sf::FloatRect discardRect = discardRectangle.getGlobalBounds();
			sf::FloatRect buildWonderRect = buildWonderRectangle.getGlobalBounds();

			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			if (canBuildCard)
			{
				if (buildRect.contains(mouse))
				{
					buildRectangle.setFillColor(sf::Color(51, 153, 255));
				}
				else
				{
					buildRectangle.setFillColor(sf::Color(0, 204, 51));
				}
			}

			if (discardRect.contains(mouse))
			{
				discardRectangle.setFillColor(sf::Color(51, 153, 255));
			}
			else
			{
				discardRectangle.setFillColor(sf::Color(0, 204, 51));
			}
			if (buildWonderRect.contains(mouse))
			{
				buildWonderRectangle.setFillColor(sf::Color(51, 153, 255));
			}
			else
			{
				buildWonderRectangle.setFillColor(sf::Color(0, 204, 51));
			}


		}
		default: break;
		} // end of switch
	} // end of while

	if (wonderBuildState == true)
	{
		p_game->pushState(new WonderBuildingState(p_game, this, p_GamePlayingState));
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
	p_card = card;

	discardCardSound.setBuffer(p_game->soundManager.soundMap.at("Discard Card"));
	buildCardSound.setBuffer(p_game->soundManager.soundMap.at("Build Card"));
	
	testRectangle.setFillColor(sf::Color(132, 132, 18, 200));
	testRectangle.setSize(CARD_GUI_SIZE);
	testRectangle.setPosition(500, 250);

	testRectangle2.setFillColor(sf::Color(51, 204, 51, 200));
	testRectangle2.setSize(CARD_GUI_SIZE_2);
	testRectangle2.setPosition(500, 250);

	cardToDisplay.setTexture(game->textureManager.getRef(card->getName()));
	cardToDisplay.setPosition(500, 300);

	for (vector<Card*>::iterator it = p_game->world.currentPlayer->playerCity.begin(); it != p_game->world.currentPlayer->playerCity.end(); ++it)
	{
		if ((*it)->getLinkerValue1() == card->getLinkerValue1() && (*it)->getLinkerValue1() != NOLINKVALUE)
		{
			linkerCard.setTexture(game->textureManager.getRef((*it)->getName()));
			linkerCard.setPosition(250, 300);
			break;
		}
		else if ((*it)->getLinkerValue2() == card->getLinkerValue2() && (*it)->getLinkerValue2() != NOLINKVALUE)

		{
			linkerCard.setTexture(game->textureManager.getRef((*it)->getName()));
			linkerCard.setPosition(250, 300);
			break;
		}
	}
	
	textCardName.setFont(p_game->fontManager.getRef("Menu Font"));
	textCardName.setString(card->getName());
	textCardName.setCharacterSize(40);
	textCardName.setFillColor(sf::Color::White);
	textCardName.setOrigin(textCardName.getGlobalBounds().width / 2.0f, textCardName.getGlobalBounds().height / 2.0f);
	textCardName.setPosition(800, 265);

	textCostHeader.setFont(p_game->fontManager.getRef("Menu Font"));
	textCostHeader.setString("Cost to Build");
	textCostHeader.setCharacterSize(30);
	textCostHeader.setFillColor(sf::Color::White);
	textCostHeader.setPosition(730, 300);

	textCoinCost.setFont(p_game->fontManager.getRef("Menu Font"));
	textCoinCost.setString("Coins:");
	textCoinCost.setCharacterSize(20);
	textCoinCost.setFillColor(sf::Color::White);
	textCoinCost.setPosition(730, 350);

	textWoodCost.setFont(p_game->fontManager.getRef("Menu Font"));
	textWoodCost.setString("Wood:");
	textWoodCost.setCharacterSize(20);
	textWoodCost.setFillColor(sf::Color::White);
	textWoodCost.setPosition(730, 390);

	textStoneCost.setFont(p_game->fontManager.getRef("Menu Font"));
	textStoneCost.setString("Stone:");
	textStoneCost.setCharacterSize(20);
	textStoneCost.setFillColor(sf::Color::White);
	textStoneCost.setPosition(730, 430);

	textClayCost.setFont(p_game->fontManager.getRef("Menu Font"));
	textClayCost.setString("Clay:");
	textClayCost.setCharacterSize(20);
	textClayCost.setFillColor(sf::Color::White);
	textClayCost.setPosition(730, 470);

	textPapyrusCost.setFont(p_game->fontManager.getRef("Menu Font"));
	textPapyrusCost.setString("Papyrus:");
	textPapyrusCost.setCharacterSize(20);
	textPapyrusCost.setFillColor(sf::Color::White);
	textPapyrusCost.setPosition(730, 510);

	textGlassCost.setFont(p_game->fontManager.getRef("Menu Font"));
	textGlassCost.setString("Glass:");
	textGlassCost.setCharacterSize(20);
	textGlassCost.setFillColor(sf::Color::White);
	textGlassCost.setPosition(730, 550);

	textCoinCostNum.setFont(p_game->fontManager.getRef("Menu Font"));
	textCoinCostNum.setString(to_string(card->getCoinCost()));
	textCoinCostNum.setCharacterSize(20);
	textCoinCostNum.setFillColor(sf::Color::White);
	textCoinCostNum.setPosition(850, 350);

	textWoodCostNum.setFont(p_game->fontManager.getRef("Menu Font"));
	textWoodCostNum.setString(to_string(card->getWoodCost()));
	textWoodCostNum.setCharacterSize(20);
	textWoodCostNum.setFillColor(sf::Color::White);
	textWoodCostNum.setPosition(850, 390);

	textStoneCostNum.setFont(p_game->fontManager.getRef("Menu Font"));
	textStoneCostNum.setString(to_string(card->getStoneCost()));
	textStoneCostNum.setCharacterSize(20);
	textStoneCostNum.setFillColor(sf::Color::White);
	textStoneCostNum.setPosition(850, 430);

	textClayCostNum.setFont(p_game->fontManager.getRef("Menu Font"));
	textClayCostNum.setString(to_string(card->getClayCost()));
	textClayCostNum.setCharacterSize(20);
	textClayCostNum.setFillColor(sf::Color::White);
	textClayCostNum.setPosition(850, 470);

	textPapyrusCostNum.setFont(p_game->fontManager.getRef("Menu Font"));
	textPapyrusCostNum.setString(to_string(card->getPapyrusCost()));
	textPapyrusCostNum.setCharacterSize(20);
	textPapyrusCostNum.setFillColor(sf::Color::White);
	textPapyrusCostNum.setPosition(850, 510);

	textGlassCostNum.setFont(p_game->fontManager.getRef("Menu Font"));
	textGlassCostNum.setString(to_string(card->getGlassCost()));
	textGlassCostNum.setCharacterSize(20);
	textGlassCostNum.setFillColor(sf::Color::White);
	textGlassCostNum.setPosition(850, 550);

	if (p_game->world.canBuild(*p_game->world.currentPlayer, *p_card)) canBuildCard = true;
	else canBuildCard = false;

	if (card->getExposed())
	{
		if (canBuildCard)
		{
			buildRectangle.setFillColor(sf::Color(0, 204, 51));
		}
		else
		{
			buildRectangle.setFillColor(sf::Color(133, 142, 155));
		}
		buildRectangle.setSize(BUTTON_SIZE);
		buildRectangle.setOrigin(buildRectangle.getGlobalBounds().width / 2.0f, buildRectangle.getGlobalBounds().height / 2.0f);
		buildRectangle.setPosition(1025, 400);


		discardRectangle.setFillColor(sf::Color(0, 204, 51));
		discardRectangle.setSize(BUTTON_SIZE);
		discardRectangle.setOrigin(discardRectangle.getGlobalBounds().width / 2.0f, discardRectangle.getGlobalBounds().height / 2.0f);
		discardRectangle.setPosition(1025, 475);


		buildWonderRectangle.setFillColor(sf::Color(0, 204, 51));
		buildWonderRectangle.setSize(BUTTON_SIZE);
		buildWonderRectangle.setOrigin(buildWonderRectangle.getGlobalBounds().width / 2.0f, buildWonderRectangle.getGlobalBounds().height / 2.0f);
		buildWonderRectangle.setPosition(1025, 550);

		textBuild.setFont(p_game->fontManager.getRef("Menu Font"));
		textBuild.setString("Build (" + to_string(p_game->world.goldCost(*p_game->world.currentPlayer, *card)) + ")");
		textBuild.setCharacterSize(25);
		textBuild.setFillColor(sf::Color::White);
		textBuild.setOrigin(textBuild.getGlobalBounds().width / 2.0f, textBuild.getGlobalBounds().height / 2.0f);
		textBuild.setPosition(buildRectangle.getPosition());

		textDiscard.setFont(p_game->fontManager.getRef("Menu Font"));
		textDiscard.setString("Discard (" + to_string(p_game->world.currentPlayer->getDiscardGoldValue()) + ")");
		textDiscard.setCharacterSize(25);
		textDiscard.setFillColor(sf::Color::White);
		textDiscard.setOrigin(textDiscard.getGlobalBounds().width / 2.0f, textDiscard.getGlobalBounds().height / 2.0f);
		textDiscard.setPosition(discardRectangle.getPosition());

		/*textDiscardValue.setFont(p_game->fontManager.getRef("Menu Font"));
		textDiscardValue.setString(to_string(p_game->world.currentPlayer->getDiscardGoldValue()));
		textDiscardValue.setCharacterSize(25);
		textDiscardValue.setOrigin(textDiscardValue.getGlobalBounds().width / 2.0f, textDiscardValue.getGlobalBounds().height / 2.0f);
		textDiscardValue.setPosition(discardRectangle.getPosition().x - 100, discardRectangle.getPosition().y);*/

		textBuildWonder.setFont(p_game->fontManager.getRef("Menu Font"));
		textBuildWonder.setString("BuildWonder");
		textBuildWonder.setCharacterSize(25);
		textBuildWonder.setFillColor(sf::Color::White);
		textBuildWonder.setOrigin(textBuildWonder.getGlobalBounds().width / 2.0f, textBuildWonder.getGlobalBounds().height / 2.0f);
		textBuildWonder.setPosition(buildWonderRectangle.getPosition());

		if (p_game->world.buildByLink == true)
		{
			linkerText.setFont(p_game->fontManager.getRef("Menu Font"));
			linkerText.setString("Can build by linking");
			linkerText.setCharacterSize(20);
			linkerText.setFillColor(sf::Color::White);
			linkerText.setRotation(90);
			linkerText.setPosition(495, 400);
		}

	}

}

void CardPickerState::removeStateAfterWonderBuild()
{
	if (builtWonder == true) p_game->popState();
}

void CardPickerState::removeStateAfterAgePlayerPick()
{
	if (playerChosen == true) p_game->popState();
}



