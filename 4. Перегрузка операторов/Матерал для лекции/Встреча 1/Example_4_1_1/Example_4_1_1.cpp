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

    static Point add(const Point& point1, const Point& point2)
    {
        return Point(point1.x + point2.x, point1.y + point2.y);
    }

    static Point mult(const Point& point, double value)
    {
        return Point(point.x * value, point.y * value);
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

    static bool isLarger(const Point& point1, const Point& point2)
    {
        return length(point1) > length(point2);
    }

    //friend ostream& operator<< (ostream& output, const Point& point)
    //{
    //    output << "(" << point.x << "," << point.y << ")";
    //    return output;
    //}

    //friend istream& operator>> (istream& input, Point& point)
    //{
    //    input >> point.x;
    //    input.ignore(1);
    //    input >> point.y;
    //    return input;
    //}

    friend bool operator==(const Point& point1, const Point& point2)
    {
        return isEqual(point1, point2);
    }

    friend  Point operator+(const Point& point1, const Point& point2)
    {
        return add(point1, point2);
    }

    friend Point operator*(const Point& point, double value)
    {
        return mult(point, value);
    }

    friend Point operator*(double value, const Point& point)
    {
        return mult(point, value);
    }

    friend double operator%(const Point& point1, const Point& point2)
    {
        return distance(point1, point2);
    }

    double operator!()
    {
        return distance(*this, Point());
    }

    //Point operator+(const Point& point)
    //{
    //    return Point(this->x + point.x, this->y + point.y);
    //}
};

int main()
{
    Point point1(1, 1);
    Point point2;
    Point point3(1, 1);

    if (point1 == point3)
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

    point3 = point1 + point2;
    cout << "p1 + p2 = ";
    point3.display();
    cout << endl;

    cout << "Distance between ";
    point1.display();
    cout << " and ";
    point2.display();
    cout << " is ";
    cout << point1 % point2 << endl;

    cout << "Vector ";
    point1.display();
    cout << " length is ";
    cout << !point1 << endl;

    _getch();
    return 0;
}
