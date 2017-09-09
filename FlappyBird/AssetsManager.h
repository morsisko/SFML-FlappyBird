#pragma once
#include <SFML\Graphics.hpp>

class AssetsManager
{
public:
	sf::Texture backgroundTexture;
	sf::Texture birdTexture;
	sf::Texture upperPipeTexture;
	sf::Texture bottomPipeTexture;
	sf::Texture splashTexture;
	sf::Texture groundTexture;

	AssetsManager();
	~AssetsManager();
};

