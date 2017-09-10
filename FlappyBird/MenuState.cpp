#include "MenuState.h"




MenuState::MenuState(GameStateManager* manager, sf::RenderWindow* window) : State(manager, window),
	playBtn(std::bind(&MenuState::play, this)),
	soundBtn(std::bind(&MenuState::changeSoundState, this))
{
	playBtn.setFont(manager->getAssets().font);
	playBtn.setString("Play");
	playBtn.setCharacterSize(50);
	playBtn.setPosition(window->getSize().x / 2 - playBtn.getGlobalBounds().width / 2, window->getSize().y / 2 - playBtn.getGlobalBounds().height / 2);

	soundBtn.setFont(manager->getAssets().font);
	soundBtn.setString("Sounds: " + std::to_string(sounds));
	soundBtn.setCharacterSize(50);
	soundBtn.setPosition(window->getSize().x / 2 - soundBtn.getGlobalBounds().width / 2, playBtn.getPosition().y + playBtn.getGlobalBounds().height + BUTTON_SPACE);
}

void MenuState::handleEvent(const sf::Event & event)
{
	playBtn.handleEvent(event);
	soundBtn.handleEvent(event);
}

void MenuState::render()
{
	window->draw(playBtn);
	window->draw(soundBtn);
}

void MenuState::update(int deltaTime)
{
}

void MenuState::play()
{
	manager->setState(std::make_unique<GameState>(manager, window, sounds));
}

void MenuState::changeSoundState()
{
	sounds = !sounds;

	soundBtn.setString("Sounds: " + std::to_string(sounds));
}

MenuState::~MenuState()
{
}
