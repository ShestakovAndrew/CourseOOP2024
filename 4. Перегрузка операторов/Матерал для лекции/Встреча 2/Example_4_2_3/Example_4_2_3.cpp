#include <iostream>

int main()
{
	int x{ 42 };
	int& refX{ x };
	const int& cRefX{ x };
	const int& cRefXX{ x + 24 };

	std::cout << x << '\n'
		<< refX << '\n'
		<< cRefX << '\n'
		<< cRefXX << '\n';
	return 0;
}