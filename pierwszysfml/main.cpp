#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
#include"Platform.h"
#include"Monety.h"
#include<vector>
#include "main.h"
#include"Points.h"
static const float VIEW_HEIGHT = 512.f;
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT*aspectRatio, VIEW_HEIGHT);
}
int main()
{
	sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML", sf::Style::Close | sf::Style::Resize);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("postac.png");
	sf::Font font;
	font.loadFromFile("font.ttf");
	int i_Points = 0;
	Player player(&playerTexture, sf::Vector2u(3, 9), 10.0f, 0.5f, 10.0);
	Points counter(font, i_Points);
	std::vector<Platform> platforms;
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	std::vector<Monety> v_monety;
	v_monety.push_back(Monety(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(6.0f,206.0f),1));
	v_monety.push_back(Monety(sf::Vector2f(30.0f, 30.0f), sf::Vector2f(-60.0f, 206.0f),2));
	float deltaTime = 0.0f;
	sf::Clock clock;
	window.setFramerateLimit(30);
	

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
		{
			deltaTime = 1.0f / 20.0f;
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}
		std::cout << player.GetPosition().x << "   "; std::cout << player.GetPosition().y<<std::endl;
		player.Update(deltaTime);
		sf::Vector2f direction;
		
		for (Platform& platform : platforms) //for(int i=0;i<platforms.size();i++){Platform& platform=platforms[i]}
		{
			if(platform.GetCollider().checkCollision(player.GetCollider(),direction, 1.0f))
				player.OnCollision(direction);
		}
		for (int i = 0; i < v_monety.size(); i++)
		{
			Monety& moneta = v_monety[i];
			if (moneta.GetCollider().CheckCollision2(player.GetCollider()))
			{
			i_Points = i_Points + moneta.GetPoints();
			}
			moneta.GetCollider().CheckCollision2(player.GetCollider());
		}

		
		view.setCenter(player.GetPosition());
		window.clear(sf::Color(8 , 84 , 24));
		window.setView(view);
		player.Draw(window);
		counter.Points_Draw(window);
		for (Platform& platform : platforms) //for(int i=0;i<platforms.size(),i++){Platform& platform=platforms[i]}
		{
			platform.Draw(window);
		}
		for (Monety& moneta : v_monety)
		{
			moneta.Draw(window);
		}
		
	window.display();
	}

	return 0;
}