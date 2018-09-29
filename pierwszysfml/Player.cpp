#include "Player.h"
#include<iostream>


Player::Player(sf::Texture* Texture, sf::Vector2u imageCount, float speed, float switchTime, float jumpHeight) : 
	animation(Texture, imageCount)
{
	switchTime = 0.5;
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(Texture);
}


Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	if (body.getPosition().y > 10000.0f)
	{
		body.setPosition(206.0f, 206.0f);
	}
	if (velocity.x > 1.0f || velocity.x < -1.0f)
	{
			velocity.x *= 0.5;
	}
	else
		velocity.x = 0.0f;
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			velocity.x -= speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			velocity.x += speed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
		{
			canJump = false;
			velocity.y = -sqrt(2.0f*98.10f*(jumpHeight/2)*1.5);
			//square root (2.0f*gravity * jumpHeight)
		}
		
		velocity.y += 98.1f*deltaTime;
		
		if (velocity.x == 0.0f)
		{
			switchTime = 0.5;
			row = 0;
		}
		else {
			row = 1;
			switchTime = 0.1f;
			if (velocity.x > 0)
				faceRight = true;
			else
				faceRight = false;
		}
		body.move(velocity.x, velocity.y);
		animation.Update(row, deltaTime, faceRight, switchTime);		
		body.setTextureRect(animation.uvRect);
			
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision under
		velocity.y = 0.0f;
			canJump = true;
	}
	else if(direction.y>0.0f)
	{ 
		velocity.y = 0.0f;
	}
}
