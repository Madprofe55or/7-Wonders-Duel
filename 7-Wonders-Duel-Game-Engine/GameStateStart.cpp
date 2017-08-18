#include "GamePlayingState.h"
#include "GameStateStart.h"
#include "GameState.h"

void GameStateStart::draw(const float dt)
{
	p_game->window.draw(background);
	p_game->window.draw(title);
	p_game->window.draw(startGameText);
	p_game->window.draw(exitGameText);
}

void GameStateStart::update(const float dt)
{
	if (mRotating == true)
	{
		title.setRotation(title.getRotation() + mRotatingSpeed);
		startGameText.setRotation(startGameText.getRotation() + mRotatingSpeed);
		exitGameText.setRotation(exitGameText.getRotation() + mRotatingSpeed);
	}
}

void GameStateStart::handleInput()
{
	sf::Event event;

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
			if (event.key.code == sf::Keyboard::Escape) p_game->window.close();
			else if (event.key.code == sf::Keyboard::R)
			{
				if (mRotating == false) mRotating = true;
				else if (mRotating == true) mRotating = false;
			}
			else if (event.key.code == sf::Keyboard::Up) mRotatingSpeed++;
			else if (event.key.code == sf::Keyboard::Down) mRotatingSpeed--;

			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (p_game->inputManager.isObjectClicked(exitGameText, event.mouseButton.button, p_game->window) == true)
				{
					p_game->window.close();
				}
				else if (p_game->inputManager.isObjectClicked(startGameText, event.mouseButton.button, p_game->window) == true)
				{
					p_game->pushState(new GamePlayingState(p_game));
				}
			}
			
		}
		case sf::Event::MouseMoved:
		{
			// These sf::IntRect objects are needed to be able to use .contains() below
			sf::FloatRect startRect = startGameText.getGlobalBounds();
			sf::FloatRect exitRect = exitGameText.getGlobalBounds();

			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			if (exitRect.contains(mouse))
			{
				exitGameText.setFillColor(sf::Color::Red);
			}
			else
			{
				exitGameText.setFillColor(sf::Color::White);
			}
			if (startRect.contains(mouse))
			{
				startGameText.setFillColor(sf::Color::Green);
			}
			else
			{
				startGameText.setFillColor(sf::Color::White);
			}
		} 
		default: break;
		}
	}

}

GameStateStart::GameStateStart(Game * game)
{
	p_game = game;

	// Background
	background.setTexture(p_game->textureManager.getRef("GameStateStart Background"));

	// Title Card at top
	title.setTexture(p_game->textureManager.getRef("GameStateStart Title"));
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(800, 200);

	// Texts for "Start Game" and "Exit"
	startGameText.setFont(p_game->fontManager.getRef("Menu Font"));
	exitGameText.setFont(p_game->fontManager.getRef("Menu Font"));
	startGameText.setString("Start Game");
	exitGameText.setString("Exit");
	startGameText.setFillColor(sf::Color::White);
	exitGameText.setFillColor(sf::Color::White);
	startGameText.setCharacterSize(50);
	exitGameText.setCharacterSize(50);

	startGameText.setOrigin(startGameText.getLocalBounds().width / 2.0f, startGameText.getLocalBounds().height / 2.0f);
	exitGameText.setOrigin(exitGameText.getLocalBounds().width / 2.0f, exitGameText.getLocalBounds().height / 2.0f);

	startGameText.setPosition(800, 400);
	exitGameText.setPosition(800, 500);

	//startGameText.setPosition(800 - 0.5 * startGameText.getGlobalBounds().width, 400);
	//exitGameText.setPosition(800 - 0.5 * exitGameText.getGlobalBounds().width, 500);
	
}

