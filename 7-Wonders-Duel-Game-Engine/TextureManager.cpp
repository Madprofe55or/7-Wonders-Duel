#include "TextureManager.h"

void TextureManager::loadTexture(const std::string & name, const std::string & fileName)
{
	sf::Texture tex;
	tex.loadFromFile(fileName);

	this->texturesMap[name] = tex;
}

sf::Texture & TextureManager::getRef(const std::string & texture)
{
	return this->texturesMap.at(texture);
}
