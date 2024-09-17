#include <iostream>
#include <conio.h>
using namespace std;

class Point
{
private:
    double x;
    double y;
public:
    Point(double x, double y) : x{ x }, y{ y }
    {
    }

    Point() : Point{ 0, 0 }
    {
    }

    void display() const
    {
        cout << "(" << x << "," << y << ")";
    }

    void read()
    {
        cin >> x;
        cin.ignore(1); // пропуск запятой между x и y
        cin >> y;
    }

    static bool isEqual(const Point& point1, const Point& point2)
    {
        return point1.x == point2.x && point1.y == point2.y;
    }

    static bool isLarger(const Point& point1, const Point& point2)
    {
        return length(point1) > length(point2);
    }

    static Point add(const Point& point1, const Point& point2)
    {
        return Point(point1.x + point2.x, point1.y + point2.y);
    }

    static Point subtract(const Point& point1, const Point& point2)
    {
        return Point(point1.x - point2.x, point1.y - point2.y);
    }

    static Point multiplay(const Point& point, const double value)
    {
        return Point(point.x * value, point.y * value);
    }

    static Point multiplay(const double value, const Point& point)
    {
        return Point(point.x * value, point.y * value);
    }

    static Point divide(const Point& point, const double value)
    {
        if (value == 0)
        {
            return Point();
        }

        return Point(point.x / value, point.y / value);
    }

    static double distance(const Point& point1, const Point& point2)
    {
        return sqrt((point1.x - point2.x) * (point1.x - point2.x) +
            (point1.y - point2.y) * (point1.y - point2.y));
    }

    static double length(const Point& point)
    {
        return distance(point, Point());
    }

    static bool isLess(const Point& point1, const Point& point2)
    {
        return length(point1) < length(point2);
    }
};

int main()
{
    Point point1(1, 1);
    Point point2;
    Point point3(1, 1);

    if (Point::isEqual(point1, point3))
    {
        cout << "point1 and point3 are equal" << endl;
    }

    cout << "p1: ";
    point1.display();
    cout << endl;

    cout << "Enter point p2 in format x,y (e.g. 12,10) : ";
    point2.read();

    cout << "p2: ";
    point2.display();
    cout << endl;

    cout << "p2 + p1 = ";
    Point::add(point2, point1).display();
    cout << endl;

    cout << "Distance between ";
    point1.display();
    cout << " and ";
    point2.display();
    cout << " is ";
    cout << Point::distance(point1, point2);
    cout << endl;

    _getch();
    return 0;
}