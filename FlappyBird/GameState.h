#pragma once
#include "State.h"
#include "Bird.h"
#include "Pipe.h"
#include "AnimatedGround.h"

class GameState :
	public State
{
private:
	sf::Sprite background;
	Bird bird;
	Pipe pipe;
	AnimatedGround ground;
public:
	GameState(GameStateManager* manager, sf::RenderWindow* window);
	virtual void handleEvent(const sf::Event &event);
	virtual void render();
	virtual void update(int deltaTime);
	~GameState();
};

