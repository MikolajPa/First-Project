#include "Animation.h"
#include<iostream>


Animation::Animation(sf::Texture* Texture, sf::Vector2u imageCount)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	std::cout << switchTime;
		currentImage.x = 0;
		uvRect.width = Texture->getSize().x / float(imageCount.x);
		uvRect.height = Texture->getSize().y / float(imageCount.y);


}


Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime, bool faceRight, float switchTime)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.top = currentImage.y * uvRect.height;
	if (faceRight)
	{
		uvRect.left = currentImage.x*uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1)*abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}
