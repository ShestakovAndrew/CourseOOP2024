//les05_03

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

int main()
{
	cout << "Class Tempate Array" << endl << endl;

	Array<int> intArray;
	cout << "int Array initialization:" << endl;
	intArray.display();
	int size = intArray.getSize();
	for (int i = size; i > 0; i--)
	{
		intArray.setItem(size - i, i);
	}
	cout << endl << "int Array after assignment:" << endl;
	intArray.display();
	intArray.sort();
	cout << endl << "int Array after ordering:" << endl;
	intArray.display();
	cout << endl;

	Array<string> strArray;
	cout << "str Array initialization:" << endl;
	strArray.display();
	strArray.setItem(0, "two");
	strArray.setItem(1, "seven");
	strArray.setItem(2, "zero");
	strArray.setItem(3, "four");
	strArray.setItem(4, "one");
	cout << endl << "str Array after assignment:" << endl;
	strArray.display();
	strArray.sort();
	cout << endl << "str Array after ordering:" << endl;
	strArray.display();

	cout << endl << "Press any key to exit program" << endl;
	_getch();
	return 0;
}
