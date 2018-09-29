#include "Monety.h"
Monety::Monety(sf::Vector2f size, sf::Vector2f position, int points)
{
	this->pointsAmount = points;
	body.setSize(size);
	body.setPosition(position);
	body.setFillColor(sf::Color::Yellow);
}


Monety::~Monety()
{
}
void Monety::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Monety::Delete()
{
	body.setPosition(5000.0f, 5000.0f);
}
