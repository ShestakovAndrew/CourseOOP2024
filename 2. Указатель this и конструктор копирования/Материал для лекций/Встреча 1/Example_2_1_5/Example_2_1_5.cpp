#include <iostream>

class Point
{
    int x;
    int y;
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
};

class Rectangle
{
    Point leftUpperCorner;
    int width;
    int height;
public:
    // конструктор по умолчанию
    Rectangle()
        : leftUpperCorner{ 10, 10 }, width{ 0 }, height{ 0 }
    {
        std::cout << "Rectangle Default constructor\n";
    }

    // конструктор с параметрами
    Rectangle(int x, int y, int widthP, int heightP)
        : leftUpperCorner{ x, y }, width{ widthP }, height{ heightP }
    {
        std::cout << "Rectangle Parametrized constructor\n";
    }
};

int main()
{
    // используется конструктор по умолчанию
    Rectangle rect;
    // используется конструктор с параметрами
    Rectangle rect1{ 42, 33, /*вершина*/ 10 /*ширина*/, 5 /*высота*/ };
    return 0;
}