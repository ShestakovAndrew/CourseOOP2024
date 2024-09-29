#include <iostream>
class Point3D;
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
	explicit operator bool() const { return x and y; }
	explicit operator Point3D() const;
};
class Point3D
{
	int x;
	int y;
	int z;
public:
	Point3D() = default;
	Point3D(int pX, int pY, int pZ) : x{ pX }, y{ pY },
		z{ pZ } {}
	Point3D& setX(int pX) { x = pX; return *this; }
	Point3D& setY(int pY) { y = pY; return *this; }
	Point3D& setZ(int pZ) { z = pZ; return *this; }
	void showPoint() const
	{
		std::cout << '(' << x << ',' << y << ',' << z << ')';
	}
	explicit operator bool() const { return x and y and z; }
	explicit operator Point() const;
};
Point::operator Point3D() const { return { x,y,0 }; }
Point3D::operator Point() const { return { x, y }; }
int main()
{
	Point point{ 26,7 };
	Point pointConv{};
	Point3D point3D{ 24, 7, 76 };
	Point3D point3DConv{};
	pointConv = (Point)point3D;
	point3DConv = (Point3D)point;
	std::cout << "Point converted from Point3D\n";
	pointConv.showPoint();
	std::cout << "\nPoint3D converted from Point\n";
	point3DConv.showPoint();
	std::cout << '\n';
	return 0;
}