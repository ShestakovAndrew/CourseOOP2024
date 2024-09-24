#include <iostream>
class Point
{
	int x;
	int y;
public:
	//Point() = default;
	Point(int pX, int pY) : x{ pX }, y{ pY } {}
	Point& setX(int pX) { x = pX; return *this; }
	Point& setY(int pY) { y = pY; return *this; }
	void showPoint() const
	{
		std::cout << '(' << x << ',' << y << ')';
	}
};
int main()
{
	Point p0;
	Point p1{ 28,29 };
	p0.setX(10).setY(20);
	std::cout << "p0: ";
	p0.showPoint();
	std::cout << '\n';
	std::cout << "p1: ";
	p1.showPoint();
	std::cout << '\n';
	return 0;
}