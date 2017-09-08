#include "Bird.h"



Bird::Bird() : animation(200)
{
	birdTexture.loadFromFile("assets/bird.png");
	sprite.setTexture(birdTexture);

	for (int i = 0; i != 3; ++i)
		animation.addFrame(sf::IntRect(28 * i, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT));

	animation.setDefaultFrame(sprite);

	sprite.setScale(3.0f, 3.0f);
}

void Bird::update(int deltaTime)
{
	animation.update(deltaTime, sprite);

	speed -= (deltaTime / 1000.0f * GRAVITY);

	sprite.move(0.0f, -speed);
}

void Bird::jump()
{
	speed = 5.0f;
}

void Bird::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}


Bird::~Bird()
{
}
