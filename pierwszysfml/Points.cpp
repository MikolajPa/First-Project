#include "Points.h"



Points::Points(sf::Font font,int Points)
{
	str = "elo";//std::to_string(Points);
	text.setString(str);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
	text.setPosition(250.0f, 250.0f);
}


Points::~Points()
{
}

void Points::Points_Draw(sf::RenderWindow& window)
{
	window.draw(text);
}


