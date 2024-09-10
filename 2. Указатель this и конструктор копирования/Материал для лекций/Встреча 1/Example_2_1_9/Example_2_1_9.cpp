#include <iostream>

// упрощенный класс Point с public полями
class Point
{
public:
	int x;
	int y;
};

int main()
{
	// Выделяется и инициализируется память под "персональный" x и y для pointOne
	Point pointOne{ 1,1 };
	// Выделяется инициализируется память под "персональный" x и y для pointTwo
	Point pointTwo{ 2,2 };

	// модифицируем PointOne поля x и y 
	pointOne.x = 4;
	pointOne.y = 6;

	// проверяем, что значения x и y для pointOne изменились
	std::cout << "pointOne: x = " << pointOne.x << " y = " << pointOne.y << '\n';
	// проверяем, что значения x и y для pointTwo не затронуты
	std::cout << "pointTwo: x = " << pointTwo.x << " y = " << pointTwo.y << '\n';
	return 0;
}