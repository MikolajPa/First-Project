#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Collider.h"
class Player
{

public:
	Player(sf::Texture* Texture, sf::Vector2u imageCoun, float speed, float switchTime, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); };
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed, switchTime;
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

