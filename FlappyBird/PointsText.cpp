#include "PointsText.h"

PointsText::PointsText(sf::Font & font, int screenWidth) : screenWidth(screenWidth)
{
	text.setFont(font);
	text.setPosition(0.0f, MARGIN);
	text.setString("0");
	centerText();
}

void PointsText::addPoints()
{
	points++;
	text.setString(std::to_string(points));
	centerText();
}

void PointsText::centerText()
{
	text.setPosition(screenWidth / 2.0f - text.getGlobalBounds().width / 2.0f, text.getPosition().y);
}

void PointsText::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(text, states);
}

PointsText::~PointsText()
{
}
