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

    // ++функции логических операций
    static bool isEqual(const Point& point1, const Point& point2)
    {
        return point1.x == point2.x && point1.y == point2.y;
    }

    static bool isNotEqual(const Point& point1, const Point& point2)
    {
        return !(point1.x == point2.x && point1.y == point2.y);
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

    static bool isGreaterThan(const Point& point1, const Point& point2)
    {
        return length(point1) > length(point2);
    }
    // --функции логических операций

    // ++функции арифметических операций
    static const Point add(const Point& point1, const Point& point2)
    {
        return Point(point1.x + point2.x, point1.y + point2.y);
    }

    static const Point subtract(const Point& point1, const Point& point2)
    {
        return Point(point1.x - point2.x, point1.y - point2.y);
    }

    static const Point mult(const Point& point, double value)
    {
        return Point(point.x * value, point.y * value);
    }

    static const Point divide(const Point& point, double value)
    {
        return Point(point.x / value, point.y / value);
    }
    // --функции арифметических операций

    // ++операнды арифметических операций
    friend Point operator+(const Point& point1, const Point& point2)
    {
        return add(point1, point2);
    }

    friend const Point operator-(const Point& point1, const Point& point2)
    {
        return subtract(point1, point2);
    }

    friend const Point operator*(const Point& point, double value)
    {
        return mult(point, value);
    }

    friend const Point operator*(double value, const Point& point)
    {
        return mult(point, value);
    }

    friend const Point operator/(const Point& point, double value)
    {
        return divide(point, value);
    }
    // --операнды арифметических операций

    // ++унарный минус
    const Point operator-()
    {
        return Point(-x, -y);
    }
    // --унарный минус

    // ++перегрузка операторов инкремента и декремента
    // префиксная форма
    Point& operator++()
    {
        ++x; ++y; return *this;
    }

    Point& operator--()
    {
        --x; --y; return *this;
    }

    // постфиксная форма
    const Point operator++(int)
    {
        Point point{ x, y }; // создается временный объект
                             // с текущими значениями
        ++(*this);           // выполняется префиксная перегрузка
        return point;        // возвращается временный объект
                             // с текущими значениями
    }

    const Point operator--(int)
    {
        Point point{ x, y };
        --(*this);
        return point;
    }
    // --перегрузка операторов инкремента и декремента

    // ++логические операторы
    friend bool operator==(const Point& point1, const Point& point2)
    {
        return point1.x == point2.x && point1.y == point2.y;
    }

    friend bool operator!=(const Point& point1, const Point& point2)
    {
        return !(point1.x == point2.x && point1.y == point2.y);
    }

    friend bool operator>(const Point& point1, const Point& point2)
    {
        return length(point1) > length(point2);;
    }
    // --логические операторы

    // ++операторы ввода-вывода
    friend ostream& operator<<(ostream& output, const Point& point)
    {
        output << "(" << point.x << "," << point.y << ")";
        return output;
    }

    friend istream& operator>>(istream& input, Point& point)
    {
        input >> point.x;
        input.ignore(1);
        input >> point.y;
        return input;
    }
    // --операторы ввода-вывода

    double operator!()
    {
        return distance(*this, Point());
    }
};

int main()
{
    int x = 1;
    cout << ++(++x) << endl;

    Point point1(1, 1);
    cout << ++(++point1) << endl;

    const Point point2(2, 2);
    Point point3(3, 3);

    cout << "point1: " << point1 << endl;
    cout << "point2 (const): " << point2 << endl;
    cout << "point3: " << point3 << endl;
    cout << endl;

    cout << "point2 == point1: " << (point2 == point1) << endl;

    cout << "point2 > point1: " << (point2 > point1) << endl;

    cout << "point1 + point2 + point3: " << (point1 + point2 + point3) << endl;

    cout << "point2 - point1: " << (point2 - point1) << endl;

    cout << "point1 * 5: " << (point1 * 5) << endl;

    cout << "3 * point2: " << (3 * point2) << endl;

    cout << "-point3 / 5: " << (-point3 / 5) << endl;

    cout << "++point1: " << ++point1 << endl;

    cout << "point3++: " << point3++ << endl;

    cout << "point3: " << point3 << endl;

    point1 = point3;

    cout << "point1: " << point1 << endl;

    _getch();
    return 0;
}
