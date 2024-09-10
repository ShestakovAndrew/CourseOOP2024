#include <iostream>
#include <ctime> // для функции time

class NumberStorage
{
	int* storage;
	uint32_t elementsCount;
	static uint32_t usedMemory;
public:
	NumberStorage(uint32_t elementsCountP)
		:storage{ new int[elementsCountP] }, elementsCount{ elementsCountP }
	{
		uint32_t used{ elementsCount * sizeof(int) };
		usedMemory += used;
		std::cout << "NumberStorage: additional " << used
			<< " bytes used. Total: " << usedMemory << '\n';
		for (uint32_t i{ 0 }; i < elementsCount; ++i)
		{
			storage[i] = rand() % 10;
		}
	}
	~NumberStorage()
	{
		uint32_t freed{ elementsCount * sizeof(int) };
		delete[] storage;
		usedMemory -= freed;
		std::cout << "NumberStorage: freed " << freed
			<< " bytes. Total used: " << usedMemory << '\n';

	}
	void print()
	{
		for (uint32_t i{ 0 }; i < elementsCount; ++i)
		{
			std::cout << storage[i] << ' ';
		}
		std::cout << '\n';
	}

	static uint32_t getUsedMemory()
	{
		return usedMemory;
	}
};

uint32_t NumberStorage::usedMemory{ 0 };

int main()
{
	// Задаем номер последовательности случайных чисел исходя из текущего времени.
	srand(time(nullptr));

	std::cout << "Total memory used: " << NumberStorage::getUsedMemory() << '\n';

	const int poolSize{ 3 };
	NumberStorage pool[poolSize]{ rand() % 101,rand() % 101,rand() % 101 };

	std::cout << "Total memory used: " << NumberStorage::getUsedMemory() << '\n';
	return 0;
}