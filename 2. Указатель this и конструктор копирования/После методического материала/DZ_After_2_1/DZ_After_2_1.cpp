#include <iostream>
#include <conio.h>

#include "Fraction.h"

int main()
{
	{
		Fraction fr1(3, 4);
		Fraction fr2(2, 3);
		Fraction frResult = fr1.Add(fr2);
		frResult.Print();// 17/12 - ОК
	}

	{
		Fraction fr1(3, 4);
		Fraction fr2(2, 3);
		Fraction frResult = fr1.Substract(fr2);
		frResult.Print();// 1/12
	}

	{
		Fraction fr1(3, 4);
		Fraction fr2(2, 3);
		Fraction frResult = fr1.Multiply(fr2);
		frResult.Print();// 1/2
	}

	{
		Fraction fr1(3, 4);
		Fraction fr2(2, 3);
		Fraction frResult = fr1.Add(2);
		frResult.Print(); // 11/4
	}

	{
		Fraction fr1(3, 4);
		Fraction fr2(2, 3);
		Fraction frResult = fr1.Substract(1);
		frResult.Print();// -1/4
	}

	{
		Fraction fr1(3, 4);
		Fraction fr2(2, 3);
		Fraction frResult = fr1.Multiply(2);
		frResult.Print();// 3/2
	}

	_getch();
	return 0;
}