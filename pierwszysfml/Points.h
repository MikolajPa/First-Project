#pragma once
#include<SFML/Graphics.hpp>;
class Points
{
public:
	Points(sf::Font font, int Points);
	~Points();
	sf::Text text;
	void Points_Draw(sf::RenderWindow& window);
private:
	std::string str;
	
};
