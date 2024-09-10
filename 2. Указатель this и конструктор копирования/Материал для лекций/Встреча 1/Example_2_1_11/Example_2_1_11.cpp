#include <iostream>

class Demo
{
public:
	int personal;
	static int common;
};

int Demo::common{ 42 };

int main()
{
	std::cout << "Demo::common = " << Demo::common << '\n';

	Demo demo;
	std::cout << "Demo::common = " << demo.common << '\n';
	return 0;
}