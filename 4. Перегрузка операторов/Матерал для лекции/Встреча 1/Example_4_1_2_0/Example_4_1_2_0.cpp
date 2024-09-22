#include <iostream>
#include <conio.h>
using namespace std;

class Point
{
public:
    double x;
    double y;

    Point(double x, double y) : x{ x }, y{ y }
    {
    }

    void display() const
    {
        cout << "(" << x << "," << y << ")";
    }

    //Через дружественные функции
    friend Point operator+(const Point& point1, const Point& point2)
    {
        return Point(point1.x + point2.x, point1.y + point2.y);
    }

    friend Point operator-(const Point& point)
    {
        return Point(-point.x, -point.y);
    }

    //Через методы класса
    Point operator+(const Point& point2)
    {
        return Point(this->x + point2.x, this->y + point2.y);
    }

    Point operator-()
    {
        return Point(-this->x, -this->y);
    }
};

//Через обычные функции
Point operator+(const Point& point1, const Point& point2)
{
    return Point(point1.x + point2.x, point1.y + point2.y);
}

Point operator-(const Point& point)
{
    return Point(-point.x, -point.y);
}

int main()
{
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3 = p1 + p2;
    p2.display();    // (3, 3)
    (-p1).display();    // (-1, -1)

    _getch();
    return 0;
}