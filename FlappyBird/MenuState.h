#pragma once
#include "State.h"
#include "SimpleButton.h"
#include "GameState.h"
#include <iostream>
class MenuState :
	public State
{
private:
	const float BUTTON_SPACE = 20.0f;
	
	sf::Font font;
	bool sounds = false;
	SimpleButton playBtn;
	SimpleButton soundBtn;
	virtual void play();
	void changeSoundState();
public:
	MenuState(GameStateManager* manager, sf::RenderWindow* window);
	virtual void handleEvent(const sf::Event &event);
	virtual void render();
	virtual void update(int deltaTime);
	~MenuState();
};

