#pragma once
#include<SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* Texture, sf::Vector2u imageCount);
	~Animation();

	void Update(int row,float deltaTime, bool faceRight, float switchTime);

public:
	sf::IntRect uvRect;
	

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float switchTime;
	float totalTime;
	
};

