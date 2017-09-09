#pragma once
#include "State.h"
#include "Bird.h"
#include "Pipe.h"
#include "AnimatedGround.h"
#include "PointsText.h"
#include <random>
#include <list>

class GameState :
	public State
{
private:
	sf::Sprite background;
	Bird bird;
	AnimatedGround ground;
	std::list<Pipe> pipes;
	PointsText pointsText;

	std::random_device rd;
	std::mt19937 mt;
	std::uniform_real_distribution<float> dist;

	const int PIPES = 3;
	const float SPACE = 300.0f;

	void addPipe(float x);
	void addNextPipe();
	void checkForPipes();
	void checkForCollisions();
public:
	GameState(GameStateManager* manager, sf::RenderWindow* window);
	virtual void handleEvent(const sf::Event &event);
	virtual void render();
	virtual void update(int deltaTime);
	~GameState();
};

