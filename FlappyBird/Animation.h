#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class Animation
{
private:
	std::vector<sf::IntRect> frames;
	int currentFrame = 0;
	int updateMiliseconds = 0;
	int milisecondsPerFrame = 0;
public:
	Animation(int milisecondsPerFrame);
	void addFrame(sf::IntRect rect);
	void update(int deltaTime, sf::Sprite& sprite);
	void setDefaultFrame(sf::Sprite& sprite);
	~Animation();
};

