#include "Bird.h"
#include "Game.h"


Bird::Bird(sf::Texture& birdTexture) : animation(200)
{
	sprite.setTexture(birdTexture);

	for (int i = 0; i != 3; ++i)
		animation.addFrame(sf::IntRect(28 * i, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT));

	animation.setDefaultFrame(sprite);

	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(Game::SCALE, Game::SCALE);
	sprite.setPosition(100, 100);
}

void Bird::update(int deltaTime)
{
	animation.update(deltaTime, sprite);

	speed -= (deltaTime / 1000.0f * GRAVITY);

	sprite.move(0.0f, -speed);
	if (sprite.getRotation() >= 360.0f - JUMP_ROTATE || sprite.getRotation() <= 90.0f)
		sprite.rotate(ROTATE * deltaTime / 1000);
}

void Bird::jump()
{
	speed = JUMP_SPEED;
	sprite.setRotation(-JUMP_ROTATE);
}

void Bird::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}


Bird::~Bird()
{
}
