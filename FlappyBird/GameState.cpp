#include "GameState.h"
#include "Game.h"

GameState::GameState(GameStateManager* manager, sf::RenderWindow* window) : State(manager, window),
	mt(rd()),
	pointsText(manager->getAssets().font, window->getSize().x),
	dist(Pipe::SPACE + 1.0f, window->getSize().y - manager->getAssets().groundTexture.getSize().y * Game::SCALE - 1.0f),
	bird(manager->getAssets().birdTexture),
	ground(manager->getAssets().groundTexture, static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y))
{
	background.setTexture(manager->getAssets().backgroundTexture);
	background.setScale(Game::SCALE, Game::SCALE);

	for (int i = 0; i != PIPES; ++i)
		addPipe(window->getSize().x + i * SPACE);
}

void GameState::handleEvent(const sf::Event & event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
		bird.jump();
		break;
	default:
		break;
	}
}

void GameState::render()
{
	window->draw(background);
	window->draw(bird);
	for (auto& pipe : pipes)
		window->draw(pipe);
	window->draw(pointsText);
	window->draw(ground);
}

void GameState::update(int deltaTime)
{
	bird.update(deltaTime);
	ground.update(deltaTime);

	for (auto& pipe : pipes)
		pipe.update(deltaTime);

	checkForPipes();
}

void GameState::addPipe(float x)
{
	pipes.push_back(Pipe(manager->getAssets().upperPipeTexture, manager->getAssets().bottomPipeTexture, x, dist(mt)));
}

void GameState::addNextPipe()
{
	if (pipes.empty())
		return;

	addPipe(pipes.back().getX() + SPACE);
}

void GameState::checkForPipes()
{
	if (pipes.empty())
		return;

	Pipe& frontPipe = pipes.front();
	if (frontPipe.getX() + frontPipe.getWidth() < 0.0f)
	{
		pipes.pop_front();
		addNextPipe();
		pointsText.addPoints();
	}
}



GameState::~GameState()
{
}
