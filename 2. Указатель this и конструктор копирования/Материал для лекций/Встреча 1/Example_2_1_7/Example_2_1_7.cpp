#include <iostream>

class Person
{
	char* name;
	uint16_t age;
	/* uint16_t - unsigned integer 16 bit type рекомендуемая современным стандартом
	нотация целочисленных типов, занимающая предсказуемое количество байт на любой
	архитектуре. Аналог unsigned short */
	uint32_t socialId;
	// Аналогично предыдущему unsigned integer 32 bit type – аналог unsigned int
public:
	Person() : name{ nullptr }, age{ 0 }, socialId{ 0 }
	{
		std::cout << "Person constructed\n";
	}

	Person(const char* nameP)
		: name{ new char[strlen(nameP) + 1] }, age{ 0 }, socialId{ 0 }
	{
		strcpy_s(name, strlen(nameP) + 1, nameP);
		std::cout << "Person constructed\n";
	}

	Person(const char* nameP, uint16_t ageP)
		: name{ new char[strlen(nameP) + 1] }, age{ ageP }, socialId{ 0 }
	{
		strcpy_s(name, strlen(nameP) + 1, nameP);
		std::cout << "Person constructed\n";
	}

	Person(const char* nameP, uint16_t ageP, uint32_t socialIdP)
		: name{ new char[strlen(nameP) + 1] }, age{ ageP }, socialId{ socialIdP }
	{
		strcpy_s(name, strlen(nameP) + 1, nameP);
		std::cout << "Person constructed\n";
	}

	~Person()
	{
		delete[] name;
		std::cout << "Person destructed\n";
	}
};