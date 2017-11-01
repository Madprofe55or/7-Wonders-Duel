#include "NewAgeChoosePlayerState.h"

void NewAgeChoosePlayerState::draw(const float dt)
{

	p_GamePlayingState->draw(dt);

	p_game->window.draw(mainArea);
	p_game->window.draw(instructions);
	p_game->window.draw(player1Text);
	p_game->window.draw(player2Text);
	p_game->window.draw(player1Button);
	p_game->window.draw(player2Button);

	if (p_game->world.compareMilitary())
	{
		p_game->window.draw(player1ChooseText);
	}

	else
	{ 
		p_game->window.draw(player2ChooseText);
	}
}

void NewAgeChoosePlayerState::update(const float dt)
{
}

void NewAgeChoosePlayerState::handleInput()
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
				if (event.mouseButton.button == sf::Mouse::Left)
				{

					if (p_game->inputManager.isObjectClicked(player1Button, event.mouseButton.button, p_game->window) == true)
					{
						p_game->world.player1Chosen = true;
						p_game->world.ChoosePlayer();
						poppingState = true;
					}
					if (p_game->inputManager.isObjectClicked(player2Button, event.mouseButton.button, p_game->window) == true)
					{
						p_game->world.player2Chosen = true;
						p_game->world.ChoosePlayer();
						poppingState = true;
					}
				}
			}
			case sf::Event::MouseMoved:
			{

				sf::Vector2f mouse = p_game->window.mapPixelToCoords(sf::Mouse::getPosition(p_game->window));

				
					if (player1ButtonRect.contains(mouse))
					{
						player1Button.setFillColor(sf::Color(51, 153, 255));
					}
					else
					{
						player1Button.setFillColor(sf::Color(0, 204, 51));
					}

				if (player2ButtonRect.contains(mouse))
				{
					player2Button.setFillColor(sf::Color(51, 153, 255));
				}
				else
				{
					player2Button.setFillColor(sf::Color(0, 204, 51));
				}


			}
			default: break;
			} // end of switch
		} // end of while

		if (poppingState == true)
		{
			p_game->world.checkForChoosePlayer = false;
			p_game->world.player1Chosen = false;
			p_game->world.player2Chosen = false;
			p_game->popState(); // state is popped here since there is no while loop to return to at this point
			
		}
	}

NewAgeChoosePlayerState::NewAgeChoosePlayerState(Game * game, GamePlayingState * gameplayingstate)
{
	p_game = game;
	p_GamePlayingState = gameplayingstate;
	p_player = p_game->world.currentPlayer;

	mainArea.setSize(MAIN_AREA_SIZE);
	mainArea.setPosition(500, 75);
	mainArea.setFillColor(sf::Color(51, 153, 255, 200));

	instructions.setString(" Choose Who Will Go First in Age " + to_string(p_game->world.getAge()));
	instructions.setPosition(600, 150);
	instructions.setFont(p_game->fontManager.getRef("Menu Font"));
	instructions.setCharacterSize(20);
	instructions.setFillColor(sf::Color::White);

	player1Text.setString("Player 1");
	player1Text.setPosition(750, 200);
	player1Text.setFont(p_game->fontManager.getRef("Menu Font"));
	player1Text.setCharacterSize(25);
	player1Text.setFillColor(sf::Color::White);

	player2Text.setString("Player 2");
	player2Text.setPosition(750, 300);
	player2Text.setFont(p_game->fontManager.getRef("Menu Font"));
	player2Text.setCharacterSize(25);
	player2Text.setFillColor(sf::Color::White);

	player1Button.setPosition(600, 200);
	player1Button.setSize(BUTTON_SIZE);
	player1Button.setFillColor(sf::Color(51, 153, 255, 0));
	player1ButtonRect=player1Button.getGlobalBounds();

	player2Button.setPosition(600, 300);
	player2Button.setSize(BUTTON_SIZE);
	player2Button.setFillColor(sf::Color(51, 153, 255, 0));
	player2ButtonRect = player2Button.getGlobalBounds();

	player1ChooseText.setString("Player 1");
	player1ChooseText.setPosition(535, 150);
	player1ChooseText.setFont(p_game->fontManager.getRef("Menu Font"));
	player1ChooseText.setCharacterSize(20);
	player1ChooseText.setFillColor(sf::Color::White);

	player2ChooseText.setString("Player 2");
	player2ChooseText.setPosition(535, 150);
	player2ChooseText.setFont(p_game->fontManager.getRef("Menu Font"));
	player2ChooseText.setCharacterSize(20);
	player2ChooseText.setFillColor(sf::Color::White);



}

