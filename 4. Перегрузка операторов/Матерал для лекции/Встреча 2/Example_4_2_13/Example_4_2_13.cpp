#include <iostream>
class Point
{
	int x;
	int y;
public:
	Point() = default;
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
	p0.setX(28.02).setY(29.02);
	std::cout << "p0: ";
	p0.showPoint();
	std::cout << '\n';
	return 0;
}