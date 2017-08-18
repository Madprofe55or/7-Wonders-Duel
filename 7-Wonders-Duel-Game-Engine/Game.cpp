#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameState.h"

// Adds a state on top of state stack
void Game::pushState(GameState * state)
{
	states.push(state);
}

// Removes a state from the top of state stack
void Game::popState()
{
	delete states.top();
	states.pop();
}

// Removes a state from the top of state stack (if there is one) and adds another state
void Game::changeState(GameState * state)
{
	if (!states.empty())
		popState();
	pushState(state);
}

// Returns pointer to top state, if there is one
GameState * Game::peekState()
{
	if (states.empty()) return nullptr;
	return states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;
	
	// while loop for the game window
	while (window.isOpen())
	{
		// time-update controls
		sf::Time timeElapsed = clock.restart();
		float dt = timeElapsed.asSeconds();

		/* looks at state on top of stack and runs functions of that state 
		   if the state stack is empty, it runs the loop again...basically if
		   no state is loaded at the beginning of the game, a black screen is shown */
		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);
		window.clear(sf::Color::Black);
		peekState()->draw(dt);
		window.display();
	}
}

Game::Game()
{
	// Loading textures, but should probably be done depending on state
	loadTextures();
	
	// Loading fonts
	loadFonts();
	
	// Creating the window, with no resizing option
	window.create(sf::VideoMode(Seven_Wonders::GAME_WINDOW_WIDTH, Seven_Wonders::GAME_WINDOW_HEIGHT), "7 Wonders Duel", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	

}

Game::~Game()
{
	// Will remove states one at a time from stack until empty
	while (!states.empty()) popState();
}

void Game::loadTextures()
{
	/* With a small game like this, it's probably ok to load all textures at game creation
	   However, for efficiency, only textures needed for a specific game state should be loaded unless 
	   states are stil stacked.  We can keep doing it this way for now, until we run into problems, if any. 
	   Textures should be defined in the game logic, in some type of container (likely a map). */
	textureManager.loadTexture("Game Board", "Resources/BoardItems/gameboard.png");
	textureManager.loadTexture("GameStateStart Background", "Resources/Backgrounds/gamestartbackground.jpg");
	textureManager.loadTexture("GameStateStart Title", "Resources/Backgrounds/gamestarttitle.png");
	textureManager.loadTexture("GameStatePlaying Background", "Resources/Backgrounds/gameplayingbackground.jpg");
	textureManager.loadTexture("Card-Glassworks", "Resources/CardImages/glassworks.jpg");

	//loading of all wonder texture
	textureManager.loadTexture("The Appian Way", "Resources/WonderCards/TheAppianWay.jpg");
	textureManager.loadTexture("Circus Maximus", "Resources/WonderCards/CircusMaximus.jpg");
	textureManager.loadTexture("The Colossus", "Resources/WonderCards/TheColossus.jpg");
	textureManager.loadTexture("The Great Library", "Resources/WonderCards/TheGreatLibrary.jpg");
	textureManager.loadTexture("The Great Lighthouse", "Resources/WonderCards/TheGreatLighthouse.jpg");
	textureManager.loadTexture("The Hanging Gardens", "Resources/WonderCards/TheHangingGardens.jpg");
	textureManager.loadTexture("The Mausoleum", "Resources/WonderCards/TheMausoleum.jpg");
	textureManager.loadTexture("Piraeus", "Resources/WonderCards/Piraeus.jpg");
	textureManager.loadTexture("The Pyramids", "Resources/WonderCards/ThePyramids.jpg");
	textureManager.loadTexture("The Sphinx", "Resources/WonderCards/TheSphinx.jpg");
	textureManager.loadTexture("The Statue of Zeus", "Resources/WonderCards/Zeus.jpg");
	textureManager.loadTexture("The Temple of Artemis", "Resources/WonderCards/TheTempleofArtemis.jpg");

	world.Setup();
}

void Game::loadFonts()
{
	/* It will be fine loading fonts at game creation since only a few will be needed. */
	fontManager.loadFont("Menu Font", "Resources/Fonts/americancaptain.ttf");
}





