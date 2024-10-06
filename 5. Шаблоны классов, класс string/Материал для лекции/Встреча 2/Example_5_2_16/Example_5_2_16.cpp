// les05_10

#include <conio.h>
#include "numbermatrix.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point(int x = 0, int y = 0) : x{ x }, y{ y }
	{}

	friend bool operator>(const Point& p1, const Point& p2)
	{
		double d1 = sqrt(p1.x * p1.x + p1.y * p1.y);
		double d2 = sqrt(p2.x * p2.x + p2.y * p2.y);
		return d1 - d2;
	}

	friend std::ostream& operator<<(std::ostream& output, const Point& p)
	{
		output << "(" << p.x << "," << p.y << ")";
		return output;
	}
};

void stopProgram(string message)
{
	cout << message << endl;
	cout << "Press any key to exit program" << endl;
	_getch();
	exit(1);
}

int main()
{
	cout << "Class Matrix" << endl << endl;

	Matrix<int> intMatrix(3);
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			intMatrix(j, i) = j * 10 + i;
		}
	}
	cout << "int Matrix:" << endl;
	cout << intMatrix << endl;

	Matrix<int> intMatrixA = intMatrix;
	cout << "Copy int Matrix:" << endl;
	cout << intMatrixA << endl;

	Matrix<string> strMatrix(2, 3);
	strMatrix(0, 0) = "string00";
	strMatrix(0, 1) = "string01";
	strMatrix(0, 2) = "string02";
	strMatrix(1, 0) = "string10";
	strMatrix(1, 1) = "string11";
	strMatrix(1, 2) = "string12";
	cout << "string Matrix:" << endl;
	cout << strMatrix << endl;

	Matrix<Point> pointMatrix(2, 3);
	pointMatrix(0, 0) = Point(0, 0);
	pointMatrix(0, 1) = Point(0, 1);
	pointMatrix(0, 2) = Point(0, 2);
	pointMatrix(1, 0) = Point(1, 0);
	pointMatrix(1, 1) = Point(1, 1);
	pointMatrix(1, 2) = Point(1, 2);
	cout << "point Matrix:" << endl;
	cout << pointMatrix << endl;

	NumberMatrix<double> numberMatrixA(2, 3);
	numberMatrixA.setRand();
	cout << "double Number MatrixA:" << endl;
	cout << numberMatrixA << endl;

	NumberMatrix<double> numberMatrixB(2, 3);
	numberMatrixB.setRand();
	cout << "double Number MatrixB:" << endl;
	cout << numberMatrixB << endl;

	NumberMatrix<double> numberMatrixC = numberMatrixA + numberMatrixB;
	cout << "MatrixC = MatrixA + MatrixB:" << endl;
	cout << numberMatrixC << endl;

	_getch();
	return 0;
}
