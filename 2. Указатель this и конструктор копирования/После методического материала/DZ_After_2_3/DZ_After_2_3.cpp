#include "String.h"

int main()
{
	String str1("Hello, world!");
	str1.Display();

	String str2(10);
	str2.SetString("Hi!");
	str2.Display();

	String str3 = str1;
	str3.Display();

	str3.SetString("New string!");
	str3.Display();

	return 0;
}