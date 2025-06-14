// main.cpp
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	// Создаем окно размером 600 на 600 и частотой обновления 60 кадров в секунду
	sf::RenderWindow window(sf::VideoMode(840, 620), "CppTale");
	window.setFramerateLimit(60);

	sf::Texture textu;
	textu.loadFromFile("file.png");

	// Текст с обозначением клавиш

	// Создаем объект игры
	Game game;
	game.setPosition(50.f, 50.f);

	sf::Event event;
	int move_counter = 0;	// Счетчик случайных ходов для перемешивания головоломки
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				// Получаем нажатую клавишу - выполняем соответствующее действиеif (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::Left) game.Move(Input::Left);
				if (event.key.code == sf::Keyboard::Right) game.Move(Input::Right);
				if (event.key.code == sf::Keyboard::Up) game.Move(Input::Up);
				if (event.key.code == sf::Keyboard::Down) game.Move(Input::Down); 
				if (event.key.code == sf::Keyboard::A) game.Move(Input::Left);
				if (event.key.code == sf::Keyboard::D) game.Move(Input::Right);
				if (event.key.code == sf::Keyboard::W) game.Move(Input::Up);
				if (event.key.code == sf::Keyboard::S) game.Move(Input::Down);
				if (event.key.code == sf::Keyboard::E) game.Move(Input::Kata);
				if (event.key.code == sf::Keyboard::Q) game.Move(Input::Ana);

				if (event.key.code == sf::Keyboard::Escape) window.close();
			}
		}

		// Если счетчик ходов больше нуля, продолжаем перемешивать головоломку

		// Выполняем необходимые действия по отрисовке
		window.clear();
		window.draw(game);
		window.display();
	}

	return 0;
}