#include "InputManager.h"

/* Handles if an sf::Sprite object is clicked
   Must pass sf::Sprite, sf::Mouse::Button, and sf::RenderWindow objects */
bool InputManager::isObjectClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect tempRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

		if (tempRect.contains(sf::Mouse::getPosition()))
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
	sf::IntRect tempRect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);
	sf::Vector2i tempMouse = this->getMousePosition(window);

		if (tempRect.contains(tempMouse))
		{
			return true;
		}
		else return false;

}

/* Returns sf::Vector2i of the mouse position
   Put into beginning of other InputManager functions regarding mouse clicks*/
sf::Vector2i InputManager::getMousePosition(sf::RenderWindow & window)
{
	return sf::Mouse::getPosition(window);
}
