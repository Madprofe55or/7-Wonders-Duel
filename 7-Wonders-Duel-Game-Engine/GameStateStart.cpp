#include "GamePlayingState.h"
#include "GameStateStart.h"
#include "GameState.h"

void GameStateStart::draw(const float dt)
{
	game->window.draw(background);
	game->window.draw(title);
	game->window.draw(startGameText);
	game->window.draw(exitGameText);
}

void GameStateStart::update(const float dt)
{
}

void GameStateStart::handleInput(Game * game)
{
	sf::Event event;
	this->game = game;

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
			if (event.key.code == sf::Keyboard::Escape) this->game->window.close();
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (game->inputManager.isObjectClicked(this->exitGameText, event.mouseButton.button, this->game->window) == true)
				{
					this->game->window.close();
				}
				else if (game->inputManager.isObjectClicked(this->startGameText, event.mouseButton.button, this->game->window) == true)
				{
					game->pushState(new GamePlayingState(this->game));
				}
			}
			
		}
		case sf::Event::MouseMoved:
		{
			// These sf::IntRect objects are needed to be able to use .contains() below
			sf::IntRect tempExitRect(this->exitGameText.getPosition().x, this->exitGameText.getPosition().y, this->exitGameText.getGlobalBounds().width, this->exitGameText.getGlobalBounds().height);
			sf::IntRect tempStartRect(this->startGameText.getPosition().x, this->startGameText.getPosition().y, this->startGameText.getGlobalBounds().width, this->startGameText.getGlobalBounds().height);

			if (tempExitRect.contains(game->inputManager.getMousePosition(this->game->window)))
			{
				this->exitGameText.setFillColor(sf::Color::Red);
			}
			else
			{
				this->exitGameText.setFillColor(sf::Color::White);
			}
			if (tempStartRect.contains(game->inputManager.getMousePosition(this->game->window)))
			{
				this->startGameText.setFillColor(sf::Color::Green);
			}
			else
			{
				this->startGameText.setFillColor(sf::Color::White);
			}

		} 
		default: break;
		}
	}

}

GameStateStart::GameStateStart(Game * game)
{
	this->game = game;

	// Background
	this->background.setTexture(game->textureManager.getRef("GameStateStart Background"));

	// Title Card at top
	this->title.setTexture(game->textureManager.getRef("GameStateStart Title"));
	this->title.setOrigin(this->title.getGlobalBounds().width / 2, this->title.getGlobalBounds().height / 2);
	this->title.setPosition(800, 200);

	// Texts for "Start Game" and "Exit"
	this->startGameText.setFont(game->fontManager.getRef("Menu Font"));
	this->exitGameText.setFont(game->fontManager.getRef("Menu Font"));
	this->startGameText.setString("Start Game");
	this->exitGameText.setString("Exit");
	this->startGameText.setFillColor(sf::Color::White);
	this->exitGameText.setFillColor(sf::Color::White);
	this->startGameText.setCharacterSize(50);
	this->exitGameText.setCharacterSize(50);
	this->startGameText.setPosition(800 - 0.5 * this->startGameText.getGlobalBounds().width, 400);
	this->exitGameText.setPosition(800 - 0.5 * this->exitGameText.getGlobalBounds().width, 500);
	
}

