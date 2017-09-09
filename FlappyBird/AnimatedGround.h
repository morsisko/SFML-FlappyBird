#pragma once
#include <SFML\Graphics.hpp>


class AnimatedGround :
	public sf::Drawable
{
private:
	sf::Sprite sprite;
	float screenWidth;

	const float SPEED = 100.0f;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	AnimatedGround(sf::Texture& texture, float screenWidth, float screenHeight);
	void update(int ms);
	~AnimatedGround();
};

