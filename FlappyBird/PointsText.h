#pragma once
#include <SFML\Graphics.hpp>
class PointsText :
	public sf::Drawable
{
private:
	sf::Text text;
	const float MARGIN = 10.0f;
	int points;
	int screenWidth;

	void centerText();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	PointsText(sf::Font &font, int screenWidth);
	void addPoints();
	~PointsText();
};

