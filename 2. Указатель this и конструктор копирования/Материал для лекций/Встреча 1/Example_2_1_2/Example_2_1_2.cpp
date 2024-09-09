#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point() { x = 0; y = 0; } // конструктор по умолчанию
    Point(int pX, int pY) { x = pX; y = pY; } // конструктор с параметрами
};

int main()
{
    Point p1; // используется конструктор по умолчанию
    Point p2{ 42,33 }; // используется конструктор с параметрами
    return 0;
}