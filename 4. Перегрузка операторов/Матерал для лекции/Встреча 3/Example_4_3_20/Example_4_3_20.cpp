#include <iostream>
enum Quadrants {
	ZeroPoint, First, Second, Third, Fourth,
	XPositive, XNegative, YPositive, YNegative
};
class Point
{
	int x;
	int y;
public:
	Point() = default;
	Point(int pX, int pY) : x{ pX }, y{ pY } {}
	Point& setX(int pX) { x = pX; return *this; }
	Point& setY(int pY) { y = pY; return *this; }
	int getX()const { return x; }
	int getY()const { return y; }
	void show() const
	{
		std::cout << '(' << x << ',' << y << ')';
	}
	friend double distance(const Point& p1, const Point& p2);
	friend int quadrant(const Point& p)
	{
		if ((!p.y and !p.x)) {
			return
				Quadrants::ZeroPoint;
		}
		if (!p.y) {
			return p.x > 0 ? Quadrants::
				XPositive : Quadrants::XNegative;
		}
		if (!p.x) {
			return p.y > 0 ? Quadrants::
				YPositive : Quadrants::YNegative;
		}
		if (p.y > 0)
		{
			return p.x > 0 ? Quadrants::First :
				Quadrants::Second;
		}
		return p.x > 0 ? Quadrants::Fourth : Quadrants::Third;
	}
	friend std::ostream& operator<<(std::ostream& out,
		const Point& point);
};
double distance(const Point& p1, const Point& p2)
{
	auto xLength{ p2.x - p1.x };
	auto yLength{ p2.y - p1.y };
	return sqrt(xLength * xLength + yLength * yLength);
}
void quadrantDecode(int quadrant)
{
	if (quadrant == Quadrants::ZeroPoint)
	{
		std::cout << "Zero point";
	}
	else if (quadrant == Quadrants::First)
	{
		std::cout << "First quadrant";
	}
	else if (quadrant == Quadrants::Second)
	{
		std::cout << "Second quadrant";
	}
	else if (quadrant == Quadrants::Third)
	{
		std::cout << "Third quadrant";
	}
	else if (quadrant == Quadrants::Fourth)
	{
		std::cout << "Fourth quadrant";
	}
	else if (quadrant == Quadrants::XPositive)
	{
		std::cout << "X axis positive";
	}
	else if (quadrant == Quadrants::XNegative)
	{
		std::cout << "X axis negative";
	}
	else if (quadrant == Quadrants::YPositive)
	{
		std::cout << "Y axis positive";
	}
	else if (quadrant == Quadrants::YNegative)
	{
		std::cout << "Y axis negative";
	}
}
std::ostream& operator<<(std::ostream& out,
	const Point& point)
{
	out << '(' << point.x << ',' << point.y << ')';
	return out;
}
int main()
{
	Point p1{ 5,5 };
	Point p2{ 10,10 };
	std::cout << "Distance between p1 " << p1
		<< " and p2 " << p2 << " is: "
		<< distance(p1, p2) << '\n';
	const int testCases{ 9 };
	Point points[testCases]{
	{0,0},
	{1,1},
	{-1,1},
	{-1,-1},
	{1,-1},
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
	};
	for (int i{ 0 }; i < testCases; ++i)
	{
		std::cout << points[i] << ' ';
		quadrantDecode(quadrant(points[i]));
		std::cout << '\n';
	}
	return 0;
}