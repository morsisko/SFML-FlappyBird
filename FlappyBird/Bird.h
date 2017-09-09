#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"

class Bird :
	public sf::Drawable
{
private:
	Animation animation;
	sf::Sprite sprite;
	float speed = 0.0f;

	static const int TEXTURE_WIDTH = 17;
	static const int TEXTURE_HEIGHT = 12;

	const float GRAVITY = 20.0f;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Bird(sf::Texture& birdTexture);
	void update(int deltaTime);
	void jump();
	~Bird();
};

