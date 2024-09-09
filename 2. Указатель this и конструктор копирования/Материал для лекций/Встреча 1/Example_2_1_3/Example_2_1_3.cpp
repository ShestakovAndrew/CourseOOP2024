#include <iostream>

class Point
{
    // поля определены с помощью public специально!
public:
    int x;
    int y;
    // 2. 5. конструктор по умолчанию
    Point() { x = 0; y = 0; std::cout << "Point Default constructor\n"; }
    // конструктор с параметрами
    Point(int pX, int pY)
    {
        x = pX;
        y = pY;
        std::cout << "Point Parametrized constructor\n";
    }
};

class Rectangle
{
    Point leftUpperCorner;
    int width;
    int height;
public:
    // 3. конструктор по умолчанию
    Rectangle()
    {
        leftUpperCorner.x = 10;
        leftUpperCorner.y = 10;
        width = 0;
        height = 0;
        std::cout << "Rectangle Default constructor\n";
    }

    // 6 . конструктор с параметрами
    Rectangle(int x, int y, int widthP, int heightP)
    {
        leftUpperCorner.x = x;
        leftUpperCorner.y = y;
        width = widthP;
        height = heightP;
        std::cout << "Rectangle Parametrized constructor\n";
    }
};

int main()
{
    // 1. используется конструктор по - умолчанию
    Rectangle rect;
    // 4. используется конструктор с параметрами
    Rectangle rect1{ 42, 33, /*вершина*/ 10, /*ширина*/ 5 /*высота*/ };
    return 0;
}