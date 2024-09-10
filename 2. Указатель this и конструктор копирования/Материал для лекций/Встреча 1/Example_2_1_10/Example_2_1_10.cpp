#include <iostream>

class Demo
{
public:
	int personal;
	static int common;
};

int Demo::common{ 0 };

int main()
{
	// создаем экземпляр и инициализируем персональное поле personal для d1
	Demo d1{ 1 };
	// создаем экземпляр и инициализируем персональное поле personal для d2
	Demo d2{ 2 };

	// присваиваем значение общему полю common
	d1.common = 42;
	// проверяем значение общего поля в d2
	std::cout << "d2.common = " << d2.common << '\n'; // 42 на экране
	return 0;
}