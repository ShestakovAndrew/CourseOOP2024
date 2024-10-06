//les05_052

#include <iostream>
#include <conio.h>
#include "array.h"
using namespace std;

void stopProgram(string message)
{
	cout << message << endl;
	cout << "Press any key to exit program" << endl;
	_getch();
	exit(1);
}

struct Point
{
	int x;
	int y;
};

int main()
{
	cout << "Class Template Array (Points)" << endl << endl;

	Array<Point> pointArray;
	cout << "Point Array initialization:" << endl;
	pointArray.display();
	int size = pointArray.getSize();
	for (int i = size; i > 0; i--)
	{
		pointArray.setItem(size - i, Point{ i,i });
	}
	cout << endl << "Point Array after assignment:" << endl;
	pointArray.display();
	pointArray.sort();
	cout << endl << "Point Array after ordering:" << endl;
	pointArray.display();
	cout << endl;

	cout << endl << "Press any key to exit program" << endl;
	_getch();
	return 0;
}
