#include <SFML/Graphics.hpp>


class InputManager
{
public:
	/* Checks if an sf::Sprite object is clicked
	Must pass sf::Sprite, sf::Mouse::Button, and sf::RenderWindow objects */
	bool isObjectClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow & window);

	/* Checks if an sf::Text object is clicked
	Must pass sf::Sprite, sf::Mouse::Button, and sf::RenderWindow objects */
	bool isObjectClicked(sf::Text text, sf::Mouse::Button button, sf::RenderWindow & window);

	/* Returns sf::Vector2i of the mouse position
	Put into beginning of other InputManager functions regarding mouse clicks*/
	sf::Vector2i getMousePosition(sf::RenderWindow & window);

	// Constructor and destructor functions are not needed
	InputManager() {};
	~InputManager() {};
};

