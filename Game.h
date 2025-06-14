#pragma once
#include <SFML/Graphics.hpp>

const int SIZE = 4;						// ������ �������� ���� � �������
const int ARRAY_SIZE = SIZE * SIZE;		// ������ �������
const int FIELD_SIZE = 500;				// ������ �������� ���� � ��������
const int CELL_SIZE = 120;				// ������ ������ � ��������

enum class Input { Left = 0, Right = 1, Up = 2, Down = 3 , Ana = 4, Kata = 5};

class Game : public sf::Drawable, public sf::Transformable
{
protected:
	int elements[ARRAY_SIZE];
	int empty_index;
	bool solved;
	sf::Font font;
	sf::Sprite sprite;
	sf::Texture textu;
public:
	Game();
	void Init();
	bool Check();
	void Move(Input input);
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};