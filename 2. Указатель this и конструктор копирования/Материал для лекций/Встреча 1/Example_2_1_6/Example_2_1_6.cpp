#include <iostream>

class Point
{
    int x{ -100 };
    int y{ -100 };
public:
    // конструктор по умолчанию
    Point() : x{ 0 }, y{ 0 }
    {
        std::cout << "Point Default constructor\n";
    }
    // конструктор с параметрами
    Point(int pX, int pY) : x{ pX }, y{ pY }
    {
        std::cout << "Point Parametrized constructor\n";
    }
    int getX() { return x; }
    int getY() { return y; }
};

int main()
{
    // поля x и y инициализируются конструктором по умолчанию в 0,0 соответственно
    // инициализаторы -100,-100 игнорируются!
    Point point;
    std::cout << "point.x = " << point.getX() << '\n';
    std::cout << "point.y = " << point.getY() << '\n';

    // поля x и y инициализируются конструктором с параметрами в 42,33 соответственно
    // инициализаторы -100,-100 игнорируются!
    Point point1{ 42,33 };
    std::cout << "point1.x = " << point1.getX() << '\n';
    std::cout << "point1.y = " << point1.getY() << '\n';
    return 0;
}