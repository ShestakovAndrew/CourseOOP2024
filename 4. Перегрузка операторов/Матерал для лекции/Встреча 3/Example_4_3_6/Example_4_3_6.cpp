#include <iostream>

class Dyn2DArrLinear
{
	int sizeY;
	int sizeX;
public:
	int** data;

	Dyn2DArrLinear(int sizeYP, int sizeXP)
		: sizeY{ sizeYP }, sizeX{ sizeXP },
		data{ new int* [sizeYP] }
	{
		/*
		* выделяем блок памяти для хранения всех элементов
		* двумерного динамического массива.
		*/
		int* dataElements{ new int[sizeY * sizeX] };

		for (int y{ 0 }; y < sizeY; ++y)
		{
			// "нарезаем" блок построчно
			data[y] = dataElements + y * sizeX;
		}
	}

	void print() const
	{
		for (int y{ 0 }; y < sizeY; ++y)
		{
			for (int x{ 0 }; x < sizeX; ++x)
			{
				std::cout << data[y][x] << '\t';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	~Dyn2DArrLinear()
	{
		/*
		* адрес начала большого блока dataElements
		* в конструкторе совпадает с адресом первой
		* строки нашего двумерного динамического массива.
		* Сперва освобождаем память из-под элементов
		* массива, затем — память контейнера строк.
		*/
		delete[] data[0];
		delete[] data;
	}
};
int main()
{
	int rows{ 3 };
	int columns{ 3 };
	int counter{ 1 };

	Dyn2DArrLinear arr2d{ rows, columns };

	for (int y{ 0 }; y < rows; ++y)
	{
		for (int x{ 0 }; x < columns; ++x)
		{
			arr2d.data[y][x] = counter++;
		}
	}

	arr2d.print();

	return 0;
}