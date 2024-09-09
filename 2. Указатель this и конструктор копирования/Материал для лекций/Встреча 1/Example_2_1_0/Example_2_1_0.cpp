#include <iostream>
int main()
{
	int numbers[2];
	numbers[0] += 2;
	std::cout << numbers[0] << '\n';
	
	int number = 0; // копирующая инициализация
	int value(42); // прямая инициализация
	int size{ 33 }; // унифицированная инициализация
	
	return 0;
}