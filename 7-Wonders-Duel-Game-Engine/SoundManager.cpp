#include "SoundManager.h"

void SoundManager::loadSound(const std::string & name, const std::string & fileName)
{
	sf::SoundBuffer sound;
	if (!sound.loadFromFile(fileName))
	{
		int i;  // testing
		i = 12; // testing
	}

	this->soundMap[name] = sound;
}

sf::SoundBuffer SoundManager::getRef(const std::string & sound)
{
	return this->soundMap.at(sound);
}
