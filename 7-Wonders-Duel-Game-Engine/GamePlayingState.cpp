#include "GamePlayingState.h"

void GamePlayingState::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->background);
	//this->game->window.draw(this->exitText);
	this->game->window.draw(this->mAge1Card1);
	this->game->window.draw(this->mAge1Card2);
	this->game->window.draw(this->mAge1Card3);
	this->game->window.draw(this->mAge1Card4);
	this->game->window.draw(this->mAge1Card5);
	this->game->window.draw(this->mAge1Card6);
	this->game->window.draw(this->mAge1Card7);
	this->game->window.draw(this->mAge1Card8);
	this->game->window.draw(this->mAge1Card9);
	this->game->window.draw(this->mAge1Card10);
	this->game->window.draw(this->mAge1Card11);
	this->game->window.draw(this->mAge1Card12);
	this->game->window.draw(this->mAge1Card13);
	this->game->window.draw(this->mAge1Card14);
	this->game->window.draw(this->mAge1Card15);
	this->game->window.draw(this->mAge1Card16);
	this->game->window.draw(this->mAge1Card17);
	this->game->window.draw(this->mAge1Card18);
	this->game->window.draw(this->mAge1Card19);
	this->game->window.draw(this->mAge1Card20);

}


void GamePlayingState::update(const float dt)
{
}

void GamePlayingState::handleInput(Game * game)
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
	if (poppingState == true) game->popState();
}

GamePlayingState::GamePlayingState(Game * game)
{
	this->game = game;

	//exitText.setFont(game->fontManager.getRef("Menu Font"));
	//exitText.setString("Gameplaying state test: Press Escape to exit to Main Menu");
	//exitText.setPosition(0, 400);
	//exitText.setCharacterSize(50);
	//exitText.setFillColor(sf::Color::White);

	// Setting background
	this->background.setTexture(game->textureManager.getRef("GameStatePlaying Background"));



	mCurrentAge = 1;
	mAge1Card1.setFillColor(sf::Color::Green);
	mAge1Card1.setPosition(mAge1Card1Loc);
	mAge1Card1.setSize(CARD_SIZE);
	mAge1Card2.setFillColor(sf::Color::Green);
	mAge1Card2.setPosition(mAge1Card2Loc);
	mAge1Card2.setSize(CARD_SIZE);

	mAge1Card3.setFillColor(sf::Color::Red);
	mAge1Card3.setPosition(mAge1Card3Loc);
	mAge1Card3.setSize(CARD_SIZE);
	mAge1Card4.setFillColor(sf::Color::Red);
	mAge1Card4.setPosition(mAge1Card4Loc);
	mAge1Card4.setSize(CARD_SIZE);
	mAge1Card5.setFillColor(sf::Color::Red);
	mAge1Card5.setPosition(mAge1Card5Loc);
	mAge1Card5.setSize(CARD_SIZE);

	mAge1Card6.setFillColor(sf::Color::Green);
	mAge1Card6.setPosition(mAge1Card6Loc);
	mAge1Card6.setSize(CARD_SIZE);
	mAge1Card7.setFillColor(sf::Color::Green);
	mAge1Card7.setPosition(mAge1Card7Loc);
	mAge1Card7.setSize(CARD_SIZE);
	mAge1Card8.setFillColor(sf::Color::Green);
	mAge1Card8.setPosition(mAge1Card8Loc);
	mAge1Card8.setSize(CARD_SIZE);
	mAge1Card9.setFillColor(sf::Color::Green);
	mAge1Card9.setPosition(mAge1Card9Loc);
	mAge1Card9.setSize(CARD_SIZE);

	mAge1Card10.setFillColor(sf::Color::Red);
	mAge1Card10.setPosition(mAge1Card10Loc);
	mAge1Card10.setSize(CARD_SIZE);
	mAge1Card11.setFillColor(sf::Color::Red);
	mAge1Card11.setPosition(mAge1Card11Loc);
	mAge1Card11.setSize(CARD_SIZE);
	mAge1Card12.setFillColor(sf::Color::Red);
	mAge1Card12.setPosition(mAge1Card12Loc);
	mAge1Card12.setSize(CARD_SIZE);
	mAge1Card13.setFillColor(sf::Color::Red);
	mAge1Card13.setPosition(mAge1Card13Loc);
	mAge1Card13.setSize(CARD_SIZE);
	mAge1Card14.setFillColor(sf::Color::Red);
	mAge1Card14.setPosition(mAge1Card14Loc);
	mAge1Card14.setSize(CARD_SIZE);

	mAge1Card15.setFillColor(sf::Color::Green);
	mAge1Card15.setPosition(mAge1Card15Loc);
	mAge1Card15.setSize(CARD_SIZE);
	mAge1Card16.setFillColor(sf::Color::Green);
	mAge1Card16.setPosition(mAge1Card16Loc);
	mAge1Card16.setSize(CARD_SIZE);
	mAge1Card17.setFillColor(sf::Color::Green);
	mAge1Card17.setPosition(mAge1Card17Loc);
	mAge1Card17.setSize(CARD_SIZE);
	mAge1Card18.setFillColor(sf::Color::Green);
	mAge1Card18.setPosition(mAge1Card18Loc);
	mAge1Card18.setSize(CARD_SIZE);
	mAge1Card19.setFillColor(sf::Color::Green);
	mAge1Card19.setPosition(mAge1Card19Loc);
	mAge1Card19.setSize(CARD_SIZE);
	mAge1Card20.setFillColor(sf::Color::Green);
	mAge1Card20.setPosition(mAge1Card20Loc);
	mAge1Card20.setSize(CARD_SIZE);



}

GamePlayingState::~GamePlayingState()
{
}
