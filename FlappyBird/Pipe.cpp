#include "Pipe.h"
#include "Game.h"

Pipe::Pipe(sf::Texture& upperTexture, sf::Texture& bottomTexture, float x, float y)
{
	upperPipe.setTexture(upperTexture);
	bottomPipe.setTexture(bottomTexture);

	upperPipe.setScale(Game::SCALE, Game::SCALE);
	bottomPipe.setScale(Game::SCALE, Game::SCALE);

	bottomPipe.setPosition(x, y);
	upperPipe.setPosition(x, y - bottomPipe.getGlobalBounds().height - SPACE);
}

void Pipe::update(int ms)
{
	upperPipe.move(-SPEED * ms / 1000.0f, 0.0f);
	bottomPipe.move(-SPEED * ms / 1000.0f, 0.0f);
}

float Pipe::getX()
{
	return upperPipe.getPosition().x;
}

float Pipe::getWidth()
{
	return upperPipe.getGlobalBounds().width;
}

bool Pipe::checkCollision(Bird & bird)
{
	return (Collision::BoundingBoxTest(bird.getSprite(), upperPipe) || Collision::BoundingBoxTest(bird.getSprite(), bottomPipe));
}

void Pipe::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(upperPipe, states);
	target.draw(bottomPipe, states);
}



Pipe::~Pipe()
{

}
