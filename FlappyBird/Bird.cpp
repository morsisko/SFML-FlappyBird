#include "Bird.h"
#include "Game.h"


Bird::Bird(sf::Texture& birdTexture) : animation(200)
{
	sprite.setTexture(birdTexture);

	for (int i = 0; i != 3; ++i)
		animation.addFrame(sf::IntRect(28 * i, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT));

	animation.setDefaultFrame(sprite);

	//sprite.setPosition(200, 200);
	sprite.setScale(Game::SCALE, Game::SCALE);
	//sprite.setOrigin(birdTexture.getSize().x * sprite.getScale().x / 2, birdTexture.getSize().y * sprite.getScale().y / 2);
}

void Bird::update(int deltaTime)
{
	animation.update(deltaTime, sprite);

	speed -= (deltaTime / 1000.0f * GRAVITY);

	sprite.move(0.0f, -speed);
}

void Bird::jump()
{
	speed = 7.5f;
	//sprite.setRotation(75.0f);
}

void Bird::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}


Bird::~Bird()
{
}
