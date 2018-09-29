#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
class Monety
{
public:
	Monety(sf::Vector2f size, sf::Vector2f Position,int points);
	~Monety();
	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	int GetPoints() { return pointsAmount; }
	void Delete();
private:
	sf::RectangleShape body;
	int pointsAmount;

};

