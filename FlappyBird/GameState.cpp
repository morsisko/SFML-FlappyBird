#include "GameState.h"
#include "Game.h"


GameState::GameState(GameStateManager* manager, sf::RenderWindow* window) : State(manager, window),
	bird(manager->getAssets().birdTexture),
	pipe(manager->getAssets().upperPipeTexture, manager->getAssets().bottomPipeTexture, 300.0f, 0.0f),
	ground(manager->getAssets().groundTexture, static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y))
{
	background.setTexture(manager->getAssets().backgroundTexture);
	background.setScale(Game::SCALE, Game::SCALE);
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
	window->draw(pipe);
	window->draw(ground);
}

void GameState::update(int deltaTime)
{
	bird.update(deltaTime);
	ground.update(deltaTime);
}


GameState::~GameState()
{
}
