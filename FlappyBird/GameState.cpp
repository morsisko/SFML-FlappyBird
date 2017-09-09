#include "GameState.h"
#include "Game.h"

GameState::GameState(GameStateManager* manager, sf::RenderWindow* window) : State(manager, window),
	mt(rd()),
	pointsText(manager->getAssets().font, window->getSize().x),
	dist(Pipe::SPACE + 1.0f, window->getSize().y - manager->getAssets().groundTexture.getSize().y * Game::SCALE - 1.0f),
	bird(manager->getAssets().birdTexture, window->getSize().y - manager->getAssets().groundTexture.getSize().y * Game::SCALE),
	ground(manager->getAssets().groundTexture, window->getSize().x, window->getSize().y)
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
	{
		bird.jump();
		if (bird.isAlive())
			manager->getAssets().wingSound.play();
		break;
	}
	case sf::Event::KeyReleased:
	{
		if (!bird.isAlive())
			manager->setState(std::make_unique<GameState>(manager, window));
		break;
	}
	default:
		break;
	}
}

void GameState::render()
{
	window->draw(background);
	for (auto& pipe : pipes)
		window->draw(pipe);
	window->draw(bird);
	window->draw(pointsText);
	window->draw(ground);
}

void GameState::update(int deltaTime)
{
	bird.update(deltaTime);

	if (!bird.isAlive())
		return;

	ground.update(deltaTime);

	for (auto& pipe : pipes)
		pipe.update(deltaTime);

	checkForPipes();
	checkForCollisions();
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
		addPoint();
	}
}

void GameState::checkForCollisions()
{
	if (ground.checkForCollision(bird))
		killBird();

	else if (pipes.empty())
		return;

	else if (pipes.front().checkCollision(bird))
		killBird();
}

void GameState::killBird()
{
	bird.kill();
	manager->getAssets().hitSound.play();
}

void GameState::addPoint()
{
	pointsText.addPoints();
	manager->getAssets().pointSound.play();
}



GameState::~GameState()
{
}
