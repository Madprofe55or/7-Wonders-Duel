#include "InputManager.h"

/* Handles if an sf::Sprite object is clicked
   Must pass sf::Sprite, sf::Mouse::Button, and sf::RenderWindow objects */
bool InputManager::isObjectClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		sf::FloatRect tempRect = sprite.getGlobalBounds();

		if (tempRect.contains(mouse))
		{
			return true;
		}

	}

	return false;
}

/* Handles if an sf::Text object is clicked
Must pass sf::Sprite, sf::Mouse::Button, and sf::RenderWindow objects */
bool InputManager::isObjectClicked(sf::Text text, sf::Mouse::Button button, sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		sf::FloatRect tempRect = text.getGlobalBounds();

		if (tempRect.contains(mouse))
		{
			return true;
		}

	}

	return false;
}

bool InputManager::isObjectClicked(sf::RectangleShape rectangle, sf::Mouse::Button button, sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		sf::FloatRect tempRect = rectangle.getGlobalBounds();

		if (tempRect.contains(mouse))
		{
			return true;
		}

	}

	return false;
}

/* Returns sf::Vector2i of the mouse position
   Put into beginning of other InputManager functions regarding mouse clicks*/
sf::Vector2i InputManager::getMousePosition(sf::RenderWindow & window)
{
	return sf::Mouse::getPosition(window);
}
