#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
public:
	// Adds a texture from a file
	void loadTexture(const std::string & name, const std::string & fileName);

	// Get a texture by passing an id
	sf::Texture& getRef(const std::string & texture);
		
	TextureManager() {};
	~TextureManager() {};
private:
	// Textures map
	std::map<std::string, sf::Texture> texturesMap;
};

#endif // TEXTUREMANAGER_H

