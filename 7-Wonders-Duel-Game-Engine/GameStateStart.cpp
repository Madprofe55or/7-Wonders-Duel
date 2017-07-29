#include "GameStateStart.h"
#include "GameState.h"

void GameStateStart::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	//this->game->window.draw(this->game->background);
}

void GameStateStart::update(const float dt)
{
}

void GameStateStart::handleInput()
{
	sf::Event event;

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
		default: break;
		}
	}
}

GameStateStart::GameStateStart(Game * game)
{
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
}

GameStateStart::~GameStateStart()
{
}
