#include "Game.h"
#include <fstream>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdio>

Game::Game()
{

	// Подгружаем шрифт для отрисовки элементов
	Init();
}
sf::Sprite loadSprite(std::string filename)
{
	sf::Texture::bind(NULL);
	sf::Texture texture;
	texture.loadFromFile(filename);
	sf::Texture::bind(&texture);
	return sf::Sprite(texture);
}
void Game::Init()
{
	sprite = loadSprite("file.png");
}

bool Game::Check()
{
	// Проверка собранности головоломки
	return true;
}
int level = 0;
sf::Vector2f PlayerPosition;
sf::Vector2f ballPosition;
sf::Vector2f ball2Position;
sf::Vector2f ball3Position;
sf::Vector2f ball4Position;
sf::Vector2f ball5Position;
sf::Vector2f ball6Position;
sf::Vector2f ball7Position;
void Game::Move(Input direction)
{
	if (direction == Input::Left)
	{
		PlayerPosition.x -= 3;
	}if (direction == Input::Right)
	{
		PlayerPosition.x += 3;
	}if (direction == Input::Up)
	{
		PlayerPosition.y -= 3;
	}if (direction == Input::Down)
	{
		PlayerPosition.y += 3;
	}if (direction == Input::Ana)
	{
		level -= 1;
	}if (direction == Input::Kata)
	{
		level += 1;
	}
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (level == 0)
	{


		states.transform.translate(sf::Vector2f(0, 0));

		sf::Sprite sprite2;
		sf::Texture texture2;
		texture2.loadFromFile("Assets/Room1.png", sf::IntRect(0, 0, 420, 310));
		sf::Texture::bind(&texture2);
		sprite2.setTexture(texture2);
		sprite2.setScale(sf::Vector2f(2, 2));
		// Рисуем рамку игрового поля

		target.draw(sprite2, states);

		sf::Sprite sprite;
		sf::Texture texture;
		texture.loadFromFile("Assets/PBody.png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture);
		sprite.setTexture(texture);
		sprite.setOrigin(sf::Vector2f(-200 - PlayerPosition.x, -200 - PlayerPosition.y));
		target.draw(sprite, states);

	}
	if (level == 1)
	{


		states.transform.translate(sf::Vector2f(0, 0));

		sf::Sprite sprite2;
		sf::Texture texture2;
		texture2.loadFromFile("Assets/Room2.png", sf::IntRect(0, 0, 420, 310));
		sf::Texture::bind(&texture2);
		sprite2.setTexture(texture2);
		sprite2.setScale(sf::Vector2f(2, 2));
		// Рисуем рамку игрового поля

		target.draw(sprite2, states);

		sf::Sprite sprite;
		sf::Texture texture;
		texture.loadFromFile("Assets/PBody.png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture);
		sprite.setTexture(texture);
		sprite.setOrigin(sf::Vector2f(-200 - PlayerPosition.x, -200 - PlayerPosition.y));
		target.draw(sprite, states);

	}
	if (level == 2)
	{


		states.transform.translate(sf::Vector2f(0, 0));

		sf::Sprite sprite2;
		sf::Texture texture2;
		texture2.loadFromFile("Assets/Room3.png", sf::IntRect(0, 0, 420, 310));
		sf::Texture::bind(&texture2);
		sprite2.setTexture(texture2);
		sprite2.setScale(sf::Vector2f(2, 2));
		// Рисуем рамку игрового поля

		target.draw(sprite2, states);

		sf::Sprite sprite;
		sf::Texture texture;
		texture.loadFromFile("Assets/PBody.png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture);
		sprite.setTexture(texture);
		sprite.setOrigin(sf::Vector2f(-200 - PlayerPosition.x, -200 - PlayerPosition.y));
		target.draw(sprite, states);

		sf::Sprite sprite4;
		sf::Texture texture4;
		texture4.loadFromFile("Assets/Ball.png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture4);
		sprite4.setTexture(texture4);
		if ((PlayerPosition.x - 200) / 2 > ballPosition.x)
		{
			ballPosition.x += 0.2f;
		}if ((PlayerPosition.x - 200) / 2 < ballPosition.x)
		{
			ballPosition.x -= 0.2f;
		}if ((PlayerPosition.y - 200) / 2 > ballPosition.y)
		{
			ballPosition.y += 0.2f;
		}if ((PlayerPosition.y - 200) / 2 < ballPosition.y)
		{
			ballPosition.y -= 0.2f;
		}
		sprite4.setOrigin(sf::Vector2f(-200 - ballPosition.x, -200 - ballPosition.y));
		sprite4.setScale(sf::Vector2f(2, 2));
		target.draw(sprite4, states);

	}
	if (level == 3)
	{


		states.transform.translate(sf::Vector2f(0, 0));

		sf::Sprite sprite2;
		sf::Texture texture2;
		texture2.loadFromFile("Assets/Room4.png", sf::IntRect(0, 0, 420, 310));
		sf::Texture::bind(&texture2);
		sprite2.setTexture(texture2);
		sprite2.setScale(sf::Vector2f(2, 2));
		// Рисуем рамку игрового поля

		target.draw(sprite2, states);

		sf::Sprite sprite;
		sf::Texture texture;
		texture.loadFromFile("Assets/PBody.png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture);
		sprite.setTexture(texture);
		sprite.setOrigin(sf::Vector2f(-200 - PlayerPosition.x, -200 - PlayerPosition.y));
		target.draw(sprite, states);



	}

	if (level > 3)
	{

		states.transform.translate(sf::Vector2f(0, 0));

		sf::Sprite sprite2;
		sf::Texture texture2;
		texture2.loadFromFile("Assets/Room" + std::to_string(level + 1) + ".png", sf::IntRect(0, 0, 420, 310));
		sf::Texture::bind(&texture2);
		sprite2.setTexture(texture2);
		sprite2.setScale(sf::Vector2f(2, 2));
		// Рисуем рамку игрового поля
		

		target.draw(sprite2, states);

		sf::Sprite sprite;
		sf::Texture texture;
		texture.loadFromFile("Assets/PBody.png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture);
		sprite.setTexture(texture);
		sprite.setOrigin(sf::Vector2f(-200 - PlayerPosition.x, -200 - PlayerPosition.y));
		target.draw(sprite, states);

		sf::Sprite sprite4;
		sf::Texture texture4;
		texture4.loadFromFile("Assets/Ball" + std::to_string(level + 1) + ".png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture4);
		sprite4.setTexture(texture4);
		
			if ((PlayerPosition.x - 200) / 2 > ballPosition.x)
			{
				ballPosition.x += 0.2f;
			}if ((PlayerPosition.x - 200) / 2 < ballPosition.x)
			{
				ballPosition.x -= 0.2f;
			}if ((PlayerPosition.y - 200) / 2 > ballPosition.y)
			{
				ballPosition.y += 0.2f;
			}if ((PlayerPosition.y - 200) / 2 < ballPosition.y)
			{
				ballPosition.y -= 0.2f;
			}
		sprite4.setOrigin(sf::Vector2f(-200 - ballPosition.x, -200 - ballPosition.y));
		sprite4.setScale(sf::Vector2f(2, 2));
		target.draw(sprite4, states);
		sf::Sprite sprite5;
		sf::Texture texture5;
		texture5.loadFromFile("Assets/Balla" + std::to_string(level + 1) + ".png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture5);
		sprite5.setTexture(texture5);
		if ((PlayerPosition.x - 200) / 2 > ball2Position.x)
		{
			ball2Position.x += 0.25f;
		}if ((PlayerPosition.x - 200) / 2 < ball2Position.x)
		{
			ball2Position.x -= 0.25f;
		}if ((PlayerPosition.y - 200) / 2 > ball2Position.y)
		{
			ball2Position.y += 0.25f;
		}if ((PlayerPosition.y - 200) / 2 < ball2Position.y)
		{
			ball2Position.y -= 0.25f;
		}
		sprite5.setOrigin(sf::Vector2f(-240 - ball2Position.x, -240 - ball2Position.y));
		sprite5.setScale(sf::Vector2f(2, 2));
		target.draw(sprite5, states);

		sf::Sprite sprite6;
		sf::Texture texture6;
		texture6.loadFromFile("Assets/Ballb" + std::to_string(level + 1) + ".png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture6);
		sprite6.setTexture(texture6);
		if ((PlayerPosition.x - 200) / 2 > ball3Position.x)
		{
			ball3Position.x += 0.3f;
		}if ((PlayerPosition.x - 200) / 2 < ball3Position.x)
		{
			ball3Position.x -= 0.3f;
		}if ((PlayerPosition.y - 200) / 2 > ball3Position.y)
		{
			ball3Position.y += 0.3f;
		}if ((PlayerPosition.y - 200) / 2 < ball3Position.y)
		{
			ball3Position.y -= 0.3f;
		}
		sprite6.setOrigin(sf::Vector2f(-240 - ball3Position.x, -200 - ball3Position.y));
		sprite6.setScale(sf::Vector2f(2, 2));
		target.draw(sprite6, states);
		sf::Sprite sprite7;
		sf::Texture texture7;
		texture7.loadFromFile("Assets/Ballc" + std::to_string(level + 1) + ".png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture7);
		sprite7.setTexture(texture7);
		if ((PlayerPosition.x - 200) / 2 > ball4Position.x)
		{
			ball4Position.x += 0.16f;
		}
		if ((PlayerPosition.x - 200) / 2 < ball4Position.x)
		{
			ball4Position.x -= 0.16f;
		}
		if ((PlayerPosition.y - 200) / 2 > ball4Position.y)
		{
			ball4Position.y += 0.16f;
		}
		if ((PlayerPosition.y - 200) / 2 < ball4Position.y)
		{
			ball4Position.y -= 0.16f;
		}
		sprite7.setOrigin(sf::Vector2f(-200 - ball4Position.x, -240 - ball4Position.y));
		sprite7.setScale(sf::Vector2f(2, 2));
		target.draw(sprite7, states);
		sf::Sprite sprite8;
		sf::Texture texture8;
		texture8.loadFromFile("Assets/Balld" + std::to_string(level + 1) + ".png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture8);
		sprite8.setTexture(texture8);
		if ((PlayerPosition.x - 200) / 2 > ball5Position.x)
		{
			ball5Position.x += 0.4f;
		}if ((PlayerPosition.x - 200) / 2 < ball5Position.x)
		{
			ball5Position.x -= 0.4f;
		}if ((PlayerPosition.y - 200) / 2 > ball5Position.y)
		{
			ball5Position.y += 0.4f;
		}if ((PlayerPosition.y - 200) / 2 < ball5Position.y)
		{
			ball5Position.y -= 0.4f;
		}
		sprite8.setOrigin(sf::Vector2f(-160 - ball5Position.x, -160 - ball5Position.y));
		sprite8.setScale(sf::Vector2f(2, 2));
		target.draw(sprite8, states);

		sf::Sprite sprite9;
		sf::Texture texture9;
		texture9.loadFromFile("Assets/Ballg" + std::to_string(level + 1) + ".png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture9);
		sprite9.setTexture(texture9);
		if ((PlayerPosition.x - 200) / 2 > ball6Position.x)
		{
			ball6Position.x += 0.1f;
		}if ((PlayerPosition.x - 200) / 2 < ball6Position.x)
		{
			ball6Position.x -= 0.1f;
		}if ((PlayerPosition.y - 200) / 2 > ball6Position.y)
		{
			ball6Position.y += 0.1f;
		}if ((PlayerPosition.y - 200) / 2 < ball6Position.y)
		{
			ball6Position.y -= 0.1f;
		}
		sprite9.setOrigin(sf::Vector2f(-160 - ball6Position.x, -200 - ball6Position.y));
		sprite9.setScale(sf::Vector2f(2, 2));
		target.draw(sprite9, states);
		sf::Sprite sprite10;
		sf::Texture texture10;
		texture10.loadFromFile("Assets/Ballf" + std::to_string(level + 1) + ".png", sf::IntRect(0, 0, 40, 72));
		sf::Texture::bind(&texture10);
		sprite10.setTexture(texture10);
		if ((PlayerPosition.x - 200) / 2 > ball7Position.x)
		{
			ball6Position.x += 0.4f;
		}if ((PlayerPosition.x - 200) / 2 < ball7Position.x)
		{
			ball7Position.x -= 0.4f;
		}if ((PlayerPosition.y - 200) / 2 > ball7Position.y)
		{
			ball7Position.y += 0.4f;
		}if ((PlayerPosition.y - 200) / 2 < ball7Position.y)
		{
			ball7Position.y -= 0.4f;
		}
		sprite10.setOrigin(sf::Vector2f(-240 - ball7Position.x, -160 - ball7Position.y));
		sprite10.setScale(sf::Vector2f(2, 2));
		target.draw(sprite10, states);
	}

}










