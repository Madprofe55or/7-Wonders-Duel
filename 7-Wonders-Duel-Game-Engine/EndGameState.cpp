#include "EndGameState.h"

EndGameState::EndGameState(Game *game, GamePlayingState *gamePlayingState)
{
	p_game = game;
	p_GamePlayingState = gamePlayingState;

	//background.setTexture(p_game->textureManager.getRef("GameStatePlaying Background"));

	militaryVictoryBackground.setTexture(p_game->textureManager.getRef("Victory Background"));
	scienceVictoryBackground.setTexture(p_game->textureManager.getRef("Science Background"));
	civilianVictoryBackground.setTexture(p_game->textureManager.getRef("Civilian Background"));




	
	player1MilitaryvictoryBanner.setCharacterSize(65);
	player1MilitaryvictoryBanner.setFillColor(sf::Color::White);
	player1MilitaryvictoryBanner.setFont(p_game->fontManager.getRef("Menu Font"));
	player1MilitaryvictoryBanner.setString("Congratulations Player 1 has Won by Military Victory!");
	player1MilitaryvictoryBanner.setPosition(50, 300);

	player2MilitaryvictoryBanner.setCharacterSize(65);
	player2MilitaryvictoryBanner.setFillColor(sf::Color::White);
	player2MilitaryvictoryBanner.setFont(p_game->fontManager.getRef("Menu Font"));
	player2MilitaryvictoryBanner.setString("Congratulations Player 2 has Won by Military Victory!");
	player2MilitaryvictoryBanner.setPosition(50, 300);

	player1SciencevictoryBanner.setCharacterSize(65);
	player1SciencevictoryBanner.setFillColor(sf::Color::White);
	player1SciencevictoryBanner.setFont(p_game->fontManager.getRef("Menu Font"));
	player1SciencevictoryBanner.setString("Congratulations Player 1 has Won by Science Victory!");
	player1SciencevictoryBanner.setPosition(50, 400);

	player2SciencevictoryBanner.setCharacterSize(65);
	player2SciencevictoryBanner.setFillColor(sf::Color::White);
	player2SciencevictoryBanner.setFont(p_game->fontManager.getRef("Menu Font"));
	player2SciencevictoryBanner.setString("Congratulations Player 2 has Won by Science Victory!");
	player2SciencevictoryBanner.setPosition(50, 400);

	player1CivilianvictoryBanner.setCharacterSize(65);
	player1CivilianvictoryBanner.setFillColor(sf::Color::White);
	player1CivilianvictoryBanner.setFont(p_game->fontManager.getRef("Menu Font"));
	player1CivilianvictoryBanner.setString("Congratulations Player 1 has Won by Civilian Victory!");
	player1CivilianvictoryBanner.setPosition(50, 300);

	player2CivilianvictoryBanner.setCharacterSize(65);
	player2CivilianvictoryBanner.setFillColor(sf::Color::White);
	player2CivilianvictoryBanner.setFont(p_game->fontManager.getRef("Menu Font"));
	player2CivilianvictoryBanner.setString("Congratulations Player 2 has Won by Civilian Victory!");
	player2CivilianvictoryBanner.setPosition(50, 300);

	playAgain.setCharacterSize(45);
	playAgain.setFillColor(sf::Color::White);
	playAgain.setFont(p_game->fontManager.getRef("Menu Font"));
	playAgain.setString("Play Again?");
	playAgain.setPosition(500, 500);

	exit.setCharacterSize(45);
	exit.setFillColor(sf::Color::White);
	exit.setFont(p_game->fontManager.getRef("Menu Font"));
	exit.setString("Exit");
	exit.setPosition(700, 500);
}

EndGameState::~EndGameState()
{
}

void EndGameState::draw(const float dt)
{
	
	if(p_game->world.player1MilitaryVictory)
	{
		p_game->window.draw(militaryVictoryBackground);
		p_game->window.draw(player1MilitaryvictoryBanner);
	}
	
	if (p_game->world.player2MilitaryVictory)
	{
		p_game->window.draw(militaryVictoryBackground);
		p_game->window.draw(player2MilitaryvictoryBanner);
	}

	if(p_game->world.player1ScienceVictory)
	{
		p_game->window.draw(scienceVictoryBackground);
		p_game->window.draw(player1SciencevictoryBanner);
	}
	
	if(p_game->world.player2ScienceVictory)
	{ 
		p_game->window.draw(scienceVictoryBackground);
		p_game->window.draw(player2SciencevictoryBanner);
	}
	
	if(p_game->world.player1CivilianVictory)
		{
		p_game->window.draw(civilianVictoryBackground);
		p_game->window.draw(player1CivilianvictoryBanner);
	}
	
	if(p_game->world.player2CivlianVictory)
	{
		p_game->window.draw(civilianVictoryBackground);
		p_game->window.draw(player2CivilianvictoryBanner);
	}
	
	p_game->window.draw(playAgain);
	p_game->window.draw(exit);

}

void EndGameState::update(const float dt)
{
}

void EndGameState::handleInput()
{
	bool poppingState = false;
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
			if (event.key.code == sf::Keyboard::Escape)
			{
				p_game->window.close();
				break;
			}
		}

		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (p_game->inputManager.isObjectClicked(exit, event.mouseButton.button, p_game->window) == true)
				{
					p_game->window.close();
					break;
				}
				if (p_game->inputManager.isObjectClicked(playAgain, event.mouseButton.button, p_game->window) == true)
				{
					poppingState = true;
					p_game->world.playAgain=true;
					p_game->world.ExitGame();
					break;

				}
			}
		}

		case sf::Event::MouseMoved:
		{
			// These sf::IntRect objects are needed to be able to use .contains() below
			sf::FloatRect playAgainRect = playAgain.getGlobalBounds();
			sf::FloatRect exitRect = exit.getGlobalBounds();

			sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

			if (exitRect.contains(mouse))
			{
				exit.setFillColor(sf::Color::Red);
			}
			else
			{
				exit.setFillColor(sf::Color::White);
			}
			if (playAgainRect.contains(mouse))
			{
				playAgain.setFillColor(sf::Color::Green);
			}
			else
			{
				playAgain.setFillColor(sf::Color::White);
			}
		}

		default: break;

	
		}
	}

	if (poppingState == true)
	{
		p_game->popState();
	}

}




